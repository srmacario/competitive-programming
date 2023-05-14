#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, INF = 1e9;

struct edge{int v, f, w, c;};

int n, flw_lmt = INF, src, snk, flw, cst, p[N], d[N], et[N];
vector<edge> e;
vector<int> g[N];

void add_edge(int u, int v, int w, int c){
    int k = e.size();
    g[u].push_back(k);
    g[v].push_back(k + 1);
    e.push_back({v, 0, w, c});
    e.push_back({u, 0, -w, 0});
}

void clear() {
    src = 0;
    snk = N - 1;
    flw_lmt = INF;
    for(int i = 0; i < N; i++) g[i].clear();
    e.clear();
}

void min_cost_max_flow() {
  flw = 0, cst = 0;
  while (flw < flw_lmt) {
    memset(et, 0, sizeof et);
    memset(d, 63, sizeof d);
    deque<int> q;
    q.push_back(src), d[src] = 0;

    while (!q.empty()) {
      int u = q.front(); q.pop_front();
      et[u] = 2;

      for(int i : g[u]) {
        edge &dir = e[i];
        int v = dir.v;
        if (dir.f < dir.c and max(d[u], dir.w) < d[v]) {
          d[v] = max(d[u], dir.w);
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
      if(inc > 0) cst = max(cst,  dir.w);
    }

    if (!inc) break;
    flw += inc;
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    while(1){
        ++cnt;
        cin >> n;
        if(!n) return 0;
        clear();
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            int p, q, d;
            cin >> p >> q >> d;
            //p = in, p + n + 1 = out
            if(p > q) swap(p, q);
            if(!p) add_edge(p, q, d, 1);
            else add_edge(p + n + 1, q, d, 1);
        }
        for(int i = 1; i <= n; i++){
            add_edge(i, i + n + 1, 0, 1);
            //cout << i << " " << i +n +1 << "\n";
        }
        int k;
        cin >> k;
        add_edge(n + 1, snk, 0, k);
        //cout << n + 1 << " " << snk << "\n";
        min_cost_max_flow();
        cout << "Case " << cnt << ": ";
        if(flw < k) cout << "no solution\n";
        else cout << cst << "\n";
    }
    return 0;
}