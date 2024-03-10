#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define nd second
#define st first


#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<


const int INF = 0x3f3f3f3f;
const int N = 3e5 + 5;

int n, m, dist[N], paths[N];
vector<int> adj[N];

void bfs(int s, int block){
    queue<int> q;
    for(int i = 1; i <= n; i++) dist[i] = INF, paths[i] = 0;
    dist[s] = 0, paths[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(u == s and v == block) continue;
            if(dist[v] >= dist[u] + 1){
                if(dist[v] > dist[u] + 1) q.push(v);
                paths[v] += paths[u];
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans_size = INF, ans_count = 0;
    for(int i = 1; i <= n; i++){
        for(auto v : adj[i]){
            bfs(i, v);
            if(ans_size == dist[v] + 1) ans_count += paths[v];
            if(ans_size > dist[v] + 1) ans_size = dist[v] + 1, ans_count = paths[v];
        }
    }
    cout << ans_count / (2 * ans_size)<< "\n";
    return 0;
}