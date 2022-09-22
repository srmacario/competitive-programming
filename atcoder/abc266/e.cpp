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

ld dp[N];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        dp[i] = (1.0 / 6) * (max((ld) 1, dp[i - 1]) + max((ld) 2.0, dp[i - 1]) + max((ld) 3.0, dp[i - 1]) + max((ld) 4.0, dp[i - 1]) + max((ld) 5.0, dp[i - 1]) + max((ld) 6.0, dp[i - 1]));
    }
    cout << setprecision(15) << fixed << dp[n] << "\n";
    return 0;
}