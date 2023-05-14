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

ll dist[N], burn[N];
vector <pll> adj[N];
priority_queue <pll> pq;
int n,m,k;

void dijkstra (int s) {
    for(int i=0;i<N;i++) dist[i] = LINF;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.st;
            ll w = x.nd;
            if (dist[v] > dist[u] + w + burn[v]) {
                dist[v] = dist[u] + w + burn[v];
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    for(int i=1;i<=n;i++) cin >> burn[i];
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        adj[0].pb({x,0});
        adj[x].pb({0,0});
    }
    dijkstra(0);
    for(int i=1;i<=n;i++) cout << dist[i] << "\n";
    return 0;
}