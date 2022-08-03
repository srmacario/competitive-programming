#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, a[N], vis[N], dp[N], ans[N];
vector<int> adj[N];

void dfs(int u, int lis){
    vis[u] = 1;
    int j = lower_bound(dp, dp + lis, a[u]) - dp;
    int old = -1;
    if(a[u] < dp[j]){
        old = dp[j];
        dp[j] = a[u];
    }
    lis = max(lis, j + 1);
    ans[u] = lis;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v, lis);
        }
    }
    if(old != -1) dp[j] = old;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, 63, sizeof(dp));
    dfs(1, 0);
    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}