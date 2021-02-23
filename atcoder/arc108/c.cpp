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
const int N = 1e5+5;

vector <piii> edges;
vector <pii> adj[N];

int par[N], sz[N], vis[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

void dfs(int u){
    for(auto v: adj[u]){
        if(!vis[v.nd]){
            if(vis[u] == v.st) vis[v.nd] = (v.st == 1 ? 2 : 1);
            else{
                vis[v.nd] = v.st;
            }
            dfs(v.nd);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin  >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        edges.pb({c,{u,v}});
    }
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for(auto e : edges){
        if(find(e.nd.st) != find(e.nd.nd)){
            adj[e.nd.st].pb({e.st,e.nd.nd});
            adj[e.nd.nd].pb({e.st,e.nd.st});
            unite(e.nd.st, e.nd.nd); 
        }
    }
    vis[1] = 1;
    dfs(1);
    for(int i=1;i<=n;i++) cout << vis[i] << "\n";
    return 0;
}