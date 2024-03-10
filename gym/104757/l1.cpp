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
const int N = 3e3+5; 
 
int n, m, root;
 
pii pts[N]; 
//0: N, 1: E, 2: S, 3: W, 
vector<int> adj[N], vis[N];
int edge[N][N], want[N][N];
vector<pair<int, int>> cyc; 

bool dfs(int u, int p, int dir){
    //consume edge
    edge[min(p, adj[p][dir])][max(p, adj[p][dir])]++;
    vis[p][dir] = 1;
     
    //check possible exits
    int cnt = 0; 
    for(int i = -1; i <= 1; i++){ 
        int nxt_dir = (i + dir + 4) % 4;
        if(edge[min(u, adj[u][nxt_dir])][max(u, adj[u][nxt_dir])] == 1)
            cnt += want[min(u, adj[u][nxt_dir])][max(u, adj[u][nxt_dir])] > 1;
        else
            cnt += want[min(u, adj[u][nxt_dir])][max(u, adj[u][nxt_dir])] > 0; 
    }
    //try go mid if possible
    if(cnt == 3){
        //add vertex to cycle
        cyc.push_back({u, dir});
        if(vis[u][dir]) { 
            //cycle
            return true;
        }
        return dfs(adj[u][dir], u, dir); 
    }

    //no mid, so go as left as possible
    if(cnt){ 
        for(int i = -1; i <= 1; i++){ 
            int nxt_dir = (i + dir + 4) % 4;
            if(want[min(u, adj[u][nxt_dir])][max(u, adj[u][nxt_dir])]){ 
                if(edge[min(u, adj[u][nxt_dir])][max(u, adj[u][nxt_dir])] == 1 and want[min(u, adj[u][nxt_dir])][max(u, adj[u][nxt_dir])] == 1){
                    continue;
                }
                //add vertex to cycle
                cyc.push_back({u, nxt_dir});
                if(vis[u][nxt_dir]) { 
                    //cycle
                    return true;
                } 
                return dfs(adj[u][nxt_dir], u, nxt_dir); 
            } 
        }
    } 
    //no branch left
    //add vertex to cycle
    cyc.push_back({u, -1});
    return false;
}

int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    char chdir; 
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){ 
        cin >> pts[i].st >> pts[i].nd; 
        adj[i].resize(4);
        vis[i].resize(4);
    } 
    for(int i = 0; i < m; i++){ 
        int u, v, k; 
        cin >> u >> v >> k; 
 
        //u em relacao a v 
        if(pts[u].st > pts[v].st) adj[u][3] = v, adj[v][1] = u; 
        if(pts[u].st < pts[v].st) adj[v][3] = u, adj[u][1] = v; 
 
        if(pts[u].nd > pts[v].nd) adj[u][2] = v, adj[v][0] = u; 
        if(pts[u].nd < pts[v].nd) adj[v][2] = u, adj[u][0] = v; 
        want[u][v] = want[v][u] = k;
    } 
    cin >> root >> chdir; 
    int idir; 
    if(chdir == 'N') idir = 0; 
    if(chdir == 'E') idir = 1; 
    if(chdir == 'S') idir = 2; 
    if(chdir == 'W') idir = 3;
    bool ok = true;
    while(ok) {
        if(!want[min(root, adj[root][idir])][max(root, adj[root][idir])]){
            cout << pts[root].st << " " << pts[root].nd << "\n";
            return 0;
        }
        //add start vertex to cycle
        cyc.push_back({root, idir});
        ok = dfs(adj[root][idir], root, idir);
        if(!ok){
            cout << pts[cyc.back().st].st << " " << pts[cyc.back().st].nd << "\n";
            return 0;
        }
        //clean cycle
        int count_times = INF;
        for(auto c : cyc){
            int u = c.st, dir = c.nd, v = adj[u][dir];
            count_times = min(count_times, want[min(u, v)][max(u, v)] / edge[min(u, v)][max(u, v)]);
        }
        for(int i = 0; i < (int)cyc.size() - 1; i++){
            auto c = cyc[i];
            int u = c.st, dir = c.nd, v = adj[u][dir];
            want[min(u, v)][max(u, v)] -= count_times;
        }
        for(auto c : cyc){
            int u = c.st, dir = c.nd, v = adj[u][dir];
            edge[min(u, v)][max(u, v)] = 0;
            vis[u][dir] = 0;
        }
        //new begin
        root = cyc.back().st, idir = cyc.back().nd;
        cyc.clear();
    }
    return 0; 
}