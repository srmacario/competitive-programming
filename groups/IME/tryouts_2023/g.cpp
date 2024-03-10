#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;

const int N = 1e5+5;

vector<pii> adj[N], adjt[N];
int n, m, vis[N], dist[N];
ll cost;

void prim(){
    priority_queue<pair<int, pii>> pq;
    pq.push({0, {1, 0}});

    while(!pq.empty()){
        int u = pq.top().nd.st;
        int par = pq.top().nd.nd;
        int w = -pq.top().st;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        if(par){
            adjt[u].push_back({w, par});
            adjt[par].push_back({w, u});
            cost += w;
        }
        for(auto nxt : adj[u]){
            if(!vis[nxt.nd]) pq.push({-nxt.st, {nxt.nd, u}});
        }
    }
}

int bfs(int s){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto nxt : adjt[u]){
            if(dist[nxt.nd] > dist[u] + 1){
                dist[nxt.nd] = dist[u] + 1;
                q.push(nxt.nd);
            }
        }
    }
    pair<int, int> ans = {0, 0};
    for(int i = 1; i <= n; i++){
        if(i == s or dist[i] == INF) continue;
        ans = max(ans, make_pair(dist[i], i));
    }
    return ans.nd;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    prim();
    int cur = bfs(1);
    cout << cost << "\n";
    cout << dist[bfs(cur)] << "\n";
    return 0;
}