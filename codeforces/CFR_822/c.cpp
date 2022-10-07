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
const int N = 1e6+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<vector<int>> mult(n + 1);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(!(s[i] - '0')){
                int tmp = INF;
                mult[i + 1].push_back(i + 1);
                for(int j = 0; j < mult[i + 1].size(); j++){
                    if(i + 1 + mult[i + 1][j] <= n) mult[i + 1 + mult[i + 1][j]].push_back(mult[i + 1][j]);
                    tmp = min(tmp, mult[i + 1][j]);
                }
                ans += tmp;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}