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

int n, mx_time;
ll dp[N][10];
map<int, int> x[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int xx, tt, aa;
        cin >> tt >> xx >> aa;
        x[xx][tt] = aa;
        mx_time = max(mx_time, tt);
    }
    for(int i = 0; i < mx_time; i++){
        for(int j = 0; j <= min(4, i); j++){
            if(j){
                if(x[j - 1].count(i + 1))
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + x[j - 1][i + 1]);
                else
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j]);
            }
            if(j < 5){
                if(x[j + 1].count(i + 1))
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + x[j + 1][i + 1]);
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            }
            if(x[j].count(i + 1))
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x[j][i + 1]);
            else
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < 5; i++){
        ans = max(dp[mx_time][i], ans);
    }
    cout << ans << "\n";
    return 0;
}