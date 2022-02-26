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

int dist[N];
vi adj[N];

void bfs (int s) {
    queue <int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cl(dist, 63);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        if(p == -1) adj[0].pb(i);
        else adj[p].pb(i);
    }
    int ans = 0;
    for(auto x : adj[0]){
        bfs(x);
    }
    for(int i = 1; i <= n; i++) ans = max(ans, dist[i]);
    cout << ans + 1 << "\n";
    return 0;
}