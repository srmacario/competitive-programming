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
const int N = 2e5+5;

vi adj[N];
int vis[N], l[N], r[N], cnt;

void dfs(int u){
    vis[u] = 1;
    int old_cnt = cnt;
    for(auto v : adj[u]){
        if(!vis[v]) dfs(v);
    }
    if(adj[u].size() == 1 and u != 1) ++cnt;
    l[u] = old_cnt + 1, r[u] = cnt; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << "\n";
    return 0;
}