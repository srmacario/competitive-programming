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

int n, q, vis[N], par[N], cmp[N];
set<int> endp;
bool cyc[N];
vector<int> adj[N];

bool dfs(int u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]){
            par[v] = u;
            bool is_cyc = dfs(v);
            cyc[u] |= is_cyc;
        }
        else if(par[u] != v) cyc[u] = true, endp.insert(v);
    }
    if(endp.count(u)) return false;
    return cyc[u];
}

void mark_dfs(int u, int cnt){
    vis[u] = 0;
    cmp[u] = cnt;
    for(auto v: adj[u]){
        if(vis[v] and (!cyc[v] or !cyc[u])) mark_dfs(v, cnt);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) if(vis[i]) mark_dfs(i, ++cnt);
    cin >> q;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if(cmp[x] == cmp[y]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
