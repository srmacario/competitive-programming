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
const int N = 2e3+5;

vi adj[N];
int vis[N];

bool dfs(int s, int b){
    //-1 nao visitado
    //0 visitado com bit 0
    //1 visitado com bit 1
    vis[s] = b;
    for(auto v : adj[s]){
        if(vis[v] != -1){
            if(vis[v] == b){
                return false;
            }
        }
        else{
            bool x = dfs(v, b^1);
            if(!x) return false;
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) vis[i] = -1, adj[i].clear();
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(vis[i] == -1) ans &= dfs(i,0); 
        }
        printf("Scenario #%d:\n", k);
        printf("%s ", (ans ? "No suspicious": "Suspicious"));
        printf("bugs found!\n");
    }
    return 0;
}