#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2e5 + 5;

vector<int> adj[N], adjt[N];
int n, m, ordn, scc_cnt, vis[N], ord[N], scc[N];

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]) if(!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst(int u){
    scc[u] = scc_cnt, vis[u] = 0;
    for(auto v : adjt[u]) if(vis[v]) dfst(v);
}

void add_edge(int u, int v){
    adj[u].push_back(v);
    adjt[v].push_back(u);
}

void kosaraju(){
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    for(int i = ordn - 1; i >= 0; i--) if(vis[ord[i]]) scc_cnt++, dfst(ord[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        }
        kosaraju();
        if(scc_cnt == 1) cout << "YES\n";
        else cout << "NO\n";
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            adjt[i].clear();
            vis[i] = 0;
        }
        for(int i = 0; i <= ordn; i++) ord[ordn] = 0;
        ordn = scc_cnt = 0;
    }
    return 0;
}