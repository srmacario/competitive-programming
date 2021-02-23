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
const int N = 2e5+5;

vi adj[N];
int vis[N], par[N], ini, fim, cyc[N];
ll ans;

void dfs(int u){
    vis[u]++;
    for(auto v: adj[u]){
        if(vis[v] and par[u] != v and !ini){
            ini = v, fim = u;
            cyc[v] = cyc[u] = 1;
        }
        if(!vis[v]){
            par[v] = u;
            dfs(v);
        }
    }
}

ll calc(int u){
    vis[u]++;
    ll cnt = 1;
    for(auto v: adj[u]){
        if(vis[v] == 1){
            if(cyc[u] and cyc[v]) continue;
            cnt += calc(v);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ans = (n)*(n-1);
        for(int i=1;i<=n;i++){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        while(fim != ini){
            fim = par[fim];
            cyc[fim] = 1;
        }
        for(int i=1;i<=n;i++){
            if(vis[i] == 1){
                ll tmp = calc(i);
                ans -= ((tmp)*(tmp-1))/2;
            }
        }
        for(int i=1;i<=n;i++){
            adj[i].clear();
            vis[i] = par[i] = cyc[i] = 0;
        }
        ini = fim = 0;
        cout << ans << "\n";
    }
    return 0;
}