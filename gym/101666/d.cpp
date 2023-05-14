#include <bits/stdc++.h>
 
using namespace std;
 
#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 1e5 + 5;
ll dist[N];
vector<pll> adj[N];
ll a, b, w, m, par[N], vis[N];
map <pll,bool> forb;

void dijkstra(ll s){
    priority_queue <pll> pq;
    for(ll i=0;i<N;i++) dist[i] = LINF;
    dist[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        ll ud = -pq.top().st;
        ll u = pq.top().nd;
        pq.pop();
        if(dist[u] < ud) continue;
        for(auto x : adj[u]){
            ll v = x.st;
            ll w = x.nd;
            if((dist[v] > dist[u] + w)){
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({-dist[v],v});
            }
        }
    }
}

void dfs(ll s){
    vis[s] = 1;
    for(auto v : adj[s]) if(!vis[v.st] and !forb[{s,v.st}]){
        par[v.st] = s;
        dfs(v.st);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n >> m;
    for(ll i=0;i < m; i++){
        cin >> a >> b >> w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
        par[b] = a;
        par[a] = b; 
    }
    ll now = 1;
    dijkstra(1);
    for(ll i=0;i<n;i++){
        if(i == 1) continue;
        forb[{i, par[i]}] = true;
    }
    for(ll i=0;i<N;i++) par[i] = LINF;
    dfs(0);
    if(par[1] == LINF){
        cout << "impossible\n";
        return 0;
    }
    now = 1;
    vector<ll> ans;
    while(now){
        ans.pb(now);
        now = par[now];
    }
    cout << ans.size() + 1 << " 0 ";
    for(ll i=ans.size()-1;i>=0;i--){
        cout << ans[i];
        if(i) cout << " ";
    }
    cout << "\n";
    return 0;
}