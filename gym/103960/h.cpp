#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

vector<int> adj[N], adjt[N];
int n, m, ordn, scc_cnt, vis[N], ord[N], scc[N], in[N], out[N];

//Directed Version
void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) if (!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  scc[u] = scc_cnt, vis[u] = 0;
  for (auto v : adjt[u]) if (vis[v]) dfst(v);
}

// add edge: u -> v
void add_edge(int u, int v){
  adj[u].push_back(v);
  adjt[v].push_back(u);
}

// run kosaraju
void kosaraju(){
  for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
  for (int i = ordn - 1; i >= 0; --i) if (vis[ord[i]]) scc_cnt++, dfst(ord[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }
    kosaraju();
    for(int u = 1; u <= n; u++){
        for(auto v : adj[u]){
            if(scc[v] == scc[u]) continue;
            in[scc[v]]++;
            out[scc[u]]++;
        }
    }
    if(scc_cnt == 1){
        cout << "0\n";
    }
    else{
        int in_cnt = 0, out_cnt = 0;
        for(int i = 1; i <= scc_cnt; i++) in_cnt += (in[i] == 0), out_cnt += (out[i] == 0);
        cout << max(in_cnt, out_cnt) << "\n";
    }
    return 0;
}