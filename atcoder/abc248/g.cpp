#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 2e5+5;

int n, a[N], vis[N];
vector<int> adj[N];
map<int, ll> qtd_mdc[N], cost_mdc[N];

ll fexp(ll b, ll e, ll m = MOD){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return ans;
}

void subtree_cost(int u){
    vis[u] = 1;
    cost_mdc[u][a[u]] = qtd_mdc[u][a[u]] = 1;
    for(auto v : adj[u]){
        if(!vis[v]){
            subtree_cost(v);
            for(auto it : qtd_mdc[v]){
                int cur_mdc = __gcd(a[u], it.st);
                cost_mdc[u][cur_mdc] = ((cost_mdc[u][cur_mdc] + it.nd)%MOD + cost_mdc[v][it.st]) % MOD;
                qtd_mdc[u][cur_mdc] = (qtd_mdc[u][cur_mdc] + it.nd)%MOD;
            }
        }
    }
}

void redfs(int u, int par){
    vis[u] = 0;
    if(par != u){
        vector<pair<int, ll>> rem_qtd, rem_cost;
        for(auto it : qtd_mdc[u]){
            int cur_mdc = __gcd(it.st, a[par]);
            rem_qtd.push_back({cur_mdc, it.nd});
            rem_cost.push_back({cur_mdc, (cost_mdc[u][it.st] + (2 * it.nd) % MOD) % MOD});
        }
        for(auto it : qtd_mdc[par]){
            int cur_mdc = __gcd(a[u], it.st);
            cost_mdc[u][cur_mdc] = ((cost_mdc[u][cur_mdc] + it.nd)%MOD + cost_mdc[par][it.st]) % MOD;
            qtd_mdc[u][cur_mdc] = (qtd_mdc[u][cur_mdc] + it.nd) % MOD;
        }
        for(auto p : rem_qtd){
            qtd_mdc[u][p.st] = (qtd_mdc[u][p.st]  - p.nd + MOD) % MOD;
        }
        for(auto p : rem_cost){
            cost_mdc[u][p.st] = (cost_mdc[u][p.st] - p.nd + MOD)%MOD;
        }
    }
    for(auto v : adj[u]){
        if(vis[v]) redfs(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    subtree_cost(1);
    ll ans = 0;
    redfs(1, 1);
    for(int i = 1; i <= n; i++){
        for(auto it : qtd_mdc[i]){
            ans = (ans + (it.st * cost_mdc[i][it.st])%MOD)%MOD;
        }
        ans = (ans - a[i] + MOD) % MOD;
    }
    // db(fexp(2, MOD - 2));
    cout << (ans * fexp(2, MOD - 2))%MOD << "\n";
    return 0;
}