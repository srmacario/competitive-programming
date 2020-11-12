#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e4+5;

ll n,m,k,ini,dist[N], par[N], cnt[N];
vector <pll> adj[N];

void dijkstra(ll s){
    for(int i=0;i<N;i++) dist[i] = LINF;
    priority_queue <pll> pq;
    dist[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        ll ud = -pq.top().st;
        ll u = pq.top().nd;
        pq.pop();
        if(dist[u] < ud) continue;
        for (auto x: adj[u]){
            ll v = x.st;
            ll w = x.nd;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = 1;
                pq.push({-dist[v],v});
            }
            else if(dist[v] == dist[u] + w){
                cnt[v]++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    ll last;
    for(ll i=0;i<k;i++){
        ll x;
        cin >> x;
        if(!i) ini = last = x;
        else par[x] = last, last = x;
    }
    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    ll v = last;
    dijkstra(ini);
    //cout << v << " ";
    while(par[v]){
        if(cnt[v] > 1){
            cout << "yes\n";
            return 0;
        }
        //cout << pai[v] << " ";
        v = par[v];
    }
    cout << "no\n";
    return 0;
}
