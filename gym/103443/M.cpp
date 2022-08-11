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
const int N = 105;

int n, m, grid[N][N], s, f, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    cin >> s >> f >> r;
    vector<pii> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] != s) continue;
            if(grid[i - 1][j] == f and grid[i][j + 1] == r) ans.push_back({i - 1, j - 1});
            else if(grid[i][j + 1] == f and grid[i + 1][j] == r) ans.push_back({i - 1, j - 1});
            else if(grid[i + 1][j] == f and grid[i][j - 1] == r) ans.push_back({i - 1, j - 1});
            else if(grid[i][j - 1] == f and grid[i - 1][j] == r) ans.push_back({i - 1, j - 1});
        }
    }
    sort(ans.begin(), ans.end());
    for(auto p : ans) cout << p.st << " " << p.nd << "\n";
    return 0;
}