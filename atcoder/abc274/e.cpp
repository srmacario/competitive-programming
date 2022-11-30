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

int n, m;
ll x[2][20], y[2][20];
//dp[cities_mask][chests_mask][type][pos]
int vis[(1 << 13)][(1 << 6)][2][13];
ld dp[(1 << 13)][(1 << 6)][2][13];

ld calc(int cities, int chests, int type, int pos){
    if(vis[cities][chests][type][pos]) return dp[cities][chests][type][pos];
    vis[cities][chests][type][pos] = 1;
    ld speed = (1 << __builtin_popcount(chests));
    if(__builtin_popcount(cities) == n){
        ld dist = (x[0][0] - x[type][pos]) * (x[0][0] - x[type][pos]) + (y[0][0] - y[type][pos]) * (y[0][0] - y[type][pos]);
        dist = sqrt(dist);
        dp[cities][chests][type][pos] = min(dp[cities][chests][type][pos], dist / speed);
    }
    // if(!cities and !chests and !type and !pos) db(dp[cities][chests][type][pos]);
    for(int i = n; i > 0; i--){
        if(!((1 << i) & cities)){
            ld dist = (x[0][i] - x[type][pos]) * (x[0][i] - x[type][pos]) + (y[0][i] - y[type][pos]) * (y[0][i] - y[type][pos]);
            dist = sqrt(dist);
            dp[cities][chests][type][pos] = min(dp[cities][chests][type][pos], calc(cities | (1 << i), chests, 0, i) + dist/speed);
            // if(!cities and !chests and !type and !pos) db(1 _ 0 _ dp[cities][chests][type][pos]);
        }
    }
    for(int i = m - 1; i >= 0; i--){
        if(!((1 << i) & chests)){
            ld dist = (x[1][i] - x[type][pos]) * (x[1][i] - x[type][pos]) + (y[1][i] - y[type][pos]) * (y[1][i] - y[type][pos]);
            dist = sqrt(dist);
            dp[cities][chests][type][pos] = min(dp[cities][chests][type][pos], calc(cities, chests | (1 << i), 1, i) + dist/speed);
            // if(!cities and !chests and !type and !pos) db(1 _ i _ dp[cities][chests][type][pos]);
        }
    }
    // db(cities _ chests _ type _ pos _ dp[cities][chests][type][pos]);
    return dp[cities][chests][type][pos];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < (1 << 13); i++){
        for(int j = 0; j < (1 << 6); j++){
            for(int k = 0; k < 13; k++) dp[i][j][0][k] = dp[i][j][1][k] = LINF;
        }
    }
    cin >> n >> m;
    //city
    for(int i = 1; i <= n; i++) cin >> x[0][i] >> y[0][i];
    //chest
    for(int i = 0; i < m; i++) cin >> x[1][i] >> y[1][i];
    
    ld ans = calc(0, 0, 0, 0);
    cout << setprecision(15) << fixed << ans << "\n";
    return 0;
}