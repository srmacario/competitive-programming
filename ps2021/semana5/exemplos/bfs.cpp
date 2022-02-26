/**********************************************************************************
* BFS (BREADTH-FIRST SEARCH)                                                      *
* Description: Basic algorithm to traverse a graph prioritizing broadness rather  *
* than depth.                                                                     *
* Time complexity: O(V+E)                                                         *
* Usage: bfs(node)                                                                *
* Notation: s: starting node                                                      *
*           adj[i]: adjacency list for node i                                     *
*           vis[i]: visited state for node i (0 or 1)                             *
**********************************************************************************/

const int N = 1e5+10; // Maximum number of nodes
int vis[N];
vi adj[N];
queue <int> q;

void bfs (int s) {
    cl(vis, 0);
    vis[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) if (!vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }
}