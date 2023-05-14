#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3 + 5;

int n, m, k;
int dist[N], vis[N];
int out[N];
int root = 1;
vector<int> adj[N];

void bfs(int u) {
    memset(dist, 63, sizeof dist);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int cnt;

void dfs(int u) {
    if (vis[u]) return;
    cnt++;
    vis[u] = 2;
    for (auto v : adj[u]) if (!vis[v]) dfs(v);
}

int ceil(int a, int b) {
    return (a + b - 1) / b;
}

bool test(int d) {
    vector<int> starts;
    bfs(root);
    for (int i = 1; i <= n; i++) 
        if (dist[i] <= d) starts.push_back(i);

    ll sum = 0;

    for (auto s : starts) {
        memset(vis, 0, sizeof vis);
        sum = 0;
        bfs(s);
        for (int i = 1; i <= n; i++) 
            if (dist[i] <= d) {
                vis[i] = 1;
            }

        for (int i = 1; i <= n; i++) 
            if (!vis[i]) {
                cnt = 0;
                dfs(i);
                sum += ceil(cnt, 2 * d + 1);
            }

        if (sum <= k - 1) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    int u, v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        out[u]++;
        out[v]++;
    }

    for (int i = 1; i <= n; i++) if (out[i] > 2) { 
        root = i;
        break;
    }

    int l = 0, r = n - 1, mid;
    while (l != r) {
        mid = (l + r) / 2;
        if (test(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";

    return 0;
}