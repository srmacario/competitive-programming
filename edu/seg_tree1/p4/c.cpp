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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

// Segment Tree (range query and point update)
// Update - O(log n)
// Query - O(log n)
// Memory - O(n)

struct Node {
  ll val;
 
  Node(ll _val = 0) : val(_val) {}
  Node(const Node& l, const Node& r) : val(l.val + r.val) {}
 
  friend ostream& operator<<(ostream& os, const Node& a) {
    os << a.val;
    return os;
  }
};
 
template <class T = Node, class U = int>
struct SimpleSegTree {
  int n;
  vector<T> st;
 
  SimpleSegTree(int _n) : n(_n), st(4 * n) {}
 
  SimpleSegTree(vector<U>& v) : n((int)v.size()), st(4 * n) {
    build(v, 1, 0, n - 1);
  }
 
  void build(vector<U>& v, int p, int l, int r) {
    if (l == r) { st[p] = T(v[l]); return; }
    int mid = (l + r) / 2;
    build(v, 2 * p, l, mid);
    build(v, 2 * p + 1, mid + 1, r);
    st[p] = T(st[2 * p], st[2 * p + 1]);
  }
 
  T query(int i, int j, int p, int l, int r) {
    if (l >= i and j >= r) return st[p];
    if (l > j or r < i) return T();
    int mid = (l + r) / 2;
    return T(query(i, j, 2 * p, l, mid), query(i, j, 2 * p + 1, mid + 1, r));
  }
 
  T query(int i, int j) { return query(i, j, 1, 0, n - 1); }
 
  void update(int idx, U v, int p, int l, int r) {
    if (l == r) { st[p] = T(v); return; }
    int mid = (l + r) / 2;
    if (idx <= mid) update(idx, v, 2 * p, l, mid);
    else update(idx, v, 2 * p + 1, mid + 1, r);
    st[p] = T(st[2 * p], st[2 * p + 1]);
  }
 
  void update(int idx, U v) { update(idx, v, 1, 0, n - 1); }
};

vector<SimpleSegTree<>> seg_sum, seg_inv;

int n, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seg_sum.push_back(SimpleSegTree(0)), seg_inv.push_back(SimpleSegTree(0));
    for(int i = 1; i <= 40; i++){
        seg_sum.push_back(SimpleSegTree(N));
    }

    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        seg_sum[v[i]].update(i, 1);
    }
    
    for(int i = 0; i < q; i++){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){

        }
        else{

        }
    }
    return 0;
}