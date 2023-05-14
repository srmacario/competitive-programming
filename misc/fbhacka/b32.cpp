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
const int N = 1e5+5;

struct edge {int v, c, f;};

struct edge {int v, f, w, c; };

int flw_lmt = INF, src, snk, flw, cst, p[N], d[N], et[N], can[N], in[N], out[N];
vector<edge> e;
vector<int> g[N];

void add_edge(int u, int v, int w, int c) {
    int k = e.size();
    g[u].push_back(k);
    g[v].push_back(k+1);
    e.push_back({ v, 0,  w, c });
    e.push_back({ u, 0, -w, 0 });
}

void clear() {
    src = N-2;
    snk = N-1;
    flw_lmt = INF;
    for(int i = 0; i < N; i++) g[i].clear();
    e.clear();
}

void min_cost_max_flow() {
    flw = 0, cst = 0;
    while (flw < flw_lmt) {
        memset(et, 0, sizeof et);
        memset(d, 63, sizeof d);
        deque<int> q;
        q.push_back(src), d[src] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            et[u] = 2;

            for(int i : g[u]) {
                edge &dir = e[i];
                int v = dir.v;
                if (dir.f < dir.c and d[u] + dir.w < d[v]) {
                    d[v] = d[u] + dir.w;
                    if (et[v] == 0) q.push_back(v);
                    else if (et[v] == 2) q.push_front(v);
                    et[v] = 1;
                    p[v] = i;
                }
            }
        }

        if (d[snk] > INF) break;

        int inc = flw_lmt - flw;
        for (int u = snk; u != src; u = e[p[u]^1].v) {
            edge &dir = e[p[u]];
            inc = min(inc, dir.c - dir.f);
        }

        for (int u = snk; u != src; u = e[p[u]^1].v) {
            edge &dir = e[p[u]], &rev = e[p[u]^1];
            dir.f += inc;
            rev.f -= inc;
            cst += inc * dir.w;
        }

        if (!inc) break;
        flw += inc;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &can[i]);
    }
    clear();
    int u, v;
    while(scanf("%d %d", &u, &v) != EOF){
        add_edge(u, v+n, can[u],0);
        in[v]++, out[u]++;
    }
    for(int i = 0; i < n; i++){
        add_edge(i+n, i, can[i],0);
        if(!in[i]){
            db(in[i] _ i);
            add_edge(src, i+n, can[i],0);
        }
        if(!out[i]){
            db(out[i] _ i);
            add_edge(i, snk, can[i],0);
        }
    }
    min_cost_max_flow();
    printf("%d\n", flw);
    return 0;
}