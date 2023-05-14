#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
ll MOD = (1ll << 31) - 1;
const int N = 1e3+5;

int n, di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};
ll dp[N][N], vis[N][N];
string grid[N];

bool check(int i, int j){
    if(i < 0 or j < 0 or i >= n or j >= n) return false;
    if(grid[i][j] == '#') return false;
    return true;
}

bool dfs(int i, int j){
    vis[i][j] = 1;
    if(i == n - 1 and j == n - 1) return true;
    for(int k = 0; k < 4; k++){
        if(check(i + di[k], j + dj[k]) and !vis[i + di[k]][j + dj[k]]){
            bool nxt = dfs(i + di[k], j + dj[k]);
            if(nxt) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> grid[i];
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 < n and grid[i][j + 1] == '.') dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % MOD;
            if(i + 1 < n and grid[i + 1][j] == '.') dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % MOD;

        }
    }
    if(!dp[n - 1][n - 1]){
        if(dfs(0, 0)) cout << "THE GAME IS A LIE\n";
        else cout << "INCONCEIVABLE\n";
    }
    else cout << dp[n - 1][n - 1] << "\n";
    return 0;
}