#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

const int INF = INT_MAX, MOD = 1e9+7;
const int N = 1e5+5;

const int K = 20;     // Each 1e3 requires ~ 10 K
const int M = K+5;
int n, m, w[N], vis[N], par[N], h[N], anc[M][N];                // Number of vertices
vector<int> root, adj[N];


vector<int> e, d, sum;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

int update(int pos, int ini, int fim, int id, int val){
    int novo = create();
    
    sum[novo] = sum[pos];
    e[novo] = e[pos];
    d[novo] = d[pos];
    pos = novo;

    if(ini == fim){
        sum[pos] += val;
        return novo;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        int aux = update(e[pos], ini, m, id, val);
        e[pos] = aux;
    }
    else{
        int aux = update(d[pos], m + 1, fim, id, val);
        d[pos] = aux;
    }

    sum[pos] = sum[e[pos]] + sum[d[pos]];
    return pos;
}

int query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return 0;

    if(pos == 0) return 0;

    if(p <= ini and fim <= q) return sum[pos];
    
    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, p, q) + query(d[pos], m + 1, fim, p, q);
}

void dfs (int u) {
    root.push_back(update(root[vis[par[u]]], 1, INF, w[u], 1));
    vis[u] = root.size() - 1;
    for (int j = 0; j < (int)adj[u].size(); j++){
        int v = adj[u][j];
        if (!vis[v]) {
            h[v] = h[u] + 1;
            anc[0][v] = u;
            par[v] = u;
            dfs(v);
        }
    }
}

void build () {
    anc[0][1] = 1;
    dfs(1);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++)
        anc[j][i] = anc[j - 1][anc[j - 1][i]];
}

int lca (int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int j = K; j >= 0; j--) if (h[anc[j][u]] >= h[v]) {
        u = anc[j][u];
    }
    if (u == v) return u;
    for (int j = K; j >= 0; j--) if (anc[j][u] != anc[j][v]) {
        u = anc[j][u];
        v = anc[j][v];
    }
    return anc[0][u];
}


int bin_s(int par_pos, int lca_pos, int u_pos, int v_pos, int ini, int fim, int k){
    if(ini == fim) return ini;
    int sum_left = sum[e[u_pos]] + sum[e[v_pos]] - sum[e[lca_pos]] - sum[e[par_pos]];
    int m = (ini + fim) >> 1;
    if(sum_left >= k) return bin_s(e[par_pos], e[lca_pos], e[u_pos], e[v_pos], ini, m, k);
    return bin_s(d[par_pos], d[lca_pos], d[u_pos], d[v_pos], m + 1, fim, k - sum_left);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root.push_back(create());
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build();
    for(int i = 0; i < m; i++){
        int u, v, k, p;
        cin >> u >> v >> k;
        p = lca(u, v);
        cout << bin_s(root[vis[par[p]]], root[vis[p]], root[vis[u]], root[vis[v]], 1, INF, k) << "\n";
    }
    return 0;
}