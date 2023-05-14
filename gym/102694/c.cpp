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
const int N = 3e5+5, M = 25;

int n,q;
vi adj[N];
int vis[N], h[N], anc[M][N];

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]) if(!vis[v]){
        h[v] = h[u] + 1;
        anc[0][v] = u;
        dfs(v);
    }
}

void lift(){
    anc[0][1] = 1;
    dfs(1);
    for(int i = 1; i <= 20;i++)
        for(int j = 1; j <= n; j++)
            anc[i][j] = anc[i-1][anc[i-1][j]];
}

int lca (int u, int v){
    if (h[u] < h[v]) swap(u,v);
    for(int i = M-1; i >= 0; i--)
        if(h[anc[i][u]] >= h[v])
            u = anc[i][u];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--)
        if(anc[i][u] != anc[i][v]){
            u = anc[i][u];
            v = anc[i][v];
        }
    return anc[0][u];
}

int dist(int u, int v){
    return h[u] + h[v] - 2*h[lca(u,v)];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> q;
    lift();
    for(int i=0;i<q;i++){
        int a,b,c;
        cin >> a >> b >> c;
        //db(dist(a,b));
        if(dist(a,b) <= c) cout << b << "\n";
        else{
            if(dist(a,lca(a,b)) > c){
                //cout << a << " " << b << "\n";
                for(int j = 20; j >= 0; j--){
                    if((1ll<<j)&c) a = anc[j][a];
                }
                cout << a << "\n";
            }
            else{
                c -= dist(a,lca(a,b));
                c = dist(b,lca(a,b)) - c;
                for(int j = 20; j >= 0; j--){
                    if((1ll<<j)&c) b = anc[j][b];
                }
                cout << b << "\n";
            }
        }
    }
    return 0;
}