#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAXN 4096
#define MAXM 8388608

#define OTHER(cure, cur) ( m[(cure)].a == (cur) ? m[(cure)].b : m[(cure)].a )

struct edge {
	int a, b, w;
} m[MAXM];

bool operator<(const edge &e1, const edge &e2) {
	if (e1.w != e2.w) return e1.w < e2.w;
	else if (e1.a != e2.a) return e1.a < e2.a;
	else return e1.b < e2.b;
}

int f[MAXN], rep[MAXM], best[MAXN], edges[MAXN][MAXN];
vector<int> adj[MAXN], notadj[MAXN];

int getf(int cur) {
	if (f[cur] != cur) f[cur] = getf(f[cur]);
	return f[cur];
}

int process(int a, int b) {
	if (a == -1) return b;
	else if (b == -1) return a;
	else return ( m[a].w < m[b].w ? a : b );
}

void dfs(int cur, int p) {
	for (int i=0; i<(int)adj[cur].size(); i++) {
		int next = OTHER(adj[cur][i], cur);
		if (next == p) continue;
		
		dfs(next, cur);
		rep[adj[cur][i]] = process(rep[adj[cur][i]], best[next]);
		best[cur] = process(best[cur], best[next]);
	}
}

int main() {
	int N, M, Q, i, j, fa, fb, a, b, w, tmp;
	long long RES, MST;
	
	while (cin >> N >> M && (N!=0 || M!=0)) {
		for (i=0; i<M; i++) cin >> m[i].a >> m[i].b >> m[i].w;
		sort(m,m+M);
		for (i=0; i<M; i++) edges[m[i].a][m[i].b] = edges[m[i].b][m[i].a] = i;
		
		MST = 0LL;
		for (i=0; i<N; i++) { f[i] = i; adj[i].clear(); notadj[i].clear(); }
		for (i=0; i<M; i++) {
			fa = getf(m[i].a); fb = getf(m[i].b);
			if (fa != fb) {
				f[fa] = fb; rep[i] = -1;
				adj[m[i].a].push_back(i);
				adj[m[i].b].push_back(i);
				MST += m[i].w;
			} else {
				rep[i] = -2;
				notadj[m[i].a].push_back(i);
				notadj[m[i].b].push_back(i);
			}
		}
		
		for (i=0; i<N; i++) {
			memset(best, -1, sizeof(best));
			for (j=0; j<(int)notadj[i].size(); j++) {
				tmp = OTHER(notadj[i][j], i);
				best[tmp] = process(notadj[i][j], best[tmp]);
			}
			dfs(i, -1);
		}
		
		cin >> Q; RES = 0LL;
		for (i=0; i<Q; i++) {
			cin >> a >> b >> w;
			tmp = edges[a][b];

			if (rep[tmp] == -2) RES += MST;
			else if (rep[tmp] == -1 || m[rep[tmp]].w > w) RES += MST - m[tmp].w + w;
			else RES += MST - m[tmp].w + m[rep[tmp]].w;
		}
		printf("%.4lf\n", RES/((double)Q));
	}

	return 0;
}
