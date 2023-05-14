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
const int N = 1e6+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll l = 1, r = N;
    while(l < r){
        ll mid = (l + r)/2;
        if(mid * mid >= m) r = mid;
        else l = mid + 1;
    }
    if(l > n){
        cout << "-1\n";
    }
    else{
        ll ans = l * l;
        for(ll c = 0; c < l; c++){
            ll kx = (m - 1) / (l - c) + 1;
            if(kx <= n) ans = min(ans, kx * (l - c));
        }
        cout << ans << "\n";
    }
    return 0;
}