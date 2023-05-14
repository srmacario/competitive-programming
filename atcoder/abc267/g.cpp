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
const int N = 5e3+5;

int n, k, a[N], eq;
ll dp[N][N], fat[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fat[0] = 1;
    for(int i = 1; i < N; i++) fat[i] = (i * fat[i - 1]) % MOD;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a, a + n + 1);
    a[0] = a[1];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] != a[i - 1]) eq = 1;
        else eq++;
        for(int j = 0; j + eq <= i; j++){
            // db(dp[i - 1][j] _ j _ eq);
            dp[i][j] = (((dp[i - 1][j] * (j + eq)) % MOD) + dp[i][j]) % MOD;
            dp[i][j + 1] += (((dp[i - 1][j] * (i - j - eq)) % MOD) + dp[i][j + 1]) % MOD;
            // db(dp[i][j] _ dp[i][j + 1]);
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}