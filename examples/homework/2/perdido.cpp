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
const int N = 105;

const int K = 20;     // Each 1e3 requires ~ 10 K
const int M = K+5;
int n,a,b,c;                // Number of vertices
vi adj[N];
int vis[N], h[N], anc[N][M];

void dfs (int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) {
        h[v] = h[u]+1;
        anc[v][0] = u;
        dfs(v);
    }
}

void build () {
    anc[a][0] = a;
    dfs(a);
    for (int j = 1; j <= K; j++) for (int i = 1; i <= n; i++)
        anc[i][j] = anc[anc[i][j-1]][j-1];
}

int lca (int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int j = K; j >= 0; j--) if (h[anc[u][j]] >= h[v]) {
        u = anc[u][j];
    }
    if (u == v) return u;
    for (int j = K; j >= 0; j--) if (anc[u][j] != anc[v][j]) {
        u = anc[u][j];
        v = anc[v][j];
    }
    return anc[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    while( cin >> n >> a >> b >> c){
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        build();
        int par = lca(b,c);
        int pos = h[c] - h[par];
        int dist = h[c] + h[b] - 2*h[par];
        cout << double (pos)/dist << "\n";
        for(int i=1;i<=n;i++) adj[i].clear();
        cl(vis,0), cl(anc,0), cl(h,0);
    }
    return 0;
}