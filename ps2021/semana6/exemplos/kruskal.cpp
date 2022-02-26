/**********************************************************************************
* KRUSKAL'S ALGORITHM (MINIMAL SPANNING TREE - INCREASING EDGE SIZE)              *
* Description: Given an undirected graph, the algorithm generates the minimal     *
* possible tree that covers all vertices, with minimum cost. We sort the edges in *
* increasing order of cost in a priority queue and then simply add them to the    *
* tree unless it generates a cycle in the new graph, because if there already is  *
* a path between A and B we don't need to add an edge between A and B at all. We  *
* use DSU to determine if the new edge will make a cycle or not.                  *
* Time complexity: O(ElogE)                                                       *
* Usage: cost, sz[find(node)]                                                     *
* Notation: cost: sum of all edges which belong to such MST                       *
*           sz:   vector of subsets sizes, i.e. size of the subset a node is in   *
**********************************************************************************/

// + DSU (DISJOINT SET UNION / UNION-FIND)

int cost = 0;
vector <piii> edges; //mp(dist, mp(node1, node2))

int main () {
    // ...
    sort(edges.begin(), edges.end());
    for (auto e : edges)
        if (find(e.nd.st) != find(e.nd.nd))
            unite(e.nd.st, e.nd.nd), cost += e.st;

    return 0;
}