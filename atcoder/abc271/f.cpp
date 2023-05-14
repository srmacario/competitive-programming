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

int n, a[30][30];
map<int, ll> top[30][30], bot[30][30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    top[1][1][0] = 1, bot[n][n][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    //top down dp
    for(int i = 1; i <= n; i++){
        for(int j = 1; j + i <= n; j++){
            for(auto mask : top[i][j]){
                top[i + 1][j][mask.st ^ a[i][j]] += mask.nd;
                top[i][j + 1][mask.st ^ a[i][j]] += mask.nd;
            }
        }
    }
    //bottom up dp
    for(int i = n; i >= 1; i--){
        for(int j = n; j + i > n + 1; j--){
            for(auto mask : bot[i][j]){
                bot[i - 1][j][mask.st ^ a[i][j]] += mask.nd;
                bot[i][j - 1][mask.st ^ a[i][j]] += mask.nd;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(auto mask : top[i][n - i + 1]){
            ans += mask.nd * bot[i][n - i + 1][mask.st ^ a[i][n - i + 1]];
        }
    }
    cout << ans << "\n";
    return 0;
}