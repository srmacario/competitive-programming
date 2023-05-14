#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+9;
const int N = 2e5 + 5;

int k, n, ordn, cnt, vis[N], ord[N], cmp[N], qtd[N];
vi adj[N], adjt[N];
map<pair<string, string>, int> id;

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]) if(!vis[v]) dfs(v);
    ord[ordn++] = u;
}

void dfst(int u){
    // db(u _ cnt);
    if(cmp[u] != cnt) qtd[cnt]++;
    cmp[u] = cnt, vis[u] = 0;
    for(auto v : adjt[u]) if (vis[v]) dfst(v);
}

int calc(int u){
    if(vis[u] != -1) return vis[u];
    if(qtd[cmp[u]] > 1) return vis[u] = qtd[cmp[u]];
    for(auto v : adj[u]){
        vis[u] = 0;
        return vis[u] = calc(v) + 1;
    }
    return vis[u] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    for(int i = 1; i <= k; i++){
        string fam, name, par, t1, t2;
        cin >> fam >> name;
        cin >> t1 >> t2 >> par;
        if(!id[{fam, name}]) id[{fam, name}] = ++n;
        if(!id[{fam, par}]) id[{fam, par}] = ++n;
        adj[id[{fam, name}]].pb(id[{fam, par}]);
        adjt[id[{fam, par}]].pb(id[{fam, name}]);
    }
    // db(n);
    for(int i = 1; i <= n; ++i) if(!vis[i]) dfs(i);
    for(int i = ordn - 1; i >= 0; --i) if(vis[ord[i]]) cnt++, dfst(ord[i]);
    for(int i = 1; i <= n; i++) vis[i] = -1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, calc(i));
        // db(vis[i] _ qtd[cmp[i]]);
    }
    cout << ans << "\n";
    return 0;
}