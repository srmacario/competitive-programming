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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int mn = INF, mx = -INF;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if(i) ans += abs(a[i] - a[i - 1]);
        }
        // db(mn _ ans);
        if(mn > 1){
            ans += mn - 2;
            ans += min({abs(a[0] - mn + 1), abs(a[0] - 1), abs(a.back() - 1), abs(a.back() - mn + 1),
                        abs(mn - 1) + 1, abs(mx - mn + 1) + abs(mx - 1)});
        }
        // db(ans);
        if(mx < x){
            ans += x - mx - 1;
            // db(ans);
            ans += min({abs(a[0] - mx - 1), abs(a[0] - x), abs(a.back() - mx - 1), abs(a.back() - x),
                        abs(x - mx) + 1, abs(mx + 1 - mn) + abs(x - mn)});
            // db(ans);
        }
        cout << ans << "\n";
    }
    return 0;
}