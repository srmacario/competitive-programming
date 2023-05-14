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
const int N = 1e5+5;

int ans, n, m, k;
ll dp[2][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++) dp[1][j] = 0;
        for(int w = 1; w <= m; w++){
            for(int j = k - w; j >= 0; j--){
                dp[1][j + w] = (dp[0][j] + dp[1][j + w])%MOD; 
            }
        }
        for(int j = 0; j <= k; j++) dp[0][j] = dp[1][j];
    }
    ll sum = 0;
    for(int i = 1; i <= k; i++) sum = (dp[0][i] + sum) % MOD;
    cout << sum << "\n";
    return 0;
}