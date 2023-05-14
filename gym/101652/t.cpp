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
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9, MOD = 1e9+7;
const int N = 1e3+5;

int n, m, k, s, t, vis[N];
vector<piii> adj[N];
set<piii> ans[N];

void in(set<piii> ss, int l, int r, int i) {
  vector<piii> add, rem;
  auto it = ss.lower_bound({{l, 0}, 0});
  if(it != ss.begin()) it--;
  for(; it != ss.end(); it++) {
    int ll = it->st.st;
    int rr = it->st.nd;
    int idx = it->nd;

    if(ll > r) break;
    if(rr < l) continue;
    if(ll < l) add.push_back({{ll, l-1}, idx});
    if(rr > r) add.push_back({{r+1, rr}, idx});
    rem.push_back(*it);
  }
  add.push_back({{l, r}, i});
  for(auto x : rem) ss.erase(x);
  for(auto x : add) ss.insert(x);
}

set<piii> dfs(int u){
    if(vis[u]){
        return ans[u];
    }
    vis[u] = 1;
    set<piii> nxt;
    for(auto v : adj[u]){
        nxt = dfs(v.nd);
        for(auto s : nxt){
            int nxt_l = max(s.st.st, v.st.st), nxt_r = min(s.st.nd, v.st.nd);
            if(nxt_r >= nxt_l){
                in(u, nxt_l, nxt_r, 0);
            }
        }
    }
    return ans[u];
}

void dfs(int u, set<piii> carry){
    vis[u] = 1;
    for(auto v : adj[u]){
        set<piii> prox;
        for(auto c : carry){
            int nxt_l = max(c.st.st, v.st.st), nxt_r = min(c.st.nd, v.st.nd);
            if(nxt_r >= nxt_l){
                in(prox, nxt_l, nxt_r, 0);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k >> s >> t;

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({{c, d}, b});
    }
    vis[t] = 1;
    in(t, 1, k, 0);
    dfs(s);
    int tot = 0;
    for(auto x : ans[s]) tot += x.st.nd - x.st.st + 1;
    cout << tot << "\n";
    return 0;
}