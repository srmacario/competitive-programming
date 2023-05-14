#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

using ll = long long;
using ld = long double;

const int N = 1e5+5, M = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, q, w[N], vis[N], upd[N];
bitset<M> old, cur;
ll resp;
vector<int> adj[N], knap;

int dfs(int u){
    int mx = w[u];
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]) mx = max(mx, dfs(v));
        if(mx == INF) return INF;
    }
    int dif = mx - w[u];
    auto v = lower_bound(knap.begin(), knap.end(), dif);
    if(v == knap.end()) return INF;
    else w[u] += *v;
    return w[u];
}

int main() {
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= q; i++) scanf("%d", &upd[i]);
    //knapsack
    old[0] = 1;
    for(int i = 1; i <= q; i++){
        cur = old;
        cur <<= upd[i];
        cur |= old;
        old = cur;
    }
    for(int j = 0; j < M; j++) if(cur[j]) knap.push_back(j);
    //dfs
    int test = dfs(1);
    if(test == INF) printf("-1\n");
    else{
        for(int i = 1; i <= n; i++) resp += w[i];
        printf("%lld\n", resp);
    }
    return 0;
}