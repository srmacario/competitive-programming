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

int t, n, m, vis[N];
ll sz[N];
vector <ll> adj[N], p;

ll dfs(int s){
    sz[s] = 1;
    vis[s] = 1;
    for(auto v: adj[s]){
        if(!vis[v]){
            sz[s] += dfs(v);
        }
    }
    return sz[s];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        cin >> m;
        for(int i=0;i<m;i++){
            ll x;
            cin >> x;
            p.pb(x);
        }
        sort(p.begin(),p.end());
        while(p.size() > n-1){
            ll aux = p.back();
            p.pop_back();
            p.back() = p.back()*aux % MOD;
        }
        dfs(1);
        ll ans = 0;
        vector<ll> prods;
        for(int i=1;i<=n;i++){
            ll aux = sz[i] * (n - sz[i]);
            prods.pb(aux);
        }
        sort(prods.begin(),prods.end());
        for(int i=prods.size()-1;i>=0;i--){
            ll aux = prods[i] % MOD;
            ll mult = 1;
            if(p.size()){
                mult = p.back();
                p.pop_back();
            }
            aux = (aux * mult) % MOD;
            ans = (ans + aux) % MOD;
        }
        cout << ans << "\n";
        for(int i=1;i<=n;i++){
            vis[i] = sz[i] = 0;
            adj[i].clear();
        }
        p.clear();
    }
    return 0;
}