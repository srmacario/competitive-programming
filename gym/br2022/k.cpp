#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef short int si;

const si N = 10;
const si K = 401;
const int MOD = 1e9;

struct poly{
	int coef[K] = {0};
	
	int& operator [](int x){ return coef[x]; }
	
	poly operator +(poly o){
		for(si i = 0; i < K; i++){
			o[i] += coef[i];
			o[i] -= (o[i] >= MOD) * MOD;
		}
		return o;
	}
	
	poly operator *(poly &o){
		poly ret;
		for(si i = 0; i < K; i++)
			for(si j = 0; i + j < K; j++)
				ret[i + j] = ((ll)coef[i] * o[j] + ret[i + j]) % MOD;
		return ret;
	}
	
	void operator +=(poly o){
		for(si i = 0; i < K; i++){
			coef[i] += o[i];
			coef[i] -= (coef[i] >= MOD) * MOD;
		}
	}
} ansp, p[10];

struct matrix{
	poly p[N][N];
	
	void multiply(matrix &o){
		matrix ret;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				for(int k = 0; k < N; k++)
					ret.p[i][j] += (p[i][k] * o.p[k][j]);
		for(si i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				p[i][j] = ret.p[i][j];
	}
	
	void sqr(){
		matrix ret;
		for(si i = 0; i < N; i++)
			for(si j = 0; j < N; j++)
				for(si k = 0; k < N; k++)
					ret.p[i][j] += (p[i][k] * p[k][j]);
		for(si i = 0; i < N; i++)
			for(si j = 0; j < N; j++)
				p[i][j] = ret.p[i][j];
	}
} rec, id;

int n, m, k, u, v, ans;

void fexp(){
	while(n){
		if(n & 1)
			id.multiply(rec);
		rec.sqr();
		n >>= 1;
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	n--;
	for(int i = 0; i < 9; i++)
		rec.p[i + 1][i][0] = 1;
	while(m--){
		scanf("%d %d", &u, &v);
		rec.p[10 - u][9][v]++;
	}
	p[0][0] = 1;
	for(int i = 1; i <= 9; i++)
		for(int j = 0; j <= i; j++)
			p[i] = p[i] + p[i - j] * rec.p[10 - j][9];
	for(int i = 0; i <= 9; i++)
		id.p[i][i][0] = 1;
	fexp();
	for(int i = 0; i <= 9; i++)
		ansp = ansp + p[i] * id.p[i][0];
	for(int i = 0; i <= k; i++)
		ans = (ans + ansp[i]) % MOD;
	printf("%d\n", ans);
	return 0;
}