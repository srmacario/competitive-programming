#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

using ll = long long;
using ld = long double;

const int N = 5e2+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, ll>> adj[N];
ll dist[N];

void dijkstra(int s, int val) {
    memset(dist, 63, sizeof dist);
    dist[s] = val;
    priority_queue<pair<ll, int>> pq;
    pq.push({ -dist[s], s });

    while (pq.size()) {
        pair<ll, int> x = pq.top();
        pq.pop();
        ll ud = -x.first;
        int u = x.second;

        if (ud > dist[u]) continue;

        for (pair<int, ll> ex : adj[u]) {
            int v = ex.first;
            ll w = ex.second;

            if (dist[v] > dist[u] + w + val) {
                dist[v] = dist[u] + w + val;
                pq.push({ -dist[v], v });
            }
        }
    }
}

int n, m, q;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    int x;
    while (q--) {
        cin >> u >> v >> x;

        dijkstra(u, x);
        if (dist[v] == LINF) dist[v] = -1;
        cout << dist[v] << "\n";
    }

    return 0;
}