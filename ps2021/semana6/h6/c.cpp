#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
//0, -1, 63 = INF
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

ll dist[N];
vector <pll> adj[N];
priority_queue <pll> pq;
int a, b, w, m;
int par[N];

void dijkstra (int s) {
    for(int i = 0; i < N; i++) dist[i] = LINF;
    dist[s] = 0;
    par[s] = s;
    pq.push({0, s});

    while (!pq.empty()) {
        int ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            int w = x.nd;
            if (dist[v] > dist[u] + w) {
                par[v] = u;
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    scanf("%d%d", &n, &m);
    // Be careful with directed graphs!
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].pb({b, w}); // Be careful!
        adj[b].pb({a, w}); // Be careful!
    }
    dijkstra(1);
    if(dist[n] == LINF){
        printf("-1\n");
        return;
    }
    int cur = n;
    vi ans;
    ans.pb(cur);
    while(cur != par[cur]){
        cur = par[cur];
        ans.pb(cur);
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}