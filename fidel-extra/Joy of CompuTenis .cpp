#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;

#define SIMULACION false
#define PRECISION 2

#define ABS(x) ( (x)>0.0 ? (x) : -(x) )

#define K_LOW 1
#define K_HIGH 3
#define S_LOW 1
#define S_HIGH 10
#define J_LOW 1
#define J_HIGH 100
#define D_LOW 1
#define P_LOW 0
#define P_HIGH 100


#define MAXN 8
#define MAXK 4
#define MAXJ 128
#define MAXD 128
#define EPS 1E-9
typedef double tint;

bool gaussjordan(tint **A, tint **B, int N, int M) {
	int i, j, k, jmax;
	tint tmp;

	for (i=0; i<N; i++) {
		//Encontrar el maximo elemento de A en la columna i con fila >= i
		jmax = i;
		for (j=i+1; j<N; j++) {
			if (ABS(A[j][i]) > ABS(A[jmax][i])) jmax = j;
		}

		//Intercambiar las filas i y jmax
		for (j=0; j<N; j++) swap(A[i][j], A[jmax][j]);
		for (j=0; j<M; j++) swap(B[j][i], B[j][jmax]);

		//Controlar que la matriz sea invertible
		if (ABS(A[i][i]) < EPS) return false;

		//Normalizar la fila i
		tmp = A[i][i];
		for (j=0; j<N; j++) A[i][j] /= tmp;
		for (j=0; j<M; j++) B[j][i] /= tmp;

		//Eliminar los valores no nulos de la columna i
		for (j=0; j<N; j++) {
			if (i == j) continue;

			tmp = A[j][i];
			for (k=0; k<N; k++) A[j][k] -= A[i][k]*tmp;
			for (k=0; k<M; k++) B[k][j] -= B[k][i]*tmp;
		}
	}
	return true;
}

void simulate(tint **pnc, tint pl, int C) {
	int i, j;
	tint pr = 1.0 - pl;

	for (i=0; i<=C; i++) {
		for (j=0; j<=C; j++) {
			pnc[i][j] = 0.0;
		}
	}
	pnc[0][0] = 1.0;

	for (i=0; i<2*C; i++) {
		for (j=0; j<=i && j<C; j++) {
			if (i - j >= C) continue;

			pnc[i-j + 1][j] += pnc[i-j][j]*pl;
			pnc[i-j][j + 1] += pnc[i-j][j]*pr;
			pnc[i-j][j] = 0.0;
		}
	}
}

void calc_set_simulacion(tint pl, tint &PL, tint &EX, int J, int D) {
	int sd[4*MAXJ], sj[4*MAXJ], S, E, X, cl, cr, cur, next;
	bool ins[2][2][MAXJ];
	tint PR, p[2][2][MAXJ], pr=1.0-pl, curp;

	memset(p, 0.0, sizeof(p));
	p[0][0][0] = 1.0;

	memset(ins, false, sizeof(ins));
	ins[0][0][0] = true;
	sd[0] = sj[0] = 0; S = 0; E = 1;

	PL = PR = EX = 0.0; X = 0;
	while (1.0 - PL - PR > EPS) {
		if ((X-sd[S])%2 != 0) X++;

		cur = X&1; next = 1^cur;
		curp = p[cur][sj[S]][sd[S]]; p[cur][sj[S]][sd[S]] = 0; ins[cur][sj[S]][sd[S]] = false;
		cl = cr = (X - sd[S])/2;
		if (sj[S] == 0) cl += sd[S];
		else cr += sd[S];
		S++; if (S == 4*MAXJ) S = 0;

		if (cl > cr) {
			if (cl >= J && cl-cr >= D) {
				PL += curp;
				EX += curp*X;
			} else {
				p[next][0][cl-cr+1] += curp*pl;
				if (ins[next][0][cl-cr+1] == false) {
					sj[E] = 0; sd[E] = cl-cr+1;
					E++; if (E == 4*MAXJ) E = 0;
					ins[next][0][cl-cr+1] = true;
				}

				p[next][0][cl-cr-1] += curp*pr;
				if (ins[next][0][cl-cr-1] == false) {
					sj[E] = 0; sd[E] = cl-cr-1;
					E++; if (E == 4*MAXJ) E = 0;
					ins[next][0][cl-cr-1] = true;
				}
			}
		} else if (cl < cr) {
			if (cr >= J && cr-cl >= D) {
				PR += curp;
				EX += curp*X;
			} else {
				p[next][1][cr-cl+1] += curp*pr;
				if (ins[next][1][cr-cl+1] == false) {
					sj[E] = 1; sd[E] = cr-cl+1;
					E++; if (E == 4*MAXJ) E = 0;
					ins[next][1][cr-cl+1] = true;
				}

				p[next][1][cr-cl-1] += curp*pl;
				if (ins[next][1][cr-cl-1] == false) {
					sj[E] = 1; sd[E] = cr-cl-1;
					E++; if (E == 4*MAXJ) E = 0;
					ins[next][1][cr-cl-1] = true;
				}
			}
		} else {
			p[next][0][1] += curp*pl;
			if (ins[next][0][1] == false) {
				sj[E] = 0; sd[E] = 1;
				E++; if (E == 4*MAXJ) E = 0;
				ins[next][0][1] = true;
			}

			p[next][1][1] += curp*pr;
			if (ins[next][1][1] == false) {
				sj[E] = 1; sd[E] = 1;
				E++; if (E == 4*MAXJ) E = 0;
				ins[next][1][1] = true;
			}
		}
	}
}

