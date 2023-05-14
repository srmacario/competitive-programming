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
        int n;
        cin >> n;
        vector<int> p(n + 1), pos(n + 1), mx(n + 1), mn(n + 1);
        for(int i = 0; i < n; i++){
            cin >> p[i];
            pos[p[i]] = i;
        }
        p[n] = pos[n] = n;
        mx[0] = mn[0] = pos[0];
        for(int i = 1; i <= n; i++){
            mx[i] = max(mx[i - 1], pos[i]);
            mn[i] = min(mn[i - 1], pos[i]);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ll x_l = mn[i - 1], x_r = mx[i - 1];
            if(pos[i] < x_r and pos[i] > x_l){
                // db(ans);
                continue;
            }
            ll m = 2 * i;
            ll b_l, b_r;
            if(x_l > pos[i]){
                b_l = max(pos[i] + 1ll, x_l - i);
                b_r = min(n - 1ll, x_r + i);
                for(int j = b_l; j <= x_l; j++){
                    ans += max(0ll, (min(b_r, j + m - 1) - x_r + 1));
                }
            }
            else{
                b_l = max(0ll, x_l - i);
                b_r = min(pos[i] - 1ll, x_r + i);
                for(int j = b_r; j >= x_r; j--){
                    ans += max(0ll, (x_l - max(b_l, j - m + 1) + 1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}