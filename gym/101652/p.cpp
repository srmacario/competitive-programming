#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll div_trick(ll n){
    ll ans = 0;
    for(ll l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        // n / i has the same value for l <= i <= r
        ans += (n / l) * (((r + l) * (r - l + 1)) / 2);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll a, b;
    cin >> a >> b;
    cout << (div_trick(b) - div_trick(a - 1)) << "\n";

    return 0;
}