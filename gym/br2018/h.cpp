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
typedef pair<pll, pll> pllll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, vis[N];
vector<plll> adj[N];
ll dist[N], cost[N], ans;
pll par[N];

void dijkstra(int s){
    priority_queue <plll> pq;
    for(int i=0;i<N;i++) cost[i] = dist[i] = par[i].nd = LINF;
    dist[s] = 0;
    cost[s] = 0;
    par[s] = {0,0};
    vis[0] = 1;
    pq.push({0,{0,s}});
    while(!pq.empty()){
        ll ud = -pq.top().st;
        ll uc = -pq.top().nd.st;
        int u = pq.top().nd.nd;
        pq.pop();
        if(dist[u] < ud) continue;
        for(auto x : adj[u]){
            int v = x.nd.nd;
            ll w = x.st;
            ll c = x.nd.st;
            if(dist[v] > dist[u] + w){
                par[v] = {u,c};
                dist[v] = dist[u] + w;
                cost[v] = cost[u] + c;
                pq.push({-dist[v],{-cost[v],v}}); 
            }
            else if(dist[v] == dist[u] + w){
                if(par[v].nd > c){
                    par[v] = {u,c};
                    dist[v] = dist[u] + w;
                    cost[v] = cost[u] + c;
                    pq.push({-dist[v],{-cost[v],v}}); 
                }
            }
        }
    }
}

void revdfs(int u){
    vis[u] = 1; 
    ans+= par[u].nd; 
    if(!vis[par[u].st])revdfs(par[u].st);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m; i++){
        int a, b, l, c;
        scanf("%d%d%d%d",&a, &b, &l, &c);
        adj[a].pb({l, {c, b}});
        adj[b].pb({l, {c, a}});
    }    
    dijkstra(1);
    for(int i=1;i<=n;i++){
        if(!vis[i]) revdfs(i);
    }
    cout << ans << "\n";
    return 0;
}