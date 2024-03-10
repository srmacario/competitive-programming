#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long double ld;
typedef long long ll;

const int N = 1e5+5;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld log7 = (ld)1 / log2l(7.);

int n, m;
vector<pii> adj[N];
ld dist[N];

ld dijkstra(){
    for(int i = 2; i <= n; i++) dist[i] = LINF;
    priority_queue<pair<ld, int>> pq;
    pq.push({0, 1});
    while(pq.size()){
        ld ud = -pq.top().st;
        int u = pq.top().nd;
        pq.pop();
        if(dist[u] < ud) continue;
        for(auto nxt : adj[u]){
            if(dist[nxt.nd] > dist[u] + log2l(nxt.st) * log7){
                dist[nxt.nd] = dist[u] + log2l(nxt.st) * log7;
                pq.push({-dist[nxt.nd], nxt.nd});
            }
        }
    }
    return dist[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    cout << setprecision(15) << fixed << dijkstra() << "\n";
    return 0;
}