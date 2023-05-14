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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 3e3+5;

int n, c[N], sum[N], checked[N], vis[N], sz[N], colors[N], cnt;
ll dp[N][N];
vector<int> adj[N];

void dfs_sum(int u, int root){
    vis[u]++;
    sz[u]++;
    if(c[u] == c[root]) sum[u]++, colors[u]++, dp[u][1] = 1;
    else sum[u]--;

    for(auto v : adj[u]){
        if(vis[v] != cnt){
            dfs_sum(v, root);

            sum[u] += sum[v];
            sz[u] += sz[v];
            colors[u] += colors[v];

            for(int i = min(colors[u], sz[u]); i + sum[v] >= 1 and i >= 1; i--){
                if(dp[u][i] > 0) dp[u][i + sum[v]] = (dp[u][i + sum[v]] + sum[v]) % MOD;
            }
            
            for(int i = 1; i <= min(colors[v], sz[v]); i++){
                dp[u][i] = (dp[u][i] + dp[v][i]) % MOD;

            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(checked[c[i]]) continue;

        checked[c[i]] = 1;
        cnt++;
        for(int j = 1; j <= n; j++) sum[j] = sz[j] = 0;
        dfs_sum(1, i);
        for(int j = 1; j <= sz[1]; j++) db(c[i] _ dp[1][j]);
    }
    ll ans = 0;
    for(int i = 1; i <= sz[1]; i++) ans = (ans + dp[1][i]) % MOD;
    cout << ans << "\n";
    return 0;
}