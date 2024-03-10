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
const int N = 1e5+5;

int n, p[N], dp[N], vis[N], v[N], ans[N], lis;
vector<int> adj[N];

void dfs(int u){
    vis[u] = 1;

    //do lis saving previous state
    int pos = lower_bound(dp, dp + lis, v[u]) - dp;
    int old_dp = dp[pos], old_lis = lis;
    dp[pos] = min(dp[pos], v[u]);
    lis = max(lis, pos + 1);
    ans[u] = lis;

    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    //rollback
    dp[pos] = old_dp, lis = old_lis;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 63, sizeof(dp));
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> v[i];
    dfs(1);
    for(int i = 2; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}