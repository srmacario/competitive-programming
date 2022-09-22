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
const int N = 2e3+5;

int n, m;
ll dp[N][N], a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 63, sizeof(dp));

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int j = 1; j <= n; j++){
        dp[1][j] = a[j];
    }
    //pos

    ll ans = -LINF;
    for(int i = 2; i <= m; i++){
        ll max_cur = dp[i - 1][i - 1];
        for(int j = i; j <= n; j++){
            dp[i][j] = max_cur + 1ll * i * a[j];
            max_cur = max(max_cur, dp[i - 1][j]);
            if(i == m) ans = max(ans, dp[i][j]);
        }
    }
    // for(int i = 1; i <= n; i++) ans = max(ans, calc(1, i));

    cout << ans << "\n";
    return 0;
}