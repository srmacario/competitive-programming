#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> par(n + 1), dist(n + 1, INF), vis(n + 1);
    dist[1] = 0;
    vis[1] = true;
    pq.emplace(0, 1);
    while(!pq.empty()) {
        auto [d, id] = pq.top(); pq.pop();
        if(d != dist[id]) continue;
        for(auto [e, v] : adj[id]) {
            if(dist[e] > d + v) {
                dist[e] = d + v;
                par[e] = id;
                pq.emplace(dist[e], e);
            }
        }
    }
    if(dist[n] == INF) {
        cout << -1 << "\n";
        return 0;
    }
    set<pair<int, int>> st;
    int cur = n;
    while(cur != 1) {
        st.emplace(min(cur, par[cur]), max(cur, par[cur]));
        cur = par[cur];
    }
    using node = tuple<int, int, int>;
    vector<vector<int>> dd(2, vector<int>(n + 1, INT_MAX));
    dd[0][1] = 0;
    int ans = INT_MAX;
    priority_queue<node, vector<node>, greater<node>> q;
    q.emplace(0, 1, 0);
    while(!q.empty()) {
        auto [dst, id, foi] = q.top(); q.pop();
        if(dd[foi][id] != dst) continue;
        for(auto [e, v] : adj[id]) {
            bool ok = foi;
            if(!ok) {
                if(st.find({min(e, id), max(e, id)}) == st.end()) {
                    ok = true;
                }
            }
            if(dd[ok][e] > dst + v) {
                dd[ok][e] = dst + v;
                q.emplace(dd[ok][e], e, ok);
            }
        }
    }
    if(dd[1][n] != INT_MAX and dd[0][n] != INT_MAX) {
        ans = dd[1][n] + dd[0][n];
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
    return 0;
}