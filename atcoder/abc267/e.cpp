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
const int N = 2e5+5;

ll n, m, a[N], ing[N], cost[N], mark[N];
vector<int> adj[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        ing[u]++, ing[v]++;
        cost[u] += a[v];
        cost[v] += a[u];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<pair<ll, int>> verts;
    for(int i = 1; i <= n; i++){
        verts.push({-cost[i], i});
    }
    ll ans = 0;
    while(!verts.empty()){
        while(!verts.empty() and mark[verts.top().nd]) verts.pop();
        if(verts.empty()) break;

        pair<ll, int> cur = verts.top();
        verts.pop();

        for(auto v : adj[cur.nd]){
            cost[v] -= a[cur.nd];
            verts.push({-cost[v], v});
        }
        ans = max(ans, -cur.st);
        mark[cur.nd] = 1;
    }
    cout << ans << "\n";
    return 0;
}