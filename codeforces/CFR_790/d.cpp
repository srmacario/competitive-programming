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
const int N = 205;

int grid[N][N];
int n, m;

ll calc(int i, int j){
    ll ans = 0;
    for(int k = 1; i + k < n and j + k < m; k++) ans += grid[i + k][j + k];
    for(int k = 1; i - k >= 0 and j + k < m; k++) ans += grid[i - k][j + k];
    for(int k = 1; i  + k < n and j - k >= 0; k++) ans += grid[i + k][j - k];
    for(int k = 1; i - k >= 0 and j - k >= 0; k++) ans += grid[i - k][j - k];
    ans += grid[i][j];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, calc(i, j));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}