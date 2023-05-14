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
    int t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        vector<ll> x(n + 5), ss(n + 5);
        ll pos = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++) cin >> x[i];
        for(int i = n; i >= 1; i--) ss[i] = ss[i + 1] + x[i];
        for(int i = 1; i <= n; i++){
            ans += b * (x[i] - pos);
            ll cost_chn = b * (ss[i + 1] - (n - i) * pos);
            ll cost_jump = b * (ss[i + 1] - (n - i) * x[i]) + a * (x[i] - pos);
            ll dif = b * ((n - i) * (x[i] - pos)) - a * (x[i] - pos);
            if(i < n and dif >= 0) ans += a * (x[i] - pos), pos = x[i];
        }
        cout << ans << "\n";
    }
    return 0;
}