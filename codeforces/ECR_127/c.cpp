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
const int INF = 1e9 + 5, MOD = 1e9+7;
const int N = 2e5+5;

ll ps[N], v[N], n, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n >> x;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        sort(v + 1, v + 1 + n);
        int last = 0;
        for(int i = 1; i <= n; i++){
            ps[i] = ps[i - 1] + v[i];
            if(ps[i] <= x) last = i;
        }
        for(int i = last; i >= 1; i--){
            ll l = 0, r = INF;
            while(l < r){
                ll mid = (l + r)/2;
                if(ps[i] + i * mid <= x) l = mid + 1;
                else r = mid;
            }
            ans += l;
        }
        cout << ans << "\n";
    }
    return 0;
}