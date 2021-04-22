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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        int n, m, p;
        cin >> m;
        set <int> num;
        for(int i = 0; i < m; i++){
            cin >> p >> n;
            for(int j = 0; j < n; j++) num.insert(p);
        }
        vii comb;
        for(auto x : num){
            vi cur;
            cur.pb(x);
            comb.pb(cur);
            // db(x);
            vii tmp;
            for(auto v : comb){
                tmp.pb(v);
                tmp.back().pb(x);
            }
            for(auto v : tmp) comb.pb(v);
        }
        cout << "combs: ";
        for(auto v : comb){
            for(auto x : v){
                cout << x << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        cout << "Case #" << k << ": " << "\n";
    }
    return 0;
}