void calc_set_gauss(tint pl, tint &PL, tint &EX, int J, int D) {
	int i, e[2][MAXD], E;
	tint pnc[MAXJ][MAXJ], *ppnncc[MAXJ], c[2*MAXD][2*MAXD], *cc[2*MAXD], b[2][2*MAXD], *bb[2], pr=1.0-pl;

	for (i=0; i<MAXJ; i++) ppnncc[i] = pnc[i];
	for (i=0; i<2*MAXD; i++) cc[i] = c[i];
	bb[0] = b[0]; bb[1] = b[1];

	simulate(ppnncc, pl, J);

	PL = EX = 0.0;
	for (i=0; i<=J-D; i++) {
		PL += pnc[J][i];
		EX += (pnc[i][J]+pnc[J][i])*(J+i);
	}

	E = 0;
	e[0][0] = e[1][0] = E++;
	for (i=1; i<=D; i++) {
		e[0][i] = E++;
		e[1][i] = E++;
	}

	memset(c, 0.0, sizeof(c));
	memset(b, 0.0, sizeof(b));
	for (i=1; i<D; i++) {
		c[e[0][i]][e[0][i]] = -1.0;
		c[e[0][i]][e[0][i+1]] = pl;
		c[e[0][i]][e[0][i-1]] = pr;
		b[0][e[0][i]] = 0.0;
		b[1][e[0][i]] = -1.0;

		c[e[1][i]][e[1][i]] = -1.0;
		c[e[1][i]][e[1][i+1]] = pr;
		c[e[1][i]][e[1][i-1]] = pl;
		b[0][e[1][i]] = 0.0;
		b[1][e[1][i]] = -1.0;
	}
	c[0][0] = -1.0;
	c[0][e[0][1]] = pl;
	c[0][e[1][1]] = pr;
	b[0][0] = 0.0;
	b[1][0] = -1.0;

	c[e[0][D]][e[0][D]] = 1.0;
	b[0][e[0][D]] = 1.0;
	b[1][e[0][D]] = 0.0;

	c[e[1][D]][e[1][D]] = 1.0;
	b[0][e[1][D]] = 0.0;
	b[1][e[1][D]] = 0.0;

	gaussjordan(cc, bb, E, 2);

	for (i=J-D+1; i<J; i++) {
		PL += pnc[J][i]*b[0][e[0][J-i]];
		EX += pnc[J][i]*(J+i + b[1][e[0][J-i]]);

		PL += pnc[i][J]*b[0][e[1][J-i]];
		EX += pnc[i][J]*(J+i + b[1][e[1][J-i]]);
	}
}

