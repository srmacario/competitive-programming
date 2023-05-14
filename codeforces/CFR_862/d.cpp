#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, dist[N], vis[N], h[N], ans[N], cmp, max_dist;
vector<int> adj[N];

int bfs(int s){
    queue<int> q;
    memset(dist, 63, sizeof(dist));
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    pii ans = {0, 0};
    for(int i = 1; i <= n; i++) ans = max(ans, make_pair(dist[i], i));
    max_dist = ans.st;
    return ans.nd;
}

void dfs(int s, int hd){
    vis[s]++;
    h[s] = max(h[s], hd);
    for(auto v : adj[s]){
        if(vis[v] < vis[s]){
            dfs(v, hd + 1);
        }
    }
    max_dist = max(max_dist, hd);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mx1 = bfs(1);
    int mx2 = bfs(mx1);
    db(mx1 _ mx2);
    dfs(mx1, 0);
    dfs(mx2, 0);
    for(int i = 1; i <= n; i++){
        if(i != mx1) ans[h[i]]++;
    }
    int cur = n;
    vector<int> resp(n + 1);
    for(int i = n; i >= 1; i--){
        cur -= ans[i];
        resp[i] = cur;
    }
    
    for(int i = 1; i <= n; i++) cout << resp[i] << " ";
    cout << "\n";
    return 0;
}