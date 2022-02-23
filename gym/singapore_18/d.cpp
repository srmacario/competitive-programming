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
const int N = 5e5+5;

int n, m, cnt, color[N];
bool ok = true;
vi adj[N];

bool dfs(int u, int c){
    color[u] = c;
    bool ok = true;
    for(auto v : adj[u]){
        if(color[v] == -1){
            ok &= dfs(v, c ^ 1);
        }
        else if(color[v] == c) ok = false;
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(color, -1, sizeof(color));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            ++cnt;
            ok &= dfs(i, 0);
        }
    }
    if(ok) cout << cnt << "\n";
    else cout << cnt - 1 << "\n";
    return 0;
}