void calc_match(tint pl, tint &PL, tint &EX, int S) {
	tint pnc[MAXJ][MAXJ], *ppnncc[MAXJ];

	for (int i=0; i<MAXJ; i++) ppnncc[i] = pnc[i];

	simulate(ppnncc, pl, S);

	for (int i=0; i<S; i++) {
		PL += pnc[S][i];
		EX += (pnc[S][i] + pnc[i][S])*(S+i);
	}
}

int perm[MAXN];
tint BEST;

void check(int N, tint **pp, tint **ep) {
	int i, j, k, l, K, a, b;
	tint prob[MAXK][MAXN], RES;

	for (K=1; N!=(1<<K); K++);

	memset(prob, 0.0, sizeof(prob));
	for (i=0; i<N; i++) prob[0][i] = 1.0;

	RES = 0.0;
	for (k=1; k<=K; k++) {
		for (i=0; i<N; i+=(1<<k)) {
			for (j=i; j<i+(1<<(k-1)); j++) {
				for (l=i+(1<<(k-1)); l<i+(1<<k); l++) {
					a = perm[j]; b = perm[l];
					RES += prob[k-1][a]*prob[k-1][b]*ep[a][b];
					prob[k][a] += prob[k-1][a]*prob[k-1][b]*pp[a][b];
					prob[k][b] += prob[k-1][b]*prob[k-1][a]*pp[b][a];
				}
			}
		}
	}
	if (RES > BEST) BEST = RES;
}

void dfs(int m, int c, int N, tint **pp, tint **ep) {
	if (m == ((1<<N)-1)) {
		check(N, pp, ep);
	} else {
		for (int i=0; i<N; i++) {
			if (((m>>i)&1) == 0) {
				perm[c] = i;
				dfs(m^(1<<i), c+1, N, pp, ep);
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);

	int K, N, S, J, D, i, j, tmp;
	tint pj[MAXN][MAXN], ps[MAXN][MAXN], es[MAXN][MAXN], pp[MAXN][MAXN], ep[MAXN][MAXN], *pppp[MAXN], *eepp[MAXN];

	for (i=0; i<MAXN; i++) {
		pppp[i] = pp[i];
		eepp[i] = ep[i];
	}

	while (cin >> K >> S >> J >> D && (K!=-1 || S!=-1 || J!=-1 || D!=-1)) {
		assert(K>=K_LOW && K<=K_HIGH);
		assert(S>=S_LOW && S<=S_HIGH);
		assert(J>=J_LOW && J<=J_HIGH);
		assert(D>=D_LOW && D<=J);

		N = (1<<K);
		for (i=0; i<N; i++) {
			for (j=0; j<N; j++) {
				cin >> tmp; assert(tmp >= P_LOW && tmp <= P_HIGH);
				pj[i][j] = tmp/100.0;
			}
		}

		memset(ps, 0.0, sizeof(ps));
		memset(es, 0.0, sizeof(es));
		for (i=0; i<N; i++) {
			for (j=i+1; j<N; j++) {
				if (SIMULACION) calc_set_simulacion(pj[i][j], ps[i][j], es[i][j], J, D);
				else calc_set_gauss(pj[i][j], ps[i][j], es[i][j], J, D);

				ps[j][i] = 1.0 - ps[i][j];
				es[j][i] = es[i][j];
			}
		}

		memset(pp, 0.0, sizeof(ps));
		memset(ep, 0.0, sizeof(es));
		for (i=0; i<N; i++) {
			for (j=i+1; j<N; j++) {
				calc_match(ps[i][j], pp[i][j], ep[i][j], S);
				ep[i][j] *= es[i][j];

				pp[j][i] = 1.0 - pp[i][j];
				ep[j][i] = ep[i][j];
			}
		}

		BEST = 0.0;
		dfs(0, 0, N, pppp, eepp);
		printf("%.*lf\n", PRECISION, BEST);
	}

	return 0;
}
