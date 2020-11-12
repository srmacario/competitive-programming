#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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
const int N = 1e6+5;

int n, k, p[N], c[N], l[N];

struct edge {int v, c, f;};

int src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

int cmp[N];
void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
    }
}

void add_edge (int u, int v, int c) {
    int k = edgs.size();
    edgs.push_back({v, c, 0});
    edgs.push_back({u, 0, 0});
    g[u].push_back(k);
    g[v].push_back(k+1);
}

void clear() {
    memset(h, 0, sizeof h);
    memset(ptr, 0, sizeof ptr);
    edgs.clear();
    for (int i = 0; i < N; i++) g[i].clear();
    src = 0;
    snk = N-1;
}

bool bfs() {
    memset(h, 0, sizeof h);
    queue<int> q;
    h[src] = 1;
    q.push(src);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int i : g[u]) {
            int v = edgs[i].v;
            if (!h[v] and edgs[i].f < edgs[i].c)
                q.push(v), h[v] = h[u] + 1;
        }
    }
    return h[snk];
}

int dfs (int u, int flow) {
    if (!flow or u == snk) return flow;
    for (int &i = ptr[u]; i < g[u].size(); ++i) {
        edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
        int v = dir.v;
        if (h[v] != h[u] + 1)  continue;
        int inc = min(flow, dir.c - dir.f);
        inc = dfs(v, inc);
        if (inc) {
            dir.f += inc, rev.f -= inc;
            return inc;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memset(ptr, 0, sizeof ptr);
        while (int inc = dfs(src, INF)) flow += inc;
    }
    return flow;
}

ll test(ll lvl){
    clear();
    vi odd, even;
    int one = 0, sum = 0;
    for(int i=1;i<=n;i++){
        if(c[i] == 1){
            if(l[i] <= lvl){
                if(p[one] < p[i]) one = i;
            }
        }
        else{
            if(c[i]%2){
                if(l[i] <= lvl) odd.pb(i), sum += p[i];
            }
            else{
                if(l[i] <= lvl) even.pb(i), sum += p[i];
            }
        }
    }
    if(one) odd.pb(one);
    for(int i=0;i<odd.size();i++){
        add_edge(src,odd[i],p[odd[i]]);
    }
    for(int i=0;i<even.size();i++){
        add_edge(even[i],snk,p[even[i]]);
        for(int j=0;j<odd.size();j++){
            if(!cmp[c[even[i]] + c[odd[j]]]){
                add_edge(odd[j],even[i],INF);
            }
        }   
    }
    sum += p[one];
    int mc = dinic();
    //cout << sum << " " << mc << " " << lvl << "\n";
    int ans = sum - mc;
    return ans >= k;
}

ll busca(){
    ll l = 1, r = N;
    while(l < r){
        ll m = (l+r)/2;
        if(test(m)) r = m;
        else l = m + 1;
    }
    return ((l == N) ? -1 : l);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primes();
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> p[i] >> c[i] >> l[i];
    }
    //db(test(3));
    cout << busca() << "\n";
    return 0;
}