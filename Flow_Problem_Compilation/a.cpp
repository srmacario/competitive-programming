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
const int N = 1e5+5;

struct edge {int v, c, f;};
int src, snk, h[N], ptr[N], n, m;
vector<edge> edgs;
vi g[N];

void add_edge(int u, int v, int c){
    int k = edgs.size();
    edgs.pb({v,c,0});
    edgs.pb({u,0,0});
    g[u].pb(k);
    g[u].pb(k+1);
}

void clear(){
    memset(h,0,sizeof h);
    memset(ptr, 0, sizeof ptr);
    edgs.clear();
    for(int i = 0; i < n; i++) g[i].clear();
    src = 0;
    snk = n-1;
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
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i <g[u].size(); ++i){
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if(h[v] != h[u] + 1) continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v,inc);
        if(inc){
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

int dinic(){
    int flow = 0;
    while(bfs()){
        memset(ptr, 0, sizeof ptr);
        while(int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    clear();
    vector <piii> ar;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        u--,v--;
        add_edge(u,v,c), ar.pb({c,{u,v}});
        add_edge(v,u,c), ar.pb({c,{v,u}});;
    }
    cout << dinic() << "\n";
    int flux = 0;
    for(int i = 0; i < edgs.size(); i += 2)
        if((i/2)%2) cout << edgs[i-2].f - edgs[i].f << "\n";        
    return 0;
}