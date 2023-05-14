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

int n, m, par[N], sz[N];
ll s;
vector<pii> adj[N];
vector<pair<pii, pii>> edges;

int find(int u){
    return (par[u] == u ? u : par[u] = find(par[u]));
}

void unite(int u, int v){
    if((u = find(u)) == (v = find(v))) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
        edges.push_back({{c, i}, {u, v}});
    }
    sort(edges.begin(), edges.end(), greater<pair<pii, pii>>());
    vector<pii> unused;
    for(auto e : edges){
        int u = e.nd.st, v = e.nd.nd;
        pii c = e.st;
        if(find(u) == find(v)) unused.push_back(c);
        unite(u, v);
    }
    reverse(unused.begin(), unused.end());
    ll cur = 0;
    vector<int> ans;
    for(auto c : unused){
        if(cur + c.st <= s){
            ans.push_back(c.nd);
            cur += c.st;
        }
        else break;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a + 1 << " ";
    cout << "\n";
    return 0;
}