/**********************************************************************************
* DFS (DEPTH-FIRST SEARCH)                                                        *
* Description: Basic algorithm to traverse a graph prioritizing depth rather than *
* broadness.                                                                      *
* Usage: dfs(node)                                                                *
* Notation: adj[x]: adjacency list for node x                                     *
*           vis[i]: visited state for node i (0 or 1)                             *
**********************************************************************************/

const int N = 1e5+10; // Maximum number of nodes
int vis[N];
vi adj[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]){
        if (!vis[v]) {
            dfs(v);
        }
    }
    // vis[u] = 0;
    // Uncomment the line above if you need to
    // traverse only one path at a time (backtracking)
}