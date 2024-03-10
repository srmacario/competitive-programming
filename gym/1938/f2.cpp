#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'

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
        vector<int> a(n), ps(n + 1), div;
        ll xmax = INF, xmin = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ps[i + 1] = ps[i] + a[i];
        }
        for(int i = 1; i * i <= n; i++){
            if(!(n % i)){
                div.push_back(i);
                if(i != n/i) div.push_back(n / i);
            }
        }
        for(auto k : div){
            if(k == 1) continue;
            vector<int> g(k);
            set<pair<int, int>> nums;
            for(int i = 0; i < n; i++) g[i % k] += a[i];
            for(int i = 0; i < k; i++) nums.insert({g[i], i});
            ll ans_max = (*nums.rbegin()).st;
            ll ans_min = (*nums.begin()).st;
            // db(ans_max _ ans_min);
            for(int i = 1; i < n; i++){
                nums.erase({g[i % k], i % k});
                nums.erase({g[(i - 1) % k], (i - 1) % k});
                g[(i - 1) % k] += (a[i] - a[0]);
                g[i % k] += (a[0] - a[i]);
                nums.insert({g[i % k], i % k});
                nums.insert({g[(i - 1) % k], (i - 1) % k});
                ll mx = (*nums.rbegin()).st;
                ll mn = (*nums.begin()).st;
                if(mx * ans_min < ans_max * mn) ans_max = mx, ans_min = mn;
                // db(mx _ mn _ ans_max _ ans_min);
            }
            if(ans_max * xmin < ans_min * xmax) xmax = ans_max, xmin = ans_min;
        }
        cout << xmax / __gcd(xmax, xmin) << " " << xmin / __gcd(xmax, xmin) << "\n";
    }
    return 0;
}