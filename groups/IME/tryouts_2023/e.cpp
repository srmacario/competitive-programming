#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5;

int n, m, a[N], par[N], sz[N], cmp = 1;
vector<int> conn[N];

int find(int u){
    return (u == par[u] ? u : par[u] = find(par[u]));
}

void unite(int u, int v){
    if((u = find(u)) == (v = (find(v)))) return;
    if(sz[u] < sz[v]) swap(u, v);
    if(v == 1) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> id;
    for(int i = 1; i <= n; i++){
        sz[i] = 1, par[i] = i;
        cin >> a[i];
        id.push_back(a[i]);
    }
    sort(id.begin(), id.end());
    for(auto i : id){
        if(cmp != i) break;
        cmp++;
    }
    cmp--;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u = a[u], v = a[v];
        if(u < v) swap(u, v);
        if(u > cmp) continue;
        conn[u].push_back(v);
    }
    int ans = 1;
    for(int i = 1; i <= cmp; i++){
        for(auto v : conn[i]) unite(v, i);
        if(sz[1] == i) ans = i;
    }
    cout << ans << "\n";
}