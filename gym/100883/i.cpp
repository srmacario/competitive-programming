#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 100+5;

ll dist[N];
vector <pll> adj[N];
priority_queue <pll> pq;
//int par[N];

void dijkstra (ll s) {
    for(int i=0;i<105;i++) dist[i] = LINF;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll ud = -pq.top().st;
        ll u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.nd;
            ll w = x.st;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        for(int i=0;i<105;i++) adj[i].clear();
        vector <plll> tp;
        ll x,y,p,dx,dy;
        ll n;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x >> y >> p;
            tp.pb({p,{x,y}});
        }
        pll bg, end;
        cin >> x >> y;
        bg = {x,y};
        cin >> x >> y;
        end = {x,y};
        dx = abs(bg.st - end.st), dy = abs(bg.nd - end.nd);
        adj[100].pb({dx+dy,101});
        adj[101].pb({dx+dy,100});
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(i==j) continue;
                dx = abs(tp[i].nd.st - tp[j].nd.st);
                dy = abs(tp[i].nd.nd - tp[j].nd.nd);
                if(dx*dx+dy*dy <= tp[i].st*tp[i].st) adj[i].pb({2,j});
                else adj[i].pb({dx+dy,j});
                if(dx*dx+dy*dy <= tp[j].st*tp[j].st) adj[j].pb({2,i});
                else adj[j].pb({dx+dy,i});
            }
            dx = abs(tp[i].nd.st - bg.st);
            dy = abs(tp[i].nd.nd - bg.nd);
            adj[100].pb({dx+dy,i});
            adj[i].pb({dx+dy,100});
            dx = abs(tp[i].nd.st - end.st);
            dy = abs(tp[i].nd.nd - end.nd);
            adj[101].pb({dx+dy,i});
            adj[i].pb({dx+dy,101});
            
        }
        dijkstra(100);
        cout << dist[101] << "\n";
    }
    return 0;
}