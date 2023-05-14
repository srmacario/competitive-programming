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
int dist[N], from[N], to[N], par[N], sz[N], vis[N];

void bfs(int s){
    memset(dist,63, sizeof(dist));
    memset(par,0, sizeof(par));
    queue <int> q;
    dist[s] = 0;
    q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : adj[u]) if (dist[v] > dist[u] + 1){
            dist[v] = dist[u] + 1;
            par[v] = u;
            q.push(v);
        }
    }
}

int dfs(int s){
    vis[s] = 1;
    for(auto v : adj[s]){
        if(!vis[v]){
            int tmp = dfs(v);
            if(from[v] != s){
                sz[s] = max(tmp,sz[s]);
            }
        }
    }
    return ++sz[s];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n == 2){
        cout << "1 2 \n";
        return 0;
    }
    bfs(1);
    pii p1 = {0,0}, p2 = {0,0};
    for(int i=1;i<=n;i++){
        p1 = max(p1,{dist[i],i});
    }
    bfs(p1.nd);
    for(int i=1;i<=n;i++){
        p2 = max(p2,{dist[i],i});
    }
    int l,r, cur = p2.nd, cnt = 0;
    while(cur != p1.nd){
        ++cnt;
        from[cur] = par[cur];
        to[par[cur]] = cur;
        cur = par[cur];
        if(cnt == p2.st/2) l = cur;
        if(cnt == (p2.st+1)/2) r = cur;
    }
    dfs(p1.nd);
    int ansr = dist[r], ansl = p2.st - dist[l], now = sz[r] - 1;
    int vertr = r, vertl = l;
    while(r != p1.nd){
        r = par[r];
        now = max({now + 1, sz[r] - 1});
        db(now);
        if(ansr > max(now,dist[r])){
            db(ansr), db(max(now,dist[r]));
            vertr = r;
            ansr = max(now,dist[r]);
        }
    }
    now = sz[l] - 1;
    r = vertr;
    while(l != p2.nd){
        l = to[l];
        now = max({now + 1, sz[l] - 1});
        if(ansl > max(now,p2.st - dist[l])){
            vertl = l;
            ansl = max(now,p2.st - dist[l]);
        }
    }
    if(vertl == vertr) vertr++;
    cout << vertl << " " << vertr << "\n";
    return 0;
}