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
        vector<ll> a(n + 1);
        ll cnt = 0;
        vector<ll> pots;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
            while(!(a[i] % 2)){
                a[i] /= 2;
                cnt++;
            }
            ll cur = i, cur_pot = 0;
            while(!(cur % 2)){
                cur /= 2;
                cur_pot++;
            }
            if(cur_pot) pots.push_back(cur_pot);
        }
        sort(pots.begin(), pots.end());
        ll need = n - cnt;
        if(need <= 0){
            cout << "0\n";
        }
        else{
            ll ans = 0;
            while(pots.size()){
                ll cur = pots.back();
                pots.pop_back();
                need -= cur;
                ans++;
                if(need <= 0) break;
            }
            if(need <= 0) cout << ans << "\n";
            else cout << "-1\n";
        }
    }
    return 0;
}