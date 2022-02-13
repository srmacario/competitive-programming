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
const int N = 1e5+5;

vi adj[N], adjt[N];

//kosaraju
int n, ordn, cnt, vis[N], ord[N], cmp[N], out[N], in[N], eul_cmp[N], qtd[N];

void dfs(int u) {
  vis[u] = 1;
  for (auto v : adj[u]) if (!vis[v]) dfs(v);
  ord[ordn++] = u;
}

void dfst(int u) {
  cmp[u] = cnt, vis[u] = 0;
  qtd[cnt]++;
  if(out[u] != in[u]) eul_cmp[cnt] = 1;
  for (auto v : adjt[u]) if (vis[v]) dfst(v);
}

map<int, int> id, revid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = n;
        id.clear(), revid.clear();
        set<int> num;
        vector<pair<int, int>> edge;
        for(int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            edge.push_back({u, v});
            num.insert(u);
            num.insert(v);
        }
        int x = 1;
        //map each node from 1...n
        for(auto u : num) id[u] = x, revid[x++] = u;
        for(auto e : edge){
            int u = e.st, v = e.nd;
            adj[id[u]].push_back(id[v]);
            adjt[id[v]].push_back(id[u]);
            out[id[u]]++;
            in[id[v]]++;
        }
        //new n
        n = num.size();
        //kosaraju
        for (int i = 1; i <= n; ++i){
            if(out[i] > in[i]) ans += out[i] - in[i];
            if (!vis[i]) dfs(i);
        }
        for (int i = ordn - 1; i >= 0; --i) if (vis[ord[i]]) cnt++, dfst(ord[i]);
        //look for connected components which only has out = in
        for (int i = 1; i <= cnt; i++){
            if(!eul_cmp[i] and qtd[i] > 1){
                ans++;
            }
        }
        //reset
        for(int i = 1; i <= n; i++) vis[i] = cmp[i] = out[i] = in[i] = 0, adj[i].clear(), adjt[i].clear();
        for(int i = 1; i <= cnt; i++) eul_cmp[i] = qtd[i] = 0;
        for (int i = ordn - 1; i >= 0; --i) ord[i] = 0;
        cnt = ordn = 0;
        cout << ans << "\n";
    }
    return 0;
}