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
const int N = 1e3+5;

int dp[N][N];
int n, k;

int calc(int i, int j){
    // db(i _ j _ dir);
    if(j <= 0) return 0;
    if(i <= 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (calc(i - 1, j) + calc(n - i, j - 1))%MOD;
    //else return dp[i][j] = (calc(i - 1, j, 0) + calc(n - i, j - 1, 1))%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin >> n >> k;
        cout << calc(n, k) << "\n";
    }
    return 0;
}