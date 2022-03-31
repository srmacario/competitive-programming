#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m[2], dist_bfs[N], dist_dijk[N];
vi adj[N];
vector<pair<int, int>> dijk_adj[N];

void bfs(int u){
    memset(dist_bfs, 63, sizeof(dist_bfs));
    queue<int> q;
    dist_bfs[u] = 0;
    q.push(u);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(dist_bfs[v] > dist_bfs[u] + 1){
                dist_bfs[v] = dist_bfs[u] + 1;
                q.push(v);
            }
        }
    }
}

void dijkstra(int s){
    memset(dist_dijk, 63, sizeof(dist_dijk));
    priority_queue<pii> pq;
    dist_dijk[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().nd;
        int w = -pq.top().st;
        pq.pop();
        if(w > dist_dijk[u]) continue;
        for(auto v: dijk_adj[u]){
            int node_v = v.nd;
            int wv = v.st;
            if(dist_dijk[node_v] > dist_dijk[u] + wv){
                dist_dijk[node_v] = dist_dijk[u] + wv;
                pq.push({-dist_dijk[node_v], node_v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m[0] >> m[1];
    vector<int> item[2];
    for(int i = 0; i < 2; i++){
        item[i].resize(m[i]);
        for(int j = 0; j < m[i]; j++) cin >> item[i][j];
    }
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        for(int k = 0; k < a; k++){
            int j;
            cin >> j;
            adj[i].pb(j);
            dijk_adj[i].pb({1, j});
        }
    }
    bfs(1);
    int ans[2] = {INF, INF};
    int resp = INF;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < m[i]; j++) ans[i] = min(ans[i], dist_bfs[item[i][j]]);
    }
    if(ans[0] == INF or ans[1] == INF){
        cout << "impossible";
        return 0;
    }
    resp = ans[0] + ans[1];
    for(int i = 0; i < 2; i++){
        dijk_adj[N - 1].clear();
        for(int j = 0; j < m[i]; j++){
            if(dist_bfs[item[i][j]] < INF) dijk_adj[N - 1].push_back({dist_bfs[item[i][j]], item[i][j]});
        }
        dijkstra(N - 1);
        for(int j = 0; j < m[i ^ 1]; j++){
            resp = min(resp, dist_dijk[item[i ^ 1][j]]);
        }
    }

    cout << resp << "\n";
    return 0;
}
