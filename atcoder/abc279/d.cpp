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
const ll T = 1e18;

ll a, b;

ld f(ll t){
    return ((ld)b * t + (ld) a / sqrt((ld)t + 1.0));
}

ld ternary_search(ll l, ll r){
    while(r - l > 5) {
        ll m1 = (l+r)/2;
        ll m2 = (l+r)/2 + 1;
        ld f1 = f(m1), f2 = f(m2);   
        if(f1 > f2) l = m1;
        //if (f1 < f2) l = m1;
        else r = m2;
    }
    ld ans = LINF;
    for(ll i = l; i <= r; i++){
        ld tmp = f(i);
        ans = min(ans, tmp);
        //ans = max(ans, tmp);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    ld t = ternary_search(0, T);
    // for(int i = 20; i <= 50; i++) cout << f(i) << "\n";
    cout << setprecision(15) << fixed << t << "\n";
    return 0;
}