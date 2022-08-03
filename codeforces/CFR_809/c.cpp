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
        vector<ll> b(n + 5);
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        ll ans = 0;
        if(n%2){
            for(int i = 2; i <= n ; i += 2){
                if(b[i] <= b[i - 1] or b[i] <= b[i + 1]){
                    ll nxt = max(b[i + 1], b[i - 1]) + 1;
                    ans += nxt - b[i];
                }
            }
        }
        else{
            ans = LINF;
            vector<pll> dp(n + 5);
            for(int i = n - 1; i > 1; i--){
                ll inc = 0;
                if(b[i] <= b[i - 1] or b[i] <= b[i + 1]){
                    ll nxt = max(b[i + 1], b[i - 1]) + 1;
                    inc = nxt - b[i];
                }
                pll nxt = dp[i + 2];
                nxt.st++, nxt.nd -= inc;

                pll nxt_2 = dp[i + 3];
                nxt_2.st++, nxt_2.nd -= inc;

                dp[i] = max(nxt, nxt_2);
            }
            // db(dp[2].nd _ dp[3].nd);
            ans = min(-dp[2].nd, -dp[3].nd);
        }
        cout << ans << "\n";
    }
    return 0;
}