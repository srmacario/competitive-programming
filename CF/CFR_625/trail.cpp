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
const int N = 3e5+5;
ll n,m,dist[N];
vector <pll> adj[N];
priority_queue <pll> pq;
ll ans = LINF, cnt = 0;
void dijkstra (ll s) {
    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.st;
            ll w = x.nd;
            if (dist[v] > dist[u] + w){
                if(v == n-1) ans = dist[u]+w, cnt = 1;
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
            else if (dist[v] == dist[u] + w and v == n-1) {
                cout << dist[v] << "\n";
                if(ans == dist[v]) cnt++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[v].pb({u,w});
        adj[u].pb({v,w});
    }
    dijkstra(0);
    cout << ans*cnt*2 << "\n";
    return 0;
}