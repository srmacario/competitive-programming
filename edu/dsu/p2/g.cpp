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

int n, k, par[N], sz[N];
vector<pii> adj[N];
vector<piii> edges;

int find(int u){
    return (par[u] == u ? u : par[u] = find(par[u]));
}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for(int i = 0; i < k; i++){
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
        edges.push_back({d, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for(auto e : edges){
        int u = e.nd.st, v = e.nd.nd, cost = e.st;
        if(find(u) == find(v)) continue;
        unite(u, v);
        ans = max(ans, cost);
    }
    cout << ans << "\n";
    return 0;
}