#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

const int N = 5e5 + 5, INF = 1e9;

struct edge {int v, f, w, c; };

int n, flw_lmt = INF, src, snk, flw, cst, p[N], d[N], et[N];
int grid[505][505];
vector<edge> e;
vector<int> g[N];

void add_edge(int u, int v, int w, int c) {
  int k = e.size();
  g[u].push_back(k);
  g[v].push_back(k+1);
  e.push_back({ v, 0,  w, c });
  e.push_back({ u, 0, -w, 0 });
}

void clear(){
    memset(grid, 0, sizeof(grid));
    src = 0;
    snk = N - 1;
    flw_lmt = INF;
    for(int i = 0; i < N; i++) g[i].clear();
    e.clear();
}

void min_cost_max_flow() {
  flw = 0, cst = 0;
  while (flw < flw_lmt) {
    memset(et, 0, sizeof(et));
    memset(d, 63, sizeof(et));
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

int id(int i, int j, int n, int m){
    return i + m*j + n*m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        clear();
        int x, y, p, w;
        cin >> x >> y >> p;
        for(int i = 0; i < p; i++){
            int u, v;
            cin >> u >> v;
            grid[u][v] = 1;
        }
        cin >> w;
        for(int i = 0; i < w; i++){
            int u, v;
            cin >> u >> v;
            grid[u][v] = -1;
        }
        ///src - > linha - > *
        //segmentos -> 1 : 10000
        //pontos vao ser de: x*y ...
        int cnt = 1;
        add_edge(src, cnt, 0, 1);
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++){
                if(grid[i][j] == -1){
                    cnt++;
                    add_edge(src, cnt, 0, 1);
                }
                if(grid[i][j] == 1){
                    add_edge(cnt, id(i, j, x, y), 0, INF);
                }
            }
            cnt++;
            add_edge(src, cnt, 0, 1);
        }
        cnt++;
        add_edge(cnt, snk, 0, 1);
        for(int i = 1; i <= y; i++){
            for(int j = 1; j <= x; j++){
                if(grid[j][i] == -1){
                    cnt++;
                    add_edge(cnt, snk, 0, 1);
                }
                if(grid[j][i] == 1){
                    add_edge(id(j, i, x, y), cnt, 0, INF);
                }
            }
            cnt++;
            add_edge(cnt, snk, 0, 1);
        }
        min_cost_max_flow();
        cout << flw << "\n";
    }
    return 0;
}