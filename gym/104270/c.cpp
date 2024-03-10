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
    int T;
    cin >> T;
    while(T--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<pii> inter;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                if(inter.empty() or inter.back().nd != i - 1)
                    inter.push_back({i, i});
                else
                    inter.back().nd = i;
            }
        }
        ll ans = 0;
        if(inter.size() == 2){
            ans = 6;
        }
        if(inter.size() == 1){
            ans = 2 * (n - 1);
        }
        if(inter.size() == 0){
            ans = (n * (n - 1)) / 2 + n;
        }
        cout << ans << "\n";
        // db(inter.size());
    }
    return 0;
}