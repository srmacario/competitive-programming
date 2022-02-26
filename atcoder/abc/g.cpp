#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9, MOD = 1e9+7;
const int M = 105, N = 1e5 + 5;

int n, m, match[M][M], w[M];

struct edge {int v, c, f;};

int src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

void add_edge (int u, int v, int c) {
  int k = edgs.size();
  edgs.push_back({v, c, 0});
  edgs.push_back({u, 0, 0});
  g[u].push_back(k);
  g[v].push_back(k+1);
}

void clear() {
    memset(h, 0, sizeof h);
    memset(ptr, 0, sizeof ptr);
    edgs.clear();
    for (int i = 0; i < N; i++) g[i].clear();
    src = 0;
    snk = N-1;
}

bool bfs() {
  memset(h, 0, sizeof h);
  queue<int> q;
  h[src] = 1;
  q.push(src);
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i : g[u]) {
      int v = edgs[i].v;
      if (!h[v] and edgs[i].f < edgs[i].c)
        q.push(v), h[v] = h[u] + 1;
    }
  }
  return h[snk];
}

int dfs (int u, int flow) {
  if (!flow or u == snk) return flow;
  for (int &i = ptr[u]; i < g[u].size(); ++i) {
    edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
    int v = dir.v;
    if (h[v] != h[u] + 1)  continue;
    int inc = min(flow, dir.c - dir.f);
    inc = dfs(v, inc);
    if (inc) {
      dir.f += inc, rev.f -= inc;
      return inc;
    }
  }
  return 0;
}

int dinic() {
  int flow = 0;
  while (bfs()) {
    memset(ptr, 0, sizeof ptr);
    while (int inc = dfs(src, INF)) flow += inc;
  }
  return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) match[i][i] = 1;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        match[u][v] = match[v][u] = 1;
        w[u]++;
    }
    for(int i = 1; i <= n; i++){
        clear();
        int num = n + 1, cnt = 0, cur = 0;
        for(int j = 1; j <= n; j++){
            if(!match[i][j]){
                cur++;
            }
        }
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            for(int k = j + 1; k <= n; k++){
                if(k == i) continue;
                if(!match[j][k]){
                    add_edge(src, num, 1);
                    add_edge(num, j, 1);
                    add_edge(num, k, 1);
                    num++;
                    cnt++;
                }
            }
        }
        bool ok = true;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(w[j] >= w[i] + cur){
                ok = false;
                break;
            }
            add_edge(j, snk, w[i] + cur - w[j] - 1);
        }
        if(ok){
            int f = dinic();
            //db(f _ cnt);
            if(f == cnt) cout << i << " ";
        }
    }
    return 0;
}