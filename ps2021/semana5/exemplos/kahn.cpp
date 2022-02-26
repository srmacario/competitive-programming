/**********************************************************************************
* KAHN'S ALGORITHM (TOPOLOGICAL SORTING)                                          *
* Description: Given a directed graph, the algorithm generates a possible way to  *
* traverse the graph meeting the dependencies, like subjects during graduation.   *
* It recursively finds the vertices with no dependencies and remove their edges,  *
* and repeat the process once again.                                              *
* It is considered that edges are directed from independent vertices towards      *
* dependent vertices.                                                             *
* Time complexity: O(V+E)                                                         *
* Notation: adj[i]:  adjacency matrix for node i                                  *
*           n:       number of vertices                                           *
*           e:       number of edges                                              *
*           a, b:    edge between a and b                                         *
*           inc:     number of incoming arcs/edges                                *
*           q:       queue with the independent vertices                          *
*           tsort:   final topo sort, i.e. possible order to traverse graph       *
**********************************************************************************/

vi adj[N];
int inc[N];
queue <int> q;
vi tsort;
int n, e, a, b;

int main () {
    scanf("%d%d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        inc[b]++;
        // inc[a]++;
        // Uncomment the line above if dependent vertices
        // are directed towards independent ones.
    }

    for (int i = 1; i <= n; ++i) if (inc[i] == 0) q.push(i);
    // if (inc[i] == 1) Undirected graphs

    while (!q.empty()) {
        int u = q.front(); q.pop();
        tsort.pb(u);
        for (int v : adj[u])
            if (inc[v] > 0 and --inc[v] == 0)
                // if (inc[v] > 1 and --inc[v] == 1)     Undirected graphs
                q.push(v);
    }
}