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
const int N = 1e5+5;

int n, m, vis[N], cnt[2], marcB[N], matchB[N], matchA[N], ans, p;
map<int,int> id, revid;
vi adj[N];

// void mark(int s, int b){
//     vis[s] = b;
//     id[s] = ++cnt[b];
//     revid[id[s]] = s;
//     for(auto v: adj[s]){
//         if(vis[v] == -1) mark(v, b^1);
//     }
// }

bool dfs(int v){
    for(int i = 0; i < adj[v].size(); i++){
        int viz = adj[v][i];
        if(marcB[viz] == 1 ) continue;
        marcB[viz] = 1;

        if((matchB[viz] == -1) || dfs(matchB[viz])){
            matchB[viz] = v;
            matchA[v] = viz;
            return true;
        }
    
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for(int i = 0; i <= n; i++) matchA[i] = -1;
    for(int j = 0; j <= n; j++) matchB[j] = -1;
    bool aux = true;
    while(aux){
        for(int j = 1; j <= n; j++) marcB[j] = 0;
        aux = false;
        for(int i = 1; i <= n; i++){
            if(matchA[i] != -1) continue;
            if(dfs(i)){
                ans++;
                aux = true;
            }
        }
    }
    cout << ans/2 << "\n";
    return 0;
}