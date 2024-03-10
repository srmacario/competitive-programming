#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'
#define int long long

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

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), ps(n + 1), div;
        ll xmax = -INF, xmin = INF;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            xmax = max(xmax, ll(a[i]));
            xmin = min(xmin, ll(a[i]));
            ps[i + 1] = ps[i] + a[i];
        }
        for(int i = 2; i * i <= n; i++){
            if(!(n % i)){
                div.push_back(i);
                if(i != n/i) div.push_back(n / i);
            }
        }
        
        for(auto k : div){
            vector<int> g(k), mx_right(k + 1), mn_right(k + 1);
            ll mn_left = INF, mx_left = -INF;
            for(int i = 0; i < n; i++) g[i % k] += a[i];
            ll tmp_max = INF, tmp_min = -INF;
            for(int i = 0; i < k; i++){
                tmp_max = max(tmp_max, 1ll * g[i]);
                tmp_min = min(tmp_min, 1ll * g[i]);
            }
            if(tmp_max * xmin < tmp_min * xmax) xmax = tmp_max, xmin = tmp_min;
            for(int i = 0; i < n; i++){
                ll ans_max = INF, ans_min = -INF;
                if(!(i % k)){
                    mn_left = INF, mx_left = -INF;
                    mx_right.clear(), mn_right.clear();
                    mx_right.resize(k + 1), mn_right.resize(k + 1);
                    mx_right[k] = -INF, mn_right[k] = INF;
                    for(int j = k - 1; j > 0; j--){
                        mx_right[j] = max(mx_right[j + 1], g[j]);
                        mn_right[j] = min(mn_right[j + 1], g[j]);
                    }
                }
                if(i == 0) continue;
                g[i % k] += (a[0] - a[i]);
                g[(i - 1) % k] += (a[i] - a[0]);
                ans_max = max({mx_right[(i % k) + 1], 1ll * g[i % k], mx_left});
                ans_min = min({mn_right[(i % k) + 1], 1ll * g[i % k], mn_left});
                mn_left = min(mn_left, g[(i - 1) % k]);
                mx_left = max(mx_left, g[(i - 1) % k]);
                if(ans_max * xmin < ans_min * xmax) xmax = ans_max, xmin = ans_min;
            }
        }
        cout << xmax / __gcd(xmax, xmin) << " " << xmin / __gcd(xmax, xmin) << "\n";
    }
    return 0;
}