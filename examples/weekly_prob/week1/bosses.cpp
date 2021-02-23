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
const int N = 3e5+5;

int n, m, dist[N], vis[N], ord[N], cmp[N], par[N], ordn, cnt;
vi adj[N], adjn[N];
set <pii> edges;

void dfs(int s){
    vis[s] = 1;
    for(auto v : adj[s]) if(!vis[v]) par[v] = s, dfs(v);
    ord[ordn++] = s;
}

void revdfs(int s){
    vis[s] = 0;
    cmp[s] = cnt;
    for(auto v : adj[s]) if(vis[v] and s != par[v]) revdfs(v);
}

void markdfs(int s){
    vis[s] = 1;
    for(auto v : adj[s]){
        if(!vis[v]){
            adjn[cmp[v]].pb(cmp[s]);
            adjn[cmp[s]].pb(cmp[v]);
            markdfs(v); 
        }
    }
}

void bfs(int s){
    cl(dist,63);
    dist[s] = 0;
    queue<int>q;
    q.push(s);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : adjn[u]) {
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[y].pb(x);
        adj[x].pb(y);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) par[i] = i, dfs(i);
    for(int i=ordn-1;i>=0;i--) if(vis[ord[i]]) cnt++, revdfs(ord[i]);
    for(int i=1;i<=n;i++) if(!vis[i]) markdfs(i);
    bfs(1);
    pii mx = {0,0};
    for(int i=1;i<=cnt;i++) mx = max({mx,{dist[i],i}});
    bfs(mx.nd);
    mx = {0,0};
    for(int i=1;i<=cnt;i++) mx = max({mx,{dist[i],i}});
    printf("%d\n",mx.st);
    return 0;
}