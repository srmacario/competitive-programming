#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 105;

ll a[N][N], dp[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        //declaring and reading
        ll n,m,ans = LINF;
        cin >> n >> m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
        //saving first cell 
        ll ini = a[0][0];
        //knowing some cell will maintain its value, iterating all over possibilities  
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
           //backtracking to a[0][0] should be from this cell
           ll cur_ini = a[i][j] - i - j;
           if(cur_ini > ini) continue;
           //presetting dp and new first cell
           for(int l=0;l<n;l++) for(int r=0;r<m;r++) dp[l][r] = LINF;
           dp[0][0] = ini - cur_ini;
           a[0][0] = cur_ini;
           //iterating all over cells and minimizing the paths
           for(int l=0;l<n;l++) for(int r=0;r<m;r++){
               ll cur = a[0][0] + l + r;
               if(cur > a[l][r]) continue;
               if(l) dp[l][r] = min(dp[l-1][r] + a[l][r] - cur, dp[l][r]);
               if(r) dp[l][r] = min(dp[l][r-1] + a[l][r] - cur, dp[l][r]);
           }
           ans = min(dp[n-1][m-1],ans);
        }
        cout << ans << "\n";
    }
    return 0;
}