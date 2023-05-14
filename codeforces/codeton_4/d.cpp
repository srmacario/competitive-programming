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
        int q;
        cin >> q;
        ll l = 1, r = LINF;
        for(int i = 0; i < q; i++){
            ll op, a, b, n;
            cin >> op >> a >> b;
            if(op == 1){
                cin >> n;
                ll mn = (n - 1) * a - max(0ll, (n - 2)) * b + 1;
                ll mx = n * a - (n - 1) * b;
                if(mn > r or mx < l){
                    cout << 0 << " ";
                }
                else{
                    l = max(l, mn);
                    r = min(r, mx);
                    cout << 1 << " ";
                }
            }
            else{
                if(r <= a){
                    cout << 1 << " ";
                    continue;
                }
                ll min_n_r = (r - a - 1) / (a - b) + 1;
                if(l - min_n_r * (a - b) > b){
                    cout << min_n_r + 1 << " ";
                }
                else cout << -1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

