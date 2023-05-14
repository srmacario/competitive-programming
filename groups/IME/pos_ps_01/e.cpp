#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n, m;

vector<pii> adj[N];
ll dist[3][N];

void dijkstra(int node){
    priority_queue<piii> pq;
    dist[0][node] = 0;
    pq.push({0, {0, node}});
    while(!pq.empty()){
        int u = pq.top().nd.nd;
        ll w = -pq.top().st;
        int m = pq.top().nd.st;
        pq.pop();
        if(w > dist[m][u]) continue;
        if(u == n) continue;
        for(auto v : adj[u]){
            int node_v = v.nd;
            ll wei_v = v.st;
            int mod = (m + 1) % 3;
            if(dist[m][u] + wei_v < dist[mod][node_v]){
                dist[mod][node_v] = dist[m][u] + wei_v;
                pq.push({-dist[mod][node_v], {mod, node_v}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist, 63, sizeof(dist));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dijkstra(1);
    vector<pair<int, string>> ans;
    ans.push_back({dist[0][n], "me"});
    ans.push_back({dist[1][n], "Gon"});
    ans.push_back({dist[2][n], "Killua"});
    sort(ans.begin(), ans.end());
    for(auto a : ans) cout << a.nd << "\n";
    return 0;
}