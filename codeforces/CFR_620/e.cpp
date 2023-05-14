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
const int N = 1e5+5;
const int K = 20;
const int M = K+5;

vi adj[N];
int vis[N], h[N], anc[N][M], n, q;

void dfs(int u){
    vis[u] = 1;
    for(auto v: adj[u]) if(!vis[v]){
        h[v] = h[u] + 1;
        anc[v][0] = u;
        dfs(v);
    }
}

void build(){
    anc[1][0] = 1;
    dfs(1);
    for(int j = 1; j<= K; j++) for(int i=1;i<=n;i++)
        anc[i][j] = anc[anc[i][j-1]][j-1];
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    for(int j = 20; j >= 0; j--) if (h[anc[u][j]] >= h[v]) u  = anc[u][j];
    if(u==v) return u;
    for(int j = 20; j >= 0; j--) if(anc[u][j] != anc[v][j]) u = anc[u][j], v = anc[v][j];
    return anc[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    cin >> q;
    build();
    while(q--){
        bool sw = false;
        int x, y, a, b, k, dist1 = 0, dist2 = 0, dist3 = 0;
        cin >> x >> y >> a >> b >> k;
        dist1 = h[a] + h[b] - 2*h[lca(a,b)];
        //cout << "distnow: " << dist2 << "\n";
        //if(!sw){
        //    d1 = h[y] + h[a] - 2*h[lca(y,a)];
        //    d2 = h[y] + h[b] - 2*h[lca(y,b)];
        //    if(d2 > d1) swap(a,b), sw =true;
        //}
        //cout << "distnow: " << dist2 << "\n";
        dist2 = h[x] + h[a] - 2*h[lca(x,a)] + h[y] + h[b] - 2*h[lca(y,b)] + 1;
        dist3 = h[x] + h[b] - 2*h[lca(x,b)] + h[y] + h[a] - 2*h[lca(y,a)] + 1;
        if(((k%2) == (dist1%2) and k>=dist1) or ((k%2) == (dist2%2) and k>=dist2) or ((k%2) == (dist3%2) and k>=dist3)) cout << "YES\n";
        else cout << "NO\n";
        //cout << "dist1: " << dist1 << " dist 2:" << dist2 << "\n" << " dist 3: " << dist3 << "\n";
    }
    return 0;
}