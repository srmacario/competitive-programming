#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 1e5 + 5;

vector<int> adj[N], adjt[N];
int n, m, ordn, cnt, vis[N], ord[N], cmp[N], br[N], x;

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]) if(!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst(int u){
    cmp[u] = cnt, vis[u] = 0, br[u] = x++;
    for(auto v : adjt[u]) if(vis[v]) dfst(v);
}

int dp[N][40];
bool visb[N][40];

int calc(int p, int b){
    if(visb[p][b])
        return dp[p][b];
    visb[p][b] = true;
    for(int i : adj[p]){
        if(cmp[i] == cmp[p]){
            if((b & (1 << br[i])) == 0)
                dp[p][b] = max(dp[p][b], calc(i, b | (1 << br[i])));
        }
        else
            dp[p][b] = max(dp[p][b], calc(i, 1 << br[i]));
    }
    return ++dp[p][b];
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adjt[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    for(int i = ordn - 1; i >= 0; i--) if(vis[ord[i]]) cnt++, x = 0, dfst(ord[i]);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, calc(i, 1 << br[i]));
    printf("%d\n", ans);
    return 0;
}