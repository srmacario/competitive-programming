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
const int N = 1e3+5;

int dp[N][N];
vi adj[N];

int calc(int x, int y){
    if(x == y) return 0;
    if(x == 1) return 1;
    if(~dp[x][y]) return dp[x][y];
    int p = 0;
    for(auto v : adj[y]){
        if(calc(min(x,v),max(x,v))){
            p = 1;
            break;
        }
    }
    return dp[x][y] = p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c,p;
    while(cin >> c >> p){
        for(int i=0;i<p;i++){
            int u,v;
            cin >> u >> v;
            adj[v].pb(u);
        }
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=2;i<=c;i++){
            for(int j=i+1;j<=c;j++){
                ans += calc(i,j);
            }
        }       
        cout << ans + c - 1 << "\n";
        for(int i=1;i<=c;i++) adj[i].clear();
    }
    return 0;
}