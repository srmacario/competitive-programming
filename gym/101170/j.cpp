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
const int INF = 1e9, MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, q, s, sensor_q[105], q_sz[105];
struct edge{int v, c, f;};

int src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

void add_edge(int u, int v, int c){
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k + 1);
}

void clear(){
    memset(h, 0, sizeof h);
    memset(ptr, 0, sizeof(ptr));
    edgs.clear();
    for(int i = 0; i < N; i++) g[i].clear();
    src = 0;
    snk = N - 1;
}

bool bfs(){
    memset(h, 0, sizeof h);
    queue<int> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : g[u]){
            int v = edgs[i].v;
            if(!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

int dfs(int u, int flow){
    if(!flow or u == snk) return flow;
    for(int &i = ptr[u]; i < g[u].size(); ++i){
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if(h[v] != h[u] + 1) continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if(inc){
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

ll dinic(){
    ll flow = 0;
    while(bfs()){
        memset(ptr, 0, sizeof ptr);
        while(int inc = dfs(src, INF)) flow = (flow + inc);
    }
    return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clear();
    cin >> n >> q >> s;
    for(int i = 1; i <= s; i++) cin >> sensor_q[i];
    for(int i = 1; i <= q; i++) cin >> q_sz[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll q_step[35] = {0};
        ll d;
        cin >> d;
        for(int j = 1; j <= s; j++){
            ll amount;
            cin >> amount;
            q_step[sensor_q[j]] += amount;
            ans += amount;
        }    
        //[1, q] -> q_in
        //[q + 1, 2q] -> q_out
        for(int j = 1 + i * 2 * q; j <= q + i * 2 * q; j++){
            add_edge(src, j, q_step[j - i * 2 * q]);
            add_edge(j, j + q, q_sz[j - i * 2 * q]);
            if(i < n - 1) add_edge(j + q, j + 2 * q, INF);
            //connect to temp sink
            add_edge(j + q, snk - i - 1, INF);
        }
        add_edge(snk - i - 1, snk, d);
    }
    if(ans == dinic()) cout << "possible\n";
    else cout << "impossible\n";
    return 0;
}
