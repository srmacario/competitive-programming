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
const int N = 1e5+5, M = (1 << 15);

int n, m;
vector<pair<int, int>> edges;
ll dp[M][15];

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

int edge(int mask){
    int ans = 0;
    for(auto e : edges){
        if(((1 << (e.st - 1)) & mask) and ((1 << (e.nd - 1)) & mask)) ans++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    for(int mask = 1; mask < (1 << n); mask++){
        int pos = __builtin_ffs(mask) - 1;
        for(int i = 2; i <= __builtin_popcount(mask); i++){
            for(int sub = mask; sub; sub = (sub - 1) & mask){
                if(sub & (1 << pos)){
                    dp[mask][i] = (dp[mask][i] + dp[sub][1] * dp[mask ^ sub][i - 1] % MOD) % MOD;
                }
            }
        }
        dp[mask][1] = fexp(2, edge(mask));
        for(int i = 2; i <= __builtin_popcount(mask); i++) dp[mask][1] = (dp[mask][1] - dp[mask][i] + MOD) % MOD;
    }
    for(int i = 1; i <= n; i++) cout << dp[(1 << n) - 1][i] << "\n";
    return 0;
}