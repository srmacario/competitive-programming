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
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, m, k, l_cur = 1, r_cur, cnt, ans[N];
vector<pii> edges;
vector<piii> queries;

struct DSU {
  vector<int> rank, link;
  vector<int> stk, chkp;
 
  DSU(int n) : rank(2 * n, 0), link(2 * n, -1) {}
 
  int find(int x) {
    while (link[x] != -1) 
      x = link[x];
    return x;
  }
  void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    stk.push_back(a);
    link[a] = b;
    rank[b] += (rank[a] == rank[b]);
    cnt--;
  }
  
  bool Try(int a, int b) {
    if (find(2 * a + 1) == find(2 * b + 1))
      return false;
    return true;
  }
  
  void Unite(int a, int b) {
    chkp.push_back(stk.size());
    unite(2 * a, 2 * b + 1);
    unite(2 * a + 1, 2 * b);
    // assert(find(2 * a) != find(2 * a + 1));
  }
  
  void Undo() {
    for (int i = chkp.back(); i < (int)stk.size(); ++i)
      link[stk[i]] = -1;
    stk.resize(chkp.back());
    int tp = chkp.back();
    chkp.pop_back();
    db(tp);
    if(!chkp.size() or tp != chkp.back()) cnt++;
  }
};
 
struct Upd {
  int type, a, b;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    DSU ds(n);
    cnt = n;
    edges.pb({0, 0});
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.pb({u, v});
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        int l, r;
        cin >> l >> r;
        queries.pb({{l, r}, i});
    }
    sort(queries.begin(), queries.end());
    for(auto q : queries){
        int l = q.st.st, r = q.st.nd;
        while(r_cur < r){
            ds.Unite(edges[r_cur].st, edges[r_cur].nd);
            r_cur++;
        }
        while(l_cur < l){
            ds.Undo();
            l_cur++;
        }
        ans[q.nd] = cnt;
    }
    for(int i = 0; i < k; i++) cout << ans[i] << "\n";
    return 0;
}