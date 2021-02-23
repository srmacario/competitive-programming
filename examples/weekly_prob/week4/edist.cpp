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
const int N = 2e3+5;

string a,b;
int dp[N][N], n, m;

int calc(int n, int m){
    if(~dp[n][m]) return dp[n][m];
    if(n == 0 or m == 0) return dp[n][m] = max(n,m);
    if(a[n-1] == b[m-1]) return dp[n][m] = calc(n-1,m-1);
    return dp[n][m] = 1 + min({calc(n-1,m),calc(n,m-1),calc(n-1,m-1)});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(dp,-1,sizeof(dp));
        n = a.size(), m = b.size();
        cout << calc(n,m) << "\n";
    }
    return 0;
}