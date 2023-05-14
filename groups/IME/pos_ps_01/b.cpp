#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

ll a[2], b[2], l, r;

void euclid(ll a, ll b, ll &x, ll &y) {
    if (b) euclid(b, a%b, y, x), y -= x*(a/b);
    else x = 1, y = 0;
}

bool diof(ll a, ll b, ll c, ll &x, ll &y){
    euclid(abs(a), abs(b), x, y);
    ll g = abs(__gcd(a, b));
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

bool crt_auxiliar(ll a, ll b, ll m1, ll m2, ll &ans){
    ll x, y;
    if(!diof(m1, m2, b - a, x, y)) return false;
    ll lcm = m1 / __gcd(m1, m2) * m2;
    ans = ((a + x % (lcm / m1) * m1) % lcm + lcm) % lcm;
    return true;
}

bool crt(int n, ll a[], ll b[], ll &ans){
    if(!b[0]) return false;
    ans = a[0] % b[0];
    ll l = b[0];
    for(int i = 1; i < n; i++){
        if(!b[i]) return false;
        if(!crt_auxiliar(ans, a[i] % b[i], l, b[i], ans)) return false;
            l *= (b[i] / __gcd(b[i], l));
    }
    return true;
}

ll cceil(ll a, ll b) {
  ll c = abs(a);
  ll d = abs(b);
  if ((a / c) * (b / d) > 0) return (c + d - 1)/d;
  return -c/d;
}
 
ll cfloor(ll a, ll b) {
  ll c = abs(a);
  ll d = abs(b);
  if ((a / c) * (b / d) > 0) return c/d;
  return -(c + d - 1)/d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // x = a[i] * k + b[i] => x = b[i] mod a[i]
    for(int i = 0; i < 2; i++) cin >> a[i] >> b[i];
    cin >> l >> r;
    ll ans = 0;
    bool ok = crt(2, b, a, ans);
    if(!ok){
        cout << "0\n";
        return 0;
    }
    ll lcm = (a[0] * a[1]) / __gcd(a[0], a[1]);
    
    //ans + k * lcm(b[i])
    //k >= (b[i] - ans) / lcm(b[i])

    //k >= (l - ans) / lcm(b[i])
    //k <= (r - ans) / lcm(b[i])
    ll min_k[2];
    for(int i = 0; i < 2; i++) min_k[i] = cceil(b[i] - ans, lcm);
    ll min_kk = max(min_k[0], min_k[1]);
    ll lft = cceil(l - ans, lcm);
    ll rgt = cfloor(r - ans, lcm);
    lft = max(lft, min_kk);
    if(rgt < min_kk) cout << "0\n";
    else{
        cout << (rgt - lft + 1) << "\n";
    }
    return 0;
}