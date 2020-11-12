
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 2e5+5;
const int K = 20;
const int M = K+5;
ll n,m, ans[N];
vector<pll> adj[N];
vector<pair<pll,pll>> edges;
ll vis[N], h[N], anc[N][M], dist[N][M], cost, par[N], sz[N], vis_edge[N];

ll find(ll a){return par[a] == a? a : par[a] = find(par[a]);}

void unite(ll a, ll b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    par[b] = a;
}

void kruskal(){
    for(int i=0;i<n;i++) par[i] = i, sz[i] = 1;
    sort(edges.begin(), edges.end());
    for(int i=0;i<m;i++){
        pair<pii,pii> e = edges[i];
        if(find(e.nd.st) != find(e.nd.nd)){
            unite(e.nd.st, e.nd.nd);
            cost += e.st.st;
            adj[e.nd.st].pb({e.nd.nd,e.st.st});
            adj[e.nd.nd].pb({e.nd.st,e.st.st});
            vis_edge[i] = 1;
        }
    }
}

void dfs (int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v.st]) {
        h[v.st] = h[u]+1;
        anc[v.st][0] = u;
        dist[v.st][0] = v.nd;
        dfs(v.st);
    }
}

void build () {
    anc[1][0] = 1;
    dfs(1);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++)
        anc[i][j] = anc[anc[i][j-1]][j-1], dist[i][j] = max(dist[i][j-1], dist[anc[i][j-1]][j-1]);
}

ll maxw (int u, int v) {
    ll ans = 0;
    if (h[u] < h[v]) swap(u, v);
    for (int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) ans = max(ans,dist[u][j]), u = anc[u][j];
    if (u == v) return ans;
    for (int j = 20; j >= 0; j--) if (anc[u][j] != anc[v][j]) ans = max({ans, dist[u][j], dist[v][j]}), u = anc[u][j], v = anc[v][j];
    return max({ans, dist[u][0], dist[v][0]});
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        edges.pb({{w,i},{u,v}});
    }
    kruskal();
    build();
    for(int i=0;i<m;i++){
        int u = edges[i].nd.st, v = edges[i].nd.nd, w = edges[i].st.st, id = edges[i].st.nd;
        if(vis_edge[i]) ans[id] = cost;
        else ans[id] = cost - maxw(u,v) + w;
    }
    for(int i=0;i<m;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
