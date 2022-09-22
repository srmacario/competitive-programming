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
const int N = 2e5+5;

int n, m;
ll ps[N], a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    ll sum = 0, ans = 0;
    for(int i = 1; i <= m; i++) sum += 1ll * i * a[i];
    ans = sum;

    for(int i = m + 1; i <= n; i++){
        sum += (1ll * m * a[i]) - (ps[i - 1] - ps[i - 1 - m]);
        ans = max(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}