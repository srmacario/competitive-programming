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
const int N = 1e3+5;

int n, m, vis[N][N];
string grid[N];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(int x, int y){
    if(vis[x][y]) return vis[x][y];
    int lp = 0;
    for(int i = 0; i < 8; i++){
        if(x + dx[i] < n and x + dx[i] >= 0 and y + dy[i] < m and y + dy[i] >= 0 and grid[x + dx[i]][y + dy[i]] == grid[x][y] + 1){
            lp = max(lp, dfs(x + dx[i], y + dy[i]));
        }
    }
    return vis[x][y] = ++lp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(dfs(i, j), ans);
        }
    }
    cout << ans << "\n";
    return 0;
}