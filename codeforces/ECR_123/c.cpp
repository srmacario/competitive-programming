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
    while(t --){
        int n, x, sum;
        cin >> n >> x;
        vi a(n + 5), pos;
        vector<vector<int>> dp;
        dp.resize(n + 5);
        dp[0].resize(n + 5);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i].resize(n + 5);
        }
        for(int i = 0; i < dp.size(); i++) for(int j = 0; j < dp[i].size(); j++) dp[i][j] = -INF;
        for(int j = 1; j <= n; j++) dp[j][0] = a[j], dp[j][1] = a[j] + x, dp[0][j] = 0;
        dp[0][0] = 0;
        vector<int> ans(n + 5);    
        for(int j = 0; j <= n; j++){
            for(int i = 1; i <= n; i++){
                //db(dp[i - 1][j] _ dp[i - 1][j - 1]);
                dp[i][j] = max({dp[i][j], dp[i - 1][j] + a[i]});
                if(j) dp[i][j] = max({dp[i][j], dp[i - 1][j - 1] + a[i] + x});
                // cout << dp[i][j] << " ";
            }
            // cout  << "\n";
            for(int i = 1; i <= n; i++) ans[j] = max(ans[j], dp[i][j]);
            for(int i = 0; i < j; i++) ans[j] = max(ans[j], ans[i]);
            cout << ans[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}