/**********************************************************************************
* CENTROID DECOMPOSITION (FIND SUCH V THAT NO BRANCH IS GREATER THAN V/2)         *
* Description: Given a tree, we want to find a vertex for which none of his       *
* branches has a greater size than V/2. Every tree has between 1 and 2 centroids. *
* Idea: From the outside in, we can accumulate the sizes of the branches. For a   *
* leaf, sz[i] = 1. For his parent, sz[i] will be the sum of sizes of his sons,    *
* none of which can be greater than V/2. Afterwards, we also need to check if     *
* V-sz[i] is lesser than V/2 (his parent's branch). If all those conditions are   *
* met, we have found a centroid.                                                  *
* Time complexity: O(V)                                                           *
* Usage: cent                                                                     *
**********************************************************************************/

int n, vis[N], sz[N];
vi adj[N], cent;

void dfs (int u) {
    bool ok = true;
    sz[u] = 1;

    for (auto v : adj[u]) if (!vis[v]) {
        vis[v] = 1;
        dfs(v);
        sz[u] += sz[v];
        if (2*sz[v] > n) ok = false;
    }

    if (ok and 2*(n-sz[u]) <= n) cent.pb(u);
}

int main () {
    // (...)
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        vis[i] = 1;
        dfs(i);
    }
    for (auto c : cent) { // centroids
        // (...)
    }
    return 0;
}