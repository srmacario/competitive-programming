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
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n, m;
int vis[N], col[N];

vector<int> adj[N];

int op(int u) {
    if (u == 1) return 2;
    return 1;
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs(v);
}

bool check_bipartite(int u, int c) {
    col[u] = c;

    for (int v : adj[u]) {
        if (col[v] != 0 and col[v] == c) return false;
        if (col[v] == 0) {
            if (!check_bipartite(v, op(c))) return false;
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    int is_bit = 0;

    for (int i = 1; i <= n; i++) if (vis[i] == 0) {
        dfs(i);
        cnt++;
        if (check_bipartite(i, 1)) is_bit++;
    }

    //cout << "cnt: " << cnt << "\n";
    //cout << "is_bit: " << is_bit << "\n";
    if (is_bit != cnt) {
        cout << cnt - 1 << "\n";
    } else {
        cout << cnt << "\n";
    }

    return 0;
}