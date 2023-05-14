#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

const int N = 505;

int par[N], sz[N], vis[N];
set<pair<int, pair<int, int>>> used;
vector<pair<int, int>> adj[N];

int find(int a){
    return par[a] == a ? a : par[a] = find(par[a]);
}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

bool dfs(int u, int peso, int fim){
    vis[u] = 1;
    if(u == fim) return true;
    for(auto v : adj[u]){
        if(!vis[v.nd]){
            bool cur = dfs(v.nd, peso, fim);
            if(cur){
                int a = v.nd, b = u;
                if(a > b) swap(a, b);
                if(v.st >= peso) used.erase({v.st, {a, b}});
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        used.clear();
        for(int i = 0; i <= n; i++){
            par[i] = i, sz[i] = 1, vis[i] = 0;
            adj[i].clear();
        }
        int s, d, c;
        vector<pair<int, pair<int, int>>> edges;
        int cost = 0;
        for(int i = 0; i < m; i++){
            cin >> s >> d >> c;
            edges.push_back({c, {s, d}});
        }
        sort(edges.begin(), edges.end());
        for(auto e : edges){
            if(find(e.nd.st) != find(e.nd.nd)){
                unite(e.nd.st, e.nd.nd);
                adj[e.nd.st].push_back({e.st, e.nd.nd});
                adj[e.nd.nd].push_back({e.st, e.nd.st});
                int a = e.nd.st, b = e.nd.nd;
                if(a > b) swap(a, b);
                used.insert({e.st, {a, b}});
            }
            else{
                for(int i = 1; i <= n; i++) vis[i] = 0;
                dfs(e.nd.st, e.st, e.nd.nd);
            }
        }
        cout << used.size() << " ";
        for(auto u : used){
            cost += u.st;
        }
        cout << cost << "\n";
    }
    return 0;
}