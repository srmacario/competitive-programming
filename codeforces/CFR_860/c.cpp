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
const int N = 1e3+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll cur_div = 1;
        ll d = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            ll tmp_div = a[i];
            if(d == -1){
                ans++;
                d = b[i];
                cur_div = tmp_div;
            }
            else{
                ll mdc = __gcd(d, 1ll * b[i]);
                ll check_left = b[i] / mdc;
                ll check_cur = d / mdc;
                if((!(a[i] % check_cur)) and (!(cur_div % check_left))){
                    d *= check_left;
                    a[i] /= check_cur;
                    cur_div /= check_left;
                    cur_div = __gcd(cur_div, a[i]);
                }
                else{
                    ans++;
                    d = b[i];
                    cur_div = tmp_div;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}