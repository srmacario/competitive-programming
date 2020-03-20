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

int n, m, dp[N];
vi adj[N];

void dfs(int u){
    if(!adj[u].size()){
        dp[u] = 1;
        return;
    }
    for(auto v : adj[u]){
        if(dp[v] == -1){
            dfs(v);
        }
    }
    for(auto v: adj[u]){
        dp[u] = max(dp[u],dp[v]+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i=1;i<=n;i++){
        if(dp[i] == -1) dfs(i);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans  = max(ans,dp[i]);
    }
    cout << ans - 1 << "\n";
    return 0;
}