#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5, K = 20, M = K + 5;

int n, m, par[N], sz[N];
vector<piii> edges, old;
vector<pii> adj[N];
int vis[N], h[N], anc[N][M], mx[N][M];

int find(int a){return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
}

void dfs(int u){
    vis[u] = 1;
    for(auto p : adj[u]){
        int v = p.nd;
        int w = p.st;
        if(!vis[v]){
            h[v] = h[u] + 1;
            anc[v][0] = u;
            mx[v][0] = w;
            dfs(v);
        }
    }
}

void build(){
    anc[1][0] = 1;
    dfs(1);
    for(int j = 1; j <= K; j++) for(int i = 1; i <= n; i++){
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
        mx[i][j] = max(mx[i][j - 1], mx[anc[i][j - 1]][j - 1]);
    }
}

int mxedge(int u, int v){
    int ans = 0;

    if(h[u] < h[v]) swap(u, v);
    for(int j = K; j >= 0; j--) if(h[anc[u][j]] >= h[v]){
        ans = max(ans, mx[u][j]);
        u = anc[u][j];
    }
    if(u == v) return ans;
    for(int j = K; j >= 0; j--) if(anc[u][j] != anc[v][j]){
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
    cin >> n >> m;
    for(int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
        old.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    ll cost = 0;
    for(auto e : edges){
        if(find(e.nd.st) != find(e.nd.nd)){
            unite(e.nd.st, e.nd.nd);
            cost += e.st;
            adj[e.nd.st].push_back({e.st, e.nd.nd});
            adj[e.nd.nd].push_back({e.st, e.nd.st});
        }
    }
    build();
    for(auto e : old){
        int cur = mxedge(e.nd.st, e.nd.nd);
        cout << (cost - 1ll * cur + 1ll * e.st) << "\n";
    }
    return 0;
}