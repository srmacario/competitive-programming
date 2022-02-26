#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

map<ll, int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int op, k;
        ll x;
        cin >> op >> x;
        if(op == 1){
            m[x]++;
        }
        if(op == 3){
            cin >> k;
            ll ans = -1;
            auto it = m.lower_bound(x);
            for(auto j = it; j != m.end(); j++){
                if(j -> nd < k) k -= j -> nd;
                else{
                    k = 0, ans = j -> st;
                    break;
                }
            }
            cout << ans << "\n";
        }
        if(op == 2){
            cin >> k;
            ll ans = -1;
            auto it = m.upper_bound(x);
            if(it == m.begin()){
                if(it -> st == x and it -> nd >= k){
                    cout << x << "\n";
                }
            }
            else{
                it--;
                for(auto j = it; j != m.begin(); j--){
                    if(j -> nd < k) k -= j -> nd;
                    else{
                        k = 0, ans = j -> st;
                        break;
                    }
                }
                if(k and m.begin() -> nd >= k) k = 0, ans = m.begin() -> st;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}