#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int dist[N];
//vector <pii> adj[N];
//priority_queue <pii> pq;
int a, b, w, m, n, par[N], path[N], ptpar[N];
int vis[N];
vi adj[N];

void bfs(int s) {
    cl(dist, 63);
    queue <int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]){
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
            if (dist[v] == dist[u] + 1 and par[v] == ptpar[v]) {
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }    
}

void bfs2(int s) {
    cl(dist, 63);
    queue <int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]){
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
            if (dist[v] == dist[u] + 1 and u == ptpar[v]) {
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b].pb(a);
    }
    int k, ans_min = 0, ans_max = 0, l, f;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> path[i];
        if(i == 0) f = path[i];
        if(i == k-1) l = path[i];
    }
    for(int i=k-2;i>=0;i--){
        ptpar[path[i]] = path[i+1];
    }
    bfs(l);
    int now = f;
    vi rpath;
    while(now != l){
        rpath.pb(now);
        now = par[now];
    }
    rpath.pb(now);
    for(int i=0;i<k;i++){
        if(par[path[i]] != ptpar[path[i]]) ans_max++;
    }
    bfs2(l);
    for(int i=0;i<k;i++){
        if(par[path[i]] != ptpar[path[i]]) ans_min++;
    }
    cout << ans_min << " " << ans_max << "\n";
    return 0;
}
