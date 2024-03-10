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

ll k, grid[25][25];
int n, m;

map<int, ll> top[25][25], bot[25][25];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    top[1][1][0] = 1, bot[n][m][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    
    //top down dp
    for(int i = 1; i <= n; i++){
        for(int j = 1; j + i <= n; j++){
            // db(i _ j);
            for(auto mask : top[i][j]){
                top[i + 1][j][mask.st ^ grid[i][j]] += mask.nd;
                top[i][j + 1][mask.st ^ grid[i][j]] += mask.nd;
            }
        }
    }
    //bottom up dp
    for(int i = n; i >= 1; i--){
        for(int j = m; j + i > n + 1; j--){
            // db(i _ j);
            for(auto mask : bot[i][j]){
                bot[i - 1][j][mask.st ^ grid[i][j]] += mask.nd;
                bot[i][j - 1][mask.st ^ grid[i][j]] += mask.nd;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(auto mask : top[i][n - i + 1]){
            // db(i _ n - i + 1);
            ans += mask.nd * bot[i][n - i + 1][mask.st ^ grid[i][n - i + 1] ^ k];
        }
    }
    cout << ans << "\n";
    return 0;
}