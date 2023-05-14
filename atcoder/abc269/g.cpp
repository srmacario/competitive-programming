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
const int N = 2e5+5, M = 900;

int n, m, ans[N];
pii dp[M][N];
map<int, int> uw;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int ini = 0;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        if((b - a)){
            uw[b - a]++;
        }
        ini += a;
    }
    for(int i = 0; i <= m; i++) dp[0][i] = {-1, -1}, ans[i] = -1;
    dp[0][ini] = {0, 0}, ans[ini] = 0;
    for(int j = 0; j <= m; j++) cout << "{ " << dp[0][j].st << ", " << dp[0][j].nd << "} ";
    cout << "\n";
    int i = 1;
    for(auto p : uw){
        for(int j = 0; j <= m; j++){
            dp[i][j] = {dp[i - 1][j].st, -1};
            if(dp[i - 1][j].st >= 0) dp[i][j].nd = 0;
        }
        if(p.st > 0){
            for(int j = p.st; j <= m; j++){
                if(dp[i][j - p.st].st >= 0 and dp[i][j - p.st].nd < p.nd){
                    if(dp[i][j].st < 0 or (dp[i][j].st >= 0 and dp[i][j].nd > dp[i][j - p.st].nd + 1)){
                        dp[i][j] = dp[i][j - p.st];
                        dp[i][j].st++, dp[i][j].nd++;
                    }
                }
            }
        }
        else{
            for(int j = m + p.st; j >= p.st; j--){
                if(dp[i][j - p.st].st >= 0 and dp[i][j - p.st].nd < p.nd){
                    if(dp[i][j].st < 0 or (dp[i][j].st >= 0 and dp[i][j].nd > dp[i][j - p.st].nd + 1)){
                        dp[i][j] = dp[i][j - p.st];
                        dp[i][j].st++, dp[i][j].nd++;
                    }
                }
            }
        }
        for(int j = 0; j <= m; j++) cout << "{ " << dp[i][j].st << ", " << dp[i][j].nd << "} ";
        cout << "\n";
        i++;
    }
    for(int j = 0; j <= m; j++) cout << dp[uw.size()][j].st << "\n";
    return 0;
}