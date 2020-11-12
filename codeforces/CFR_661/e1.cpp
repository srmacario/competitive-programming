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
const int N = 1e5+5;

vector<pll> adj[N];
ll vis[N], par[N], leaf[N];
map <pll,ll> edgs;

ll dfs(ll u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v.nd]){
            par[v.nd] = u;
            leaf[u] += dfs(v.nd);
            vis[u]++;
        }
    }
    if(vis[u] == 1) leaf[u] = 1;
    return leaf[u];
}

struct cmp{
    bool operator() (const pll &a, const pll &b) const{
        ll difa = a.st*a.nd - (a.st/2)*a.nd;
        ll difb = b.st*b.nd - (b.st/2)*b.nd;
        return difa < difb;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n, S;
        cin >> n >> S;
        for(ll i=0;i<n-1;i++){
            ll v,u,w;
            cin >> u >> v >> w;
            adj[u].pb({w,v});
            adj[v].pb({w,u});
            edgs[{u,v}] = w;
            edgs[{v,u}] = w;
        }
        dfs(1);
        ll sum = 0;
        priority_queue<pll,vector<pll>,cmp> pq;
        for(ll i=2;i<=n;i++){
            if(par[i] == 0) continue;
            ll p = leaf[i];
            sum += p*edgs[{i,par[i]}];
            pq.push({edgs[{i,par[i]}],p});
        }
        ll cnt = 0;
        while(sum > S){
            pll cur = pq.top();
            pq.pop();
            sum -= cur.st*cur.nd - (cur.st/2)*cur.nd;
            pq.push({cur.st/2,cur.nd});
            cnt++;
        }
        for(ll i=1;i<=n;i++){
            adj[i].clear();
            vis[i] = par[i] = leaf[i] = 0;
        }
        edgs.clear();
        cout << cnt << "\n";
    }
    return 0;
}