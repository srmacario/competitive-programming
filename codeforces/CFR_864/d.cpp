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

int n, m, sz[N], vis[N], par[N];
ll a[N], imp[N];
vector<int> adj[N];
set<pair<int, int>> heavy_adj[N];

void dfs(int u){
    vis[u] = 1;
    sz[u]++;
    imp[u] += a[u];
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
            par[v] = u;
            sz[u] += sz[v];
            imp[u] += imp[v];
            heavy_adj[u].insert({sz[v], -v});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 0; i < m; i++){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            cout << imp[x] << "\n";
        }
        else{
            if(heavy_adj[x].empty()) continue;
            int pai = par[x];

            pii heavy_son = *heavy_adj[x].rbegin();
            heavy_adj[pai].erase({sz[x], -x});

            //remove heavy_son from x
            sz[x] -= sz[-heavy_son.nd];
            imp[x] -= imp[-heavy_son.nd];
            heavy_adj[x].erase(heavy_son);

            //add x to heavy_son
            sz[-heavy_son.nd] += sz[x];
            imp[-heavy_son.nd] += imp[x];
            heavy_adj[-heavy_son.nd].insert({sz[x], -x});
            par[x] = -heavy_son.nd;

            //add heavy_son to pai
            heavy_adj[pai].insert({sz[-heavy_son.nd], heavy_son.nd});
            par[-heavy_son.nd] = pai;
        }
    }
    return 0;
}