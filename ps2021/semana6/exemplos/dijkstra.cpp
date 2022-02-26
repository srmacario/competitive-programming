/**********************************************************************************
* DIJKSTRA'S ALGORITHM (SHORTEST PATH TO A VERTEX)                                *
* Description: Given any graph (not necessarily a tree), the algorithm generates  *
* an array denoting the shortest distance from each vertex to the start point. It *
* starts considering all distances equal to infinity and then uses the given      *
* edges in a BFS to generate the array.                                           *
* Time complexity: O((V+E)logE)                                                   *
* Usage: dist[node]                                                               *
* Notation: m:           number of edges                                          *
*           (a, b, w):   edge between a and b with weight w                       *
*           s:           starting node                                            *
*           par[v]:      parent node of u, used to rebuild the shortest path      *
**********************************************************************************/

const int N = 1e4+10; // Maximum number of nodes
int dist[N];
vector <pii> adj[N];
priority_queue <pii> pq;
int a, b, w, m;
//int par[N];

void dijkstra (int s) {
    // Be careful with directed graphs!
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].pb({b, w}); // Be careful!
        adj[b].pb({a, w}); // Be careful!
    }

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
                //par[v] = u;
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}