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
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll dp[18];

ll cnt(ll k){
    if(k == 0) return 0;
    string sk = to_string(k);
    ll ans = 0;
    ll num_pot = 1;
    for(int i = 1; i < sk.size(); i++) num_pot *= 10;
    for(int i = 0; i < sk.size(); i++){
        int cur = (sk[i] - '0');
        ll pot = sk.size() - i;
        if(i == sk.size() - 1){
            ans += (cur >= 4);
            continue;
        }
        if(cur == 4){
            k -= cur * num_pot;
            ans += k + 1 + (cur) * dp[pot - 1];
            break;
        }
        else{
            
            if(cur < 4) ans += (cur) * dp[pot - 1];
            if(cur > 4) ans += (cur - 1) * dp[pot - 1] + num_pot;
        }
        k -= cur * num_pot;
        num_pot /= 10;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    ll pot = 1;
    dp[1] = 1;
    for(int i = 2; i < 18; i++){
        dp[i] = 9 * dp[i - 1];
        pot *= 10;
        dp[i] += pot;
    }
    while(t--){
        ll k;
        cin >> k;
        ll l = 1, r = LINF;
        while(l < r){
            ll mid = (l + r)/2;
            if(mid - cnt(mid) >= k)r = mid;
            else l = mid + 1;
        }
        cout << l << "\n";
    }
    return 0;
}