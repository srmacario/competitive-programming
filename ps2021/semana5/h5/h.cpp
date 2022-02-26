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
const int N = 3e5+5;

vi adj[N];
int n, dist[N], dist_old[N];

void bfs(int s){
    queue <int> q;
    //63 == 3f
    memset(dist, 63, sizeof(dist));
    //fill(dist, dist + N, INF);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1);
    pii mx1 = {0, 0}, mx2 = {0,0};
    for(int i = 1; i <= n; i++){
        mx1 = max(mx1, {dist[i], i});
    }
    bfs(mx1.nd);
    for(int i = 1; i <= n; i++){
        mx2 = max(mx2, {dist[i], i});
        dist_old[i] = dist[i];
    }
    //diametro = mx2.st
    bfs(mx2.nd);
    for(int i = 1; i <= n; i++){
        int dist1 = dist_old[i], dist2 = dist[i];
        int ans = max({dist1 + 1, dist2 + 1, mx2.st});
        cout << ans << "\n";
    }
    return 0;
}