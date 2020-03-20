#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;
const int L = 155;

ld ans, v[N], dp[N];
int n, limit, w[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cl(w,0); cl(v,0); cl(dp,0);
        dp[0] = 1;
        cin >> n;
        for(int i=0;i<n;i++){
            ld x;
            cin >> w[i] >> x;
            v[i] = x/100;
        }
        for(int i=0;i<n;i++){
            for(int j = L-1; j>=w[i]; j--){
                dp[j] = max(dp[j], v[i]*dp[j-w[i]]);
            }
        }
        ld ans = 0;
        for(int i=76;i<=150;i++) ans = max(ans,dp[i]);
        cout << setprecision(10) << ans*100 << "\n";
    }
    return 0;
}