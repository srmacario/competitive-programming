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

int c[N], vis[N], n, m, mx;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

vi adj[N];
set<pii> memo;

void dfs(int s, int mdc){
    if(memo.count({s, mdc})) return;
    memo.insert({s, mdc});
    vis[mdc] = 1;
    for(auto v : adj[s]){
        dfs(v, gcd(mdc, c[v]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
       cin >> c[i];
       mx = max(mx, c[i]);
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        int mdc = gcd(c[u], c[v]);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    //start a dfs with a source at each node
    for(int i = 1; i <= n; i++) dfs(i, c[i]);

    //after all dfs with all possible paths (starting in a source) are calc, verify if for some i we could reach it as a gcd
    for(int i = 1; i < N; i++) if(vis[i]) ans++;
    
    cout << ans << "\n";
    return 0;
}