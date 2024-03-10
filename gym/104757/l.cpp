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
 
int n, m, root; 
char dir; 
 
pii pts[N]; 
//0: N, 1: E, 2: S, 3: W, 
vector<int> adj[N], vis[N];
int edge[N][N], want[N][N], start;
bool ok = true; 
vector<pair<int, int>> cyc; 
 
bool dfs(int u, int dir){
    edge[min(u, adj[u][dir])][max(u, adj[u][dir])]++;
    cyc.push_back({adj[u][dir], dir}); 
    vis[adj[u][dir]][dir] = cyc.size(); 
    int cnt = 0; 
    for(int i = 0; i <= 3; i++){ 
        if((i - dir + 4) % 4 == 2) continue;
        if(edge[min(u, adj[u][dir])][max(u, adj[u][dir])] == 1)
            cnt += want[min(u, adj[u][dir])][max(u, adj[u][dir])] > 1;
        else
            cnt += want[min(u, adj[u][i])][max(u, adj[u][i])] > 0; 
    } 
    if(cnt == 3){ 
        if(vis[adj[u][dir]][dir]) { 
            //cycle
            start = vis[adj[u][dir]][dir] - 1;
            return true;
        }
        return dfs(adj[u][dir], dir); 
    } 
    if(cnt){ 
        for(int i = -1; i <= 1; i++){ 
            if(want[min(u, adj[u][(dir + i + 4) % 4])][max(u, adj[u][(dir + i + 4) % 4])]){ 
                if(edge[min(u, adj[u][(dir + i + 4) % 4])][max(u, adj[u][(dir + i + 4) % 4])] == 1 and want[min(u, adj[u][(dir + i + 4) % 4])][max(u, adj[u][(dir + i + 4) % 4])] == 1){
                    continue;
                }
                if(vis[adj[u][(dir + i + 4) & 3]][dir]) { 
                    //cycle
                    start = vis[adj[u][(dir + i + 4) & 3]][dir] - 1;
                    return true;
                } 
                return dfs(adj[u][(dir + i + 4) % 4], (dir + i + 4) % 4); 
            } 
        }
    } 
    return false;
} 
 
/* 
0, 1, 2, 3, 4 <-- idx 
2, 3, 2, 2, 2 <-- factor 
0, 1, 2, 3, 4, 1 <-- idx 
2, 1, 2, 2, 2, 3 <-- factor 
 
*/ 
 
int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
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
        want[min(u, v)][max(u, v)] = k;
    } 
    cin >> root >> dir; 
    int idir; 
    if(dir == 'N') idir = 0; 
    if(dir == 'E') idir = 1; 
    if(dir == 'S') idir = 2; 
    if(dir == 'W') idir = 3;
    bool ok = true;
    while(ok) { 
        ok = dfs(root, idir);
        if(!ok){
            cout << pts[cyc.back().st].st << " " << pts[cyc.back().st].nd << "\n";
        }
        else{
            int count_times = INF;
            for(int i = 0; i < cyc.size(); i++){
                auto c = cyc[i];
                int u = c.st, dir = c.nd, v = adj[u][dir];
                count_times = min(count_times, want[min(u, v)][max(u, v)] / edge[min(u, v)][max(u, v)]);
            }
            for(int i = 0; i < cyc.size(); i++){
                auto c = cyc[i];
                int u = c.st, dir = c.nd, v = adj[u][dir];
                want[min(u, v)][max(u, v)] -= count_times;
            }
            for(int i = 0; i < cyc.size(); i++){
                auto c = cyc[i];
                int u = c.st, dir = c.nd, v = adj[u][dir];
                edge[min(u, v)][max(u, v)] = 0;
            }
            cyc.clear();
        }
    } 
    return 0; 
}