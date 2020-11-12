#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 5e3+5;

int ans[N], b[N], n, m, n1, n2, n3, comp;
int dp[N][2], memo[N][N];
vi adj[N], conn[N];

bool dfs(int s, int c, int comp){
    b[s] = c;
    dp[comp][c]++;
    conn[comp].pb(s);
    for(auto v : adj[s]){
        if(b[v] == b[s]){
            return false;
        }
        if(b[v] == -1){
            if(!dfs(v,c^1,comp)) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(b,-1,sizeof(b));
    cin >> n >> m >> n1 >> n2 >> n3;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(b[i] == -1){
            comp++;
            if(!dfs(i,1,comp)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    for(int i=1;i<=comp;i++){
        if(i == 1){
            memo[i][dp[i][0]] = 0;
            memo[i][dp[i][1]] = 1;
            continue;
        }
        for(int j=0;j<=n;j++){
            if(memo[i-1][j] != -1){
                memo[i][j + dp[i][0]] = 0;
                memo[i][j + dp[i][1]] = 1;
            }
        }
    }

    if(memo[comp][n2] == -1){
        cout << "NO\n";
        return 0;
    }
    int aux = n2, cont1 = 0;
    for(int i = comp; i>=1; i--){
        int temp = memo[i][aux];
        for(int j=0;j<conn[i].size();j++){
            if(b[conn[i][j]] == temp) ans[conn[i][j]] = 2;
            else if(cont1 < n1){
                ans[conn[i][j]] = 1;
                cont1++;
            }
            else ans[conn[i][j]] = 3;
        }
        aux -= dp[i][memo[i][aux]];
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++) cout << ans[i];
    cout << "\n";
    return 0;
}