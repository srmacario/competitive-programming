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
ll vis[N], par[N], leaf[N], n, S;
map <pll,ll> edgs, cost;

//dfs to set par and count leafs for each node
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

//operator to compare on priority queue
struct cmp{
    bool operator() (const pll &a, const pll &b) const{
        ll difa = a.st*a.nd - (a.st/2)*a.nd;
        ll difb = b.st*b.nd - (b.st/2)*b.nd;
        return difa < difb;
    }
};

vector <ll> cut(ll c){
    ll sum = 0;
    vector <ll> ans;
    priority_queue<pll,vector<pll>,cmp> pq;
    //add edges with cost c on priority queue
    for(ll i=2;i<=n;i++){
        if(par[i] == 0 or cost[{i,par[i]}] != c) continue;
        ll p = leaf[i];
        sum += p*edgs[{i,par[i]}];
        pq.push({edgs[{i,par[i]}],p});
    }
    //create vector ans pushing sum, cutting edge and restarting the process
    ans.pb(sum);
    while(sum > 0 and !pq.empty()){
        pll cur = pq.top();
        pq.pop();
        sum -= cur.st*cur.nd - (cur.st/2)*cur.nd;
        ans.pb(sum);
        pq.push({cur.st/2,cur.nd});
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> S;
        for(ll i=0;i<n-1;i++){
            ll v,u,w,c;
            cin >> u >> v >> w >> c;
            adj[u].pb({w,v});
            adj[v].pb({w,u});
            edgs[{u,v}] = w;
            edgs[{v,u}] = w;
            cost[{u,v}] = c;
            cost[{v,u}] = c;
        }
        dfs(1);
        vector<ll> v1 = cut(1), v2 = cut(2);
        ll cnt = INF, r = v2.size()-1;
        //two pointers iteration
        //if a r works for a l, a r greater than it won't be optimal
        //we can iterate through l and store r, decreasing it, no need to test greater r again (similar to knuth?) 
        for(ll l=0;l<v1.size();l++){
            //vectors are set from greater sum [0] to 0 [size - 1], while sum between 2 and 1 is smaller, decrease r to find a sum < S with less cuts
            while(r > 0 and v1[l] + v2[r-1] <= S) r--;
            if(v1[l] + v2[r] <= S){
                cnt = min(cnt, l + 2*r);
            }
        }
        for(ll i=1;i<=n;i++){
            adj[i].clear();
            vis[i] = par[i] = leaf[i] = 0;
        }
        edgs.clear();
        cost.clear();
        cout << cnt << "\n";
    }
    return 0;
}