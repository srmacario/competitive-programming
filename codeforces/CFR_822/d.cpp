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
        int n, k;
        cin >> n >> k;
        //{barrier, gain}
        vector<pll> a;
        vector<ll> v(n + 2);
        vector<plll> dp(n + 2);
        for(int i = 1; i <= n; i++) cin >> v[i];
        ll cur_sum = 0, cur_barrier = 0;
        int l, r;
        for(int i = k - 1; i >= 0; i--){
            cur_sum += v[i];
            cur_barrier = min(cur_barrier, cur_sum);
            if(i == 0 or cur_sum >= 0){
                if(!i) cur_sum = LINF;
                a.push_back({cur_sum, cur_barrier});
                cur_sum = cur_barrier = 0;
                continue;
            }
        }
        reverse(a.begin(), a.end());
        l = (int)a.size() - 1, r = (int)a.size();
        for(int i = k + 1; i <= n + 1; i++){
            cur_sum += v[i];
            cur_barrier = min(cur_barrier, cur_sum);
            if(i == n + 1 or cur_sum >= 0){
                if(i == n + 1) cur_sum = LINF;
                a.push_back({cur_sum, cur_barrier});
                cur_sum = cur_barrier = 0;
                continue;
            }
        }
        while(l >= 0 and r < (int)a.size()){
            if(abs(a[l].nd) <= v[k]){
                v[k] += a[l--].st;
            }
            else if(abs(a[r].nd) <= v[k]){
                v[k] += a[r++].st;
            }
            else{
                break;
            }
        }
        if(l < 0 or r == (int)a.size()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}