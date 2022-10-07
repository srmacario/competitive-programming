#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;
const int T = 1e4+5;

int n, m, k, x;
int dist[N][N];
vector<int> adj[N];

int dp[T];

int on, t, o[N], w[N], v[N], d;

void bfs(int s) {
    dist[s][s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();

        for (auto vi : adj[u]) {
            if (dist[s][vi] == INF) {
                dist[s][vi] = dist[s][u] + k;
                q.push(vi);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dist, INF, sizeof dist);

    cin >> n >> m >> k;
    
    int a, b;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) bfs(i);

    cin >> on >> t;
    for (int i = 1; i <= on; i++) cin >> o[i];
    o[on+1] = 1;

    bool fail = false;

    int last = 1;
    for (int i = 1; i <= on; i++) {
        cin >> d >> v[i];
        if (dist[last][o[i]] == INF) fail = true;

        if (!fail) {
            x += dist[last][o[i]];
            if (dist[o[i]][d] == INF or dist[d][o[i+1]] == INF) {
                w[i] = INF;
            } else {
                w[i] = dist[o[i]][d] + dist[d][o[i+1]] - dist[o[i]][o[i+1]];
            }
            last = o[i];
        }
    }

    if (dist[last][1] == INF) fail = true;
    if (!fail) x += dist[last][1];

    if (fail or t - x < 0) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 1; i <= on; i++)
        for (int wt = t - x; wt >= w[i]; wt--)
            dp[wt] = max(dp[wt], dp[wt - w[i]] + v[i]);

    cout << dp[t-x] << "\n";

    return 0;
}