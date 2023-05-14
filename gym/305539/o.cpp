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
const int N = 1e6+5;
int dist[N];
vector <pii> adj[N];
priority_queue <pii> pq;
int a, b, w, m;

void dijkstra (int s) {
    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int w = x.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,u,v;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        adj[u].pb({v,1});
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
           if(j%k == i){
               adj[n+i+1].pb({j,1});
               adj[j].pb({n+i+1,0});
           } 
        }
    }
    cin >> u >> v;
    dijkstra(u);
    if(dist[v] < INF) cout << dist[v] << "\n";
    else cout << "-1\n";
    return 0;
}