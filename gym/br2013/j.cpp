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

vi adj[N];
ll dist[N], mx[2][N], ps[2][N], diam[2];

void bfs (int s) {
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) if (dist[v] > dist[u] + 1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

void calc(int n, int k){
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++) dist[i] = LINF, mx[k][i] = ps[k][i] = 0;
    bfs(1);
    pii ini = {0,0}, fim = {0,0};
    for(int i=1;i<=n;i++){
        ini = max(ini,{dist[i],i});
    }
    for(int i=1;i<=n;i++) dist[i] = LINF;
    bfs(ini.nd);
    for(int i=1;i<=n;i++){
        fim = max(fim,{dist[i],i});
    }
    for(int i=1;i<=n;i++){
        mx[k][i] = dist[i];
    }
    diam[k] = fim.st;
    for(int i=1;i<=n;i++) dist[i] = LINF;
    bfs(fim.nd);
    for(int i=1;i<=n;i++){
        mx[k][i] = max(mx[k][i],dist[i]);
        adj[i].clear();
    }
    sort(mx[k]+1, mx[k]+n+1);
    for(int i=1;i<=n;i++){
        ps[k][i] = ps[k][i-1] + mx[k][i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(3);
    ll n,m;
    while(cin >> n >> m){
        calc(n,0);
        calc(m,1);
        ll q1 = 0;
        double S = 0;
        ll M = max(diam[0],diam[1]);
        for(int i=1;i<=n;i++){
            int ub = (upper_bound(mx[1]+1,mx[1]+m+1,M - mx[0][i] - 1) - mx[1]);
            q1 = m-ub+1;
            double s = q1*(mx[0][i]+1) + (ps[1][m] - ps[1][m-q1]) + M*(m-q1);
            S += s;
        }
        double ans = S/(n*m);
        cout << ans << "\n";
    }
    return 0;
}