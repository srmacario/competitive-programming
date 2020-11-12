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
const int N = 1005;

int dist[N][N], n , m, k, a, b, w;
vector <pii> adj[N], cou, edge;
priority_queue <pii> pq;

void dijkstra (int s) {
    for(int i=0;i<N;i++) dist[s][i] = INF;
    dist[s][s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[s][u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int w = x.nd;
            if (dist[s][v] > dist[s][u] + w) {
                dist[s][v] = dist[s][u] + w;
                pq.push({-dist[s][v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
        edge.pb({a,b});
    }
    for(int i=0;i<k;i++){
        int u,v;
        cin >> u >> v;
        cou.pb({u,v});
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    int ans = INF;
    for(auto e : edge){
        int partans = 0;
        for(auto r : cou){
            int r1 = dist[r.st][r.nd];
            int r2 = dist[r.st][e.st] + dist[e.nd][r.nd];
            int r3 = dist[r.st][e.nd] + dist[e.st][r.nd];
            int mn = min({r1, r2, r3});
            partans += mn;
        }
        ans = min(ans,partans);
    }
    cout << ans << "\n";
    return 0;
}