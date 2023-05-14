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
const int N = 2e5+5;

vector<pii> adj[N], adjt[N], new_adj[N];
set<int> cmp_vert[N];
int n, m, ordn, cnt, vis[N], ord[N], cmp[N];
int par[N];

void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) if(!vis[v.st]) par[v.st] = u, dfs(v.st);
  ord[ordn++] = u;
}

void dfst(int u) {
  cmp[u] = cnt, vis[u] = 0;
  cmp_vert[cnt].insert(u);
  for (auto v : adj[u]) if(vis[v.st] and u != par[v.st]) dfst(v.st);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // in main
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
    for (int i = ordn-1; i >= 0; --i) if (vis[ord[i]]) cnt++, dfst(ord[i]);
    for(int i = 1; i <= cnt; i++){
        for(auto u : cmp_vert[cnt]){
            for(auto v : adj[u]){
                new_adj[i].push_back({cmp[v.st], v.nd});
            }
        }
    }
    return 0;
}