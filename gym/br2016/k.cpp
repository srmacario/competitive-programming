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
const int INF = 1e9, MOD = 1e9+7;
const int N = 105;

int adj[N][2], incide[N], ans;

struct edge {int v, f, w, c; };

int flw_lmt = INF, src, snk, flw, cst, p[N], d[N], et[N];
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
    src = 0;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> adj[i][0] >> adj[i][1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) incide[i] = 0;
        clear();
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(adj[j][0] == i or adj[j][1] == i or j == i){
                if(j == i) continue;
                cnt++;
            }
            else{
                add_edge(src, j, 0, 1);
                add_edge(j, adj[j][0] + n, 1, 1);
                add_edge(j, adj[j][1] + n, 1, 1);
                incide[adj[j][0]]++;
                incide[adj[j][1]]++;
            }
        }
        for(int j = 1; j <= n; j++){
            if(incide[j]){
                if(j == adj[i][0] or j == adj[i][1]) add_edge(j + n, snk, 0, cnt - 2);
                else add_edge(j + n, snk, 0, cnt - 1);
            }
        }
        min_cost_max_flow();
        if(flw < n - cnt - 1) ans++;
    }
    cout << ans << "\n";
    return 0;
}