#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 7;
 
int dp[2][N], ing[N], vis[N], ans;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> dist(n + 1);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ing[b]++, ing[a]++;
    }
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        if(d == 2) return;
        vis[u] = 1;
        for(auto e : adj[u]) if(e != p) {
            ing[u]--;
            ing[e]--;
            dfs(e, u, d + 1);
        }
    };
    dfs(1, 0, 0);
    queue<int> q;
    for(int i = 2; i <= n; i++){
        if(ing[i] == 1){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(vis[u] == 1) continue;
        vis[u] = 1;

        for(auto v : adj[u]){
            if(!vis[v]){
                ans++;
                vis[v] = 1;
                for(auto vv : adj[v]){
                    vis[vv] = 1;
                    ing[v]--;
                    if((--ing[vv]) == 1) q.push(vv);
                }
            }
        }
    }
    cout << min(dp[0][1], dp[1][1]) << endl;

    end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
}