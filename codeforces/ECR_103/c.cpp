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

ll n, dp[N], a[N], b[N], c[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n;
        for(int i=1;i<=n;i++) cin >> c[i];
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];
        for(int i=1;i<=n;i++){
            if(i == 1){
                dp[i] = 0;
                continue;
            }
            if(i == 2){
                dp[i] = c[i] + abs(a[i]-b[i]) + 1;
                continue;
            }
            if(a[i] == b[i]){
                dp[i] = c[i] + 1;
                continue;
            }
            dp[i] = max(c[i] + abs(a[i]-b[i]) + 1, c[i] + dp[i-1] - abs(a[i]-b[i]) + 1);
        }
        for(int i=1;i<=n;i++) ans = max(ans,dp[i]);
        cout << ans << "\n";
    }
    return 0;
}