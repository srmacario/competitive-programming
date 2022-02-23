#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 505, INF = 1e9;
int mark[N], vis[N], ans[N];
vector<int> adj[N];

struct edge {int v, f, w, c; };

int n, m, flw_lmt = INF, src, snk, flw, cst, p[N], d[N], et[N];
vector<edge> e;
vector<int> g[N];
vector<int> nodes[2];

void add_edge(int u, int v, int w, int c) {
  int k = e.size();
  g[u].push_back(k);
  g[v].push_back(k+1);
  e.push_back({ v, 0,  w, c });
  e.push_back({ u, 0, -w, 0 });
}

void clear() {
    src = 0;
    snk = N - 1;
    flw_lmt = INF;
    for(int i = 0; i < N; ++i) g[i].clear(), p[i] = 0;
    e.clear();
}

void min_cost_max_flow() {
  flw = 0, cst = 0;
  while (flw < flw_lmt) {
    memset(et, 0, sizeof(et));
    memset(d, 63, sizeof(d));
    deque<int> q;
    q.push_back(src), d[src] = 0;

    while (!q.empty()) {
      int u = q.front(); q.pop_front();
      et[u] = 2;

      for(int i : g[u]) {
        edge &dir = e[i];
        int v = dir.v;
        if (dir.f < dir.c and d[u] + dir.w < d[v]) {
          d[v] = d[u] + dir.w;
          if (et[v] == 0) q.push_back(v);
          else if (et[v] == 2) q.push_front(v);
          et[v] = 1;
          p[v] = i;
        }
      }
    }

    if (d[snk] > INF) break;

    int inc = flw_lmt - flw;
    for (int u=snk; u != src; u = e[p[u]^1].v) {
      edge &dir = e[p[u]];
      inc = min(inc, dir.c - dir.f);
    }

    for (int u=snk; u != src; u = e[p[u]^1].v) {
      edge &dir = e[p[u]], &rev = e[p[u]^1];
      dir.f += inc;
      rev.f -= inc;
      cst += inc * dir.w;
    }

    if (!inc) break;
    flw += inc;
  }
}

void dfs(int u, int cnt, int pos){
    vis[u] = cnt + 1;
    nodes[pos].push_back(u);
    for(int i = 0; i < (int)g[u].size(); i++){
        int j = g[u][i];
        if(e[j].c == 0) continue;
        if(vis[e[j].v]) continue;
        if(e[j].f == e[j].c) dfs(e[j].v, cnt, pos);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) mark[i] = -1, ans[i] = 0, adj[i].clear(), vis[i] = 0;
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int k;
        cin >> k;
        for(int i = 1; i <= k; i++){
            int u;
            cin >> u;
            cin >> mark[u];
        }
        for(int i = 31; i >= 0; i--){
            //reset
            clear();
            nodes[0].clear(), nodes[1].clear();
            adj[src].clear();
            adj[snk].clear();
            //end of reset
            for(int j = 1; j <= n; j++){
                if(mark[j] != -1){
                    //connect 1 to src and 0 to snk
                    if((1 << i) & mark[j]){
                        add_edge(src, j, 0, INF);
                        adj[src].push_back(j);
                    }
                    else{
                        add_edge(j, snk, 0, INF);
                        adj[snk].push_back(j);
                    }
                    for(auto v: adj[j]){
                        add_edge(j, v, 0, 1), add_edge(v, j, 0, 1);
                    }
                }
            }
            min_cost_max_flow();
            dfs(src, i, 1);
            dfs(snk, i, 0);
            for(int j = 0; j < 2; j++){
                for(auto u : nodes[j]){
                    if(mark[u] == -1){
                        ans[u] += (1 << i) * j;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(mark[i] != -1) ans[i] = mark[i];
            cout << ans[i] << "\n";
        }
    }
    return 0;
}