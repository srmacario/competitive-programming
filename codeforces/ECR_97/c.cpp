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
const int N = 1005;

int dp[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vi t(n);
        for(int i=0;i<n;i++){
            cin >> t[i];
        }
        sort(t.begin(), t.end());
        memset(dp,63,sizeof(dp));
        dp[1][0] = 0;
        for(int i=1;i<=2*n;i++){
            //for each time define dp putting or not jth dish
            for(int j=0;j<=n;j++){
                //for each dish j verify ans for:
                // dp[next time][next dish] = using dish j at time i
                // dp[next time][same dish] = not using dish j at time i
                // if j==n there is no next dish
                if(j!=n) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + abs(i - t[j]));
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
        cout << dp[2*n+1][n] << "\n";
    }
    return 0;
}