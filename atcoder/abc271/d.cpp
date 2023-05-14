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
const int N = 2e4 + 5;

int a[2][N];
int dp[105][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[1][i] >> a[0][i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            if(dp[i - 1][j] != -1){
                dp[i][j + a[0][i]] = 0;
                dp[i][j + a[1][i]] = 1;
            }
        }
    }
    if(dp[n][s] != -1){
        cout << "Yes\n";
        vector<int> ans(n + 1);
        for(int i = n; i >= 1; i--){
            // db(dp[i][s].nd);
            ans[i] = dp[i][s];
            s -= a[dp[i][s]][i];
        }
        for(int i = 1; i <= n; i++){
            if(ans[i] == 0) cout << "T";
            else cout << "H";
        }
        cout << "\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}