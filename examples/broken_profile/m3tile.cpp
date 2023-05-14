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
const int N = 35;

int n,m = 3;

ll dp[N][N][N];

ll go(int i, int j, ll b){
    if(j == n) return 1;
    if(i == m) return go(0,j+1,b);
    if(~dp[i][j][b]) return dp[i][j][b];

    if(b & 1ll<<i) return go(i+1,j,(b & ~(1ll<<i)));
    ll res = 0;
    if(j < n-1) res += go(i+1,j,b | 1ll<<i);
    if(i < m-1 and !(b & 1ll<<i+1)) res += go(i+1,j,b | 1ll<<i+1);
    return dp[i][j][b] = res; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> n;
        if(n == -1) break;
        memset(dp,-1,sizeof(dp));
        cout << go(0,0,0) << "\n";
    }
    return 0;
}