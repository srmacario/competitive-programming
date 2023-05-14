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
const int N = 2e3+5;

int n, m, c[N], dist[N][N];
vector<int> adj[2][N];

int bfs(){
    memset(dist, 63, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({1, n});
    dist[1][n] = 0;
    while(!q.empty()){
        int u = q.front().st;
        int v = q.front().nd;
        q.pop();
        for(int i = 0; i < 2; i++){
            for(auto nxt_u : adj[i][u]){
                for(auto nxt_v : adj[i ^ 1][v]){
                    if(dist[nxt_u][nxt_v] > dist[u][v] + 1){
                        dist[nxt_u][nxt_v] = dist[u][v] + 1;
                        q.push({nxt_u, nxt_v});
                    }
                }
            }
        }
    }
    return dist[n][1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) adj[0][i].clear(), adj[1][i].clear();
        for(int i = 1; i <= n; i++) cin >> c[i];
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[c[u]][v].push_back(u);
            adj[c[v]][u].push_back(v);
        }
        int d = bfs();
        cout << (d == INF ? -1 : d) << "\n";
    }
    return 0;
}