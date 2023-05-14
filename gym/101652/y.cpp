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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ld k, p, x;
    cin >> k >> p >> x;
    // custo: K / M * (P) + M * x
    ld ans = LINF;
    ll mn = sqrt(k * p / x);
    for(int m = max(1ll, mn - 10); m <= mn + 10; m++){
        ld days = k / m;
        ans = min(days * p + m * x, ans);
    }
    cout << setprecision(3) << fixed << ans << "\n";
    return 0;
}