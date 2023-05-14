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
const ll LINF = 1e14+1;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll dist[N], gt[N], best, mxedge = LINF;
vector <pll> adj[N];
ll n, m, X;

void dijkstra (ll s, ll k) {
    priority_queue <pll> pq;
    for(int i = 0;i<=n;i++) dist[i] = LINF;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.st;
            ll w = x.nd;
            if(w > k) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

ll busca(){
    ll l = 0, r = mxedge;
    while(l < r){
        ll mid = (l + r)/2;
        dijkstra(1,mid);
        ll val = 100*dist[n];
        ll mx = (100 + X)*best;
        if(val > mx) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> X;
    for(int i=0;i<m;i++){
        ll u,v,t;
        cin >> u >> v >> t;
        adj[u].pb({v,t});
        adj[v].pb({u,t});
        mxedge = max(mxedge,t);
    }
    dijkstra(1,mxedge);
    best = dist[n];
    cout << busca() << "\n";
    return 0;
}