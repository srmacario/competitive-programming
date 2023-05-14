#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 5;
const int K = 20;
const int M = K + 5;
int n;
vector<int> adj[N];
int vis[N], h[N], anc[N][M], mn[N][M], peso[N];

void dfs(int u){
    vis[u] = 1;
    for(auto p : adj[u]){
        int v = p;
        int w = min(peso[u], peso[v]);
        if(!vis[v]){
            h[v] = h[u] + 1;
            anc[v][0] = u;
            mn[v][0] = w;
            dfs(v);
        }
    }
}

void build(){
    memset(mn, 63, sizeof(mn));
    anc[1][0];
    dfs(1);
    for(int j = 1; j <= K; j++) for(int i = 1; i <= n; i++){
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
        mn[i][j] = min(mn[i][j - 1], mn[anc[i][j - 1]][j - 1]);
    }
}

int min_edge(int u, int v){
    int ans = 0;
    if(h[u] < h[v]) swap(u, v);
    for(int j = K; j >= 0; j--)
        if(h[anc[u][v]] >= h[v]){
            ans = min(ans, mn[u][j]);
            u = anc[u][j];
        }
    
    if(u == v) return ans;
    for(int j = K; j >= 0; j--) if(anc[u][j] != anc[v][j]){
        ans = min(ans, mn[u][j]);
        ans = min(ans, mn[v][j]);
        u = anc[u][j];
        v = anc[v][j];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> peso[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}