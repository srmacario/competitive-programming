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
const int N = 1e5+5;

map<int,int> adj[N];
map<pii,int> cnt;
vi edges[N];
int vis[N],n,g;

bool dfs(int u, int p){
    bool ok = false;
    if(u == g) ok = true;
    //stop condition, if already passed u coming from p, cycle completed
    if(cnt[{u,p}]++ or cnt[{p,u}]++){
        return (ok);
        //else return true;
    }
    //if u it's endpoint means this cycle doesn't need post
    int nxt = adj[u][p];
    //go to next
    bool ok_nxt = dfs(nxt, u);
    return (ok_nxt or ok);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> g;
        for(int i=1;i<=n;i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            //every node has a map, adj[i][p] = u means if comes from p, goes to u
            adj[i][a] = c;
            adj[i][b] = d;
            adj[i][c] = a;
            adj[i][d] = b;
            //edges just nominate which edges it has
            edges[i].pb(a);
            edges[i].pb(b);
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(i == g) continue;
            for(int j=0;j<=1;j++){
                // for each node iterate through possible edges to see where it goes  
                int nxt = edges[i][j];
                if(!cnt[{i,nxt}]) ans += 1^dfs(nxt,i);
            }
        }
        for(int i=1;i<=n;i++) adj[i].clear(), vis[i] = 0, edges[i].clear();
        cnt.clear();
        cout << ans << "\n";
    }
    return 0;
}