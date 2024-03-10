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
    int n;
    cin >> n;
    string s[2];
    ll h[2][3] = {0};
    ll ans = LINF;
    cin >> s[0] >> s[1];
    for(int pos = 0; pos < 3; pos++){
        for(int k = 0; k < 2; k++){
            int cur = pos;
            for(int i = n - 1; i >= 0; i--){
                set<int> able = {0, 1, 2};
                if((s[k][i] - 'A') != cur){
                    h[k][pos]++;
                    if(!i) break;
                    h[k][pos] += (1ll << (i - 1));
                    able.erase(s[k][i] - 'A'), able.erase(cur);
                    cur = *(able.begin());
                }
            }
        }
        db(h[0][pos] _ h[1][pos]);
        ans = min(ans, h[0][pos] + h[1][pos]);
    }
    cout << ans << "\n";
    return 0;
}