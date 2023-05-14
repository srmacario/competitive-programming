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
const int N = 2e5+5;

int n, q, ans[N], dist[2][N], vis[N];
vector<int> adj[N], qry[N], diam;
map<pii, vector<int>> id_qry;

int bfs(int s, int it){
    for(int i = 1; i <= n; i++) dist[it][i] = INF;
    queue<int> q;
    dist[it][s] = 0;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[it][u] + 1 < dist[it][v]){
                dist[it][v] = dist[it][u] + 1;
                q.push(v);
            }
        }
    }
    pair<int, int> cur_mx = {0, 0};
    for(int i = 1; i <= n; i++) cur_mx = max(cur_mx, make_pair(dist[it][i], i));
    return cur_mx.nd;
}

void dfs(int u, vector<int> &p){
    vis[u] = 1;
    for(auto v : qry[u]){
        if(p.size() < v) continue;
        for(auto i : id_qry[{u, v}]) ans[i] = p[p.size() - v];
    }
    p.push_back(u);
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v, p);
        }
    }
    p.pop_back();
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
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int u, k;
        cin >> u >> k;
        qry[u].push_back(k);
        id_qry[{u, k}].push_back(i);
    }
    diam.push_back(bfs(1, 0));
    diam.push_back(bfs(diam[0], 1));
    memset(ans, -1, sizeof(ans));
    for(auto u : diam){
        for(int i = 1; i <= n; i++) vis[i] = 0;
        vector<int> p;
        dfs(u, p);
    }
    for(int i = 0; i < q; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}