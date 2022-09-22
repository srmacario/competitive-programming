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

int dp[N], vis[N];
vector<int> adj[N];

void dfs(int u){
    vis[u] = 1;
    int sum = 0;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
            sum += dp[v];
        }
    }
    if(!sum) dp[u] = 1;
    else dp[u] = sum - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if(dp[1] == 0) cout << "Bob\n";
    else cout << "Alice\n";
    return 0;
}