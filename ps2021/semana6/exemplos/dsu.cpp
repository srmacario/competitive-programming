/**********************************************************************************
* DSU (DISJOINT SET UNION / UNION-FIND)                                           *
* Description: The DSU structure performs two operations: union and find. It is   *
* required in Kruskal's MST algorithm.                                            *
* FIND: Determine if two elements are in the same subset. Can be used to detect   *
* cycles in an undirected graph.                                                  *
* UNION: Join two subsets into a single subset.                                   *
* Usage: find(node), unite(node1, node2), sz[find(node)]                          *
* Notation: par: vector of parents                                                *
*           sz:  vector of subsets sizes, i.e. size of the subset a node is in    *
**********************************************************************************/

int par[N], sz[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main () {
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
}