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
const int N = 105;

int adj[N][N], n, m, a, b, r, vis[N][N];
set<int> par[N][N];
set<pii> ans;

void floyd_warshall(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == k or j == k or i == j) continue;
                if(adj[i][k] + adj[k][j] <= adj[i][j]){
                    if(adj[i][k] + adj[k][j] < adj[i][j]) par[i][j].clear();
                    adj[i][j] = adj[i][k] + adj[k][j];
                    par[i][j].insert(k);
                }
            }
        }
    } 
}

void go(int i, int j){
    vis[i][j] = 1;
    for(auto p : par[i][j]){
        if(p == i) ans.insert({min(i, j), max(i, j)});
        else{
            if(!vis[i][p]) go(i, p);
            if(!vis[p][j]) go(p, j);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(adj, 63, sizeof(adj));
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; i++){
        int u, v, d;
        cin >> u >> v >> d;
        adj[u][v] = adj[v][u] = d;
        r += d;
        par[u][v].insert(u);
        par[v][u].insert(v);
    }
    floyd_warshall();
    go(a, b);
    for(auto a : ans) r -= adj[a.st][a.nd];
    cout << r << "\n";
    return 0;
}