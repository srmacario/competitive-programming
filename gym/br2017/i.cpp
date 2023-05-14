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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;  // Max number of vertices
const int K = 20;     // Each 1e3 requires ~ 10 K
const int M = K+5;

int n, r, cost = 0;
vector <piii> edges; //mp(dist, mp(node1, node2))
map<pii,int> ed;
set<pii> con;

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

vector <pii> adj[N];
int vis[N], h[N], anc[N][M], mx[N][M];

void dfs (int u) {
    vis[u] = 1;
    for (auto p : adj[u]) {
        int v = p.st;
        int w = p.nd;
        if (!vis[v]) {
            h[v] = h[u]+1;
            anc[v][0] = u;
            mx[v][0] = w;
            dfs(v);
        }
    }
}

void build () {
    // cl(mn, 63) -- Don't forget to initialize with INF if min edge!
    anc[1][0] = 1;
    dfs(1);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++) {
        anc[i][j] = anc[anc[i][j-1]][j-1];
        mx[i][j] = max(mx[i][j-1], mx[anc[i][j-1]][j-1]);
    }
}

int mxedge (int u, int v) {
    int ans = 0;

    if (h[u] < h[v]) swap(u, v);
    for (int j = K; j >= 0; j--) if (h[anc[u][j]] >= h[v]) {
        ans = max(ans, mx[u][j]);
        u = anc[u][j];
    }
    if (u == v) return ans;
    for (int j = K; j >= 0; j--) if (anc[u][j] != anc[v][j]) {
        ans = max(ans, mx[u][j]);
        ans = max(ans, mx[v][j]);
        u = anc[u][j];
        v = anc[v][j];
    }
    return max({ans, mx[u][0], mx[v][0]});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    cin >> n >> r;
    for(int i=0;i<r;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges.pb({c,{a,b}});
        ed[{min(a,b),max(a,b)}] = c;
    }
    sort(edges.begin(), edges.end());
    for (auto e : edges){
        if (find(e.nd.st) != find(e.nd.nd)){
            unite(e.nd.st, e.nd.nd), cost += e.st;
            adj[e.nd.st].pb({e.nd.nd,e.st});
            adj[e.nd.nd].pb({e.nd.st,e.st});
            con.insert({min(e.nd.st,e.nd.nd), max(e.nd.st,e.nd.nd)});
        }
    }
    build();
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
        int u,v;
        cin >> u >> v;
        int ans = cost;
        if(!con.count({min(u,v),max(u,v)})) ans += ed[{min(u,v),max(u,v)}] - mxedge(u,v);
        cout << ans << "\n";
    }
    return 0;
}