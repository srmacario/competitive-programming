#include <bits/stdc++.h>

using namespace std;

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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

// Regular Tarjan stuff
int n, m, num[N], low[N], cnt, ch[N], art[N];
vector<int> adj[N], st;

int lb[N]; // Last block that node is contained
int bn; // Number of blocks
vector<int> blc[N]; // List of nodes from block

void dfs(int u, int p) {
  num[u] = low[u] = ++cnt;
  ch[u] = adj[u].size();
  st.push_back(u);

  if (adj[u].size() == 1) blc[++bn].push_back(u);

  for(int v : adj[u]) {
    if (!num[v]) {
      dfs(v, u), low[u] = min(low[u], low[v]);
      if (low[v] == num[u]) {
        if (p != -1 or ch[u] > 1) art[u] = 1;
        blc[++bn].push_back(u);
        while(blc[bn].back() != v)
          blc[bn].push_back(st.back()), st.pop_back();
      }
    }
    else if (v != p) low[u] = min(low[u], num[v]), ch[v]--;
  }

  if (low[u] == num[u]) st.pop_back();
}

// Nodes from 1 .. n are blocks
// Nodes from n+1 .. 2*n are articulations
vector<int> bct[2*N]; // Adj list for Block Cut Tree

void build_tree() {
  for(int u=1; u<=n; ++u) for(int v : adj[u]) if (num[u] > num[v]) {
    if (lb[u] == lb[v] or (blc[lb[u]].size() and blc[lb[u]][0] == v)) /* edge u-v belongs to block lb[u] */;
    else { /* edge u-v belongs to block cut tree */;
      int x = (art[u] ? u + n : lb[u]), y = (art[v] ? v + n : lb[v]);
      bct[x].push_back(y), bct[y].push_back(x);
    }
  }
}

void tarjan() {
  for(int u=1; u<=n; ++u) if (!num[u]) dfs(u, -1);
  for(int b=1; b<=bn; ++b) for(int u : blc[b]) lb[u] = b;
  build_tree();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        st.clear();
        for(int i = 0; i <= 2 * n; i++){
            if(i <= n){
                adj[i].clear();
                blc[i].clear();
                num[i] = low[i] = ch[i] = art[i] = lb[i] = 0;
            }
            bct[i].clear();
        }
        cnt = bn = 0;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll l = 0, r = n;
        while(l < r){
            ll mid = (l + r)/2;
            if(mid * mid >= n) r = mid;
            else l = mid + 1;
        }
        if(l * l != n or m != l * (l + 1)){
            cout << "NO\n";
            continue;
        }
        tarjan();
        if(bn == l + 1){
            bool ok = true, art_cmp = false;;
            // for(int i = 1; i <= n; i++) cout << art[i] << " ";
            // cout << "\n";
            for(int i = 1; i <= bn; i++){
                int has_art = 0, all_art = 1;
                for(auto b : blc[i]){
                    // db(b _ art[b]);
                    all_art &= art[b];
                    has_art |= art[b];
                }
                if(blc[i].size() != l){
                    ok = false;
                    break;
                }
                art_cmp |= all_art;
                // cout << "\n";
            }
            if(ok and art_cmp){
                cout << "YES\n";
                continue;
            }
            
        }
        cout << "NO\n";
    }
    return 0;
}