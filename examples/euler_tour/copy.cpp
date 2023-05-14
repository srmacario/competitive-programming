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

ll n, vis[N], frst[N], lst[N], st[8*N], r[N];
vector<ll> adj[N];
map <ll,ll> val;

void tour(ll s){
    r[s] = val[s];
    vis[s] = 1;
    for(auto v : adj[s]){
        if(!vis[v]){
            tour(v);
            r[s] = min(r[s], r[v]);
        }
    }
}

void dfs(ll s){
    vis[s] = 1;
    for(auto v : adj[s]) if(!vis[v]) dfs(v);
    cout << s;
    if(s!=1) cout << " ";
}

bool cmp(ll u, ll v){
    return r[u] < r[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(ll i=1;i<n;i++){
        ll u;
        cin >> u;
        adj[u].pb(i+1), adj[i+1].pb(u);
    }
    for(ll i=1;i<=n;i++){
        ll u;
        cin >> u;
        val[i] = u;
    }
    tour(1);
    for(ll i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end(),cmp);
    memset(vis,0,sizeof(vis));
    dfs(1);
    cout << "\n";
    return 0;
}