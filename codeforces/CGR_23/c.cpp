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
        ll cur_min = LINF;
        vector<ll> p(n + 1);
        vector<ll> ans(n + 1);
        set<int> useful;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
            useful.insert(i);
        }
        for(int i = n; i; i--){
            cur_min = min(cur_min, p[i]);
            if(p[i - 1] > p[i]){
                ll dif = p[i - 1] - cur_min;
                int pos = *useful.lower_bound(dif);
                ans[pos] = i;
                useful.erase(pos);
                cur_min += pos;
                cur_min = min(cur_min, p[i - 1]);
            }
        }
        for(auto u : useful) ans[u] = 1;
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}