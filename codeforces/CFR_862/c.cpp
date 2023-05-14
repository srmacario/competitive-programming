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
        int n, m;
        cin >> n >> m;
        vector<ll> l(n);
        for(int i = 0; i < n; i++){
            cin >> l[i];
        }
        sort(l.begin(), l.end());
        for(int i = 0; i < m; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            if(c <= 0){
                cout << "NO\n";
                continue;
            }
            auto it = lower_bound(l.begin(), l.end(), b);
            if(it != l.end() and (b - (*it)) * (b - (*it)) < 4 * a * c){
                cout << "YES\n";
                cout << (*it) << "\n";
                continue;
            }
            if(it != l.begin()){
                it--;
                if((b - (*it)) * (b - (*it)) < 4 * a * c){
                    cout << "YES\n";
                    cout << (*it) << "\n";
                    continue;
                }
            }
            cout << "NO\n";
        }
        cout << "\n";
    }
    return 0;
}