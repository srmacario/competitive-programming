#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define endl '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5, L = 20;

struct seg_tree {
    int n;
    vector<long long> lz, st;
    seg_tree(int n_ = 1) {
        n = n_;
        lz.resize(4 * n);
        st.resize(4 * n);
    }
    void push(int p, int l, int r) {
        if(lz[p]) {
            st[p] += lz[p] * (r - l + 1);
            if(l != r) {
                lz[2 * p] += lz[p];
                lz[2 * p + 1] += lz[p];
            }
            lz[p] = 0;
        }
    }
    long long query(int i, int j) {
        return query(i, j, 1, 1, n);
    }
    long long query(int i, int j, int p, int l, int r) {
        push(p, l, r);
        if(l > j or r < i) return 0;
        if(l >= i and j >= r) return st[p];
        return query(i, j, 2 * p, l, (l + r) >> 1) + query(i, j, 2 * p + 1, ((l + r) >> 1) + 1, r);
    }
    void update(int i, int j, long long v) {
        return update(i, j, v, 1, 1, n);
    }
    void update(int i, int j, long long v, int p, int l, int r) {
        push(p, l, r);
        if(l > j or r < i) return;
        if(l >= i and j >= r) {
            lz[p] += v;
            push(p, l, r);
            return;
        }
        update(i, j, v, 2 * p, l, (l + r) >> 1);
        update(i, j, v, 2 * p + 1, ((l + r) >> 1) + 1, r);
        st[p] = st[2 * p] + st[2 * p + 1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, qq;
    cin >> n >> qq;
    vector<vector<int>> adj(n + 1), up(L, vector<int>(n + 1));
    vector<vector<pair<int, int>>> fq(n + 1);
    vector<vector<vector<pair<int, int>>>> sq(n + 1, vector<vector<pair<int, int>>>(n + 1));
    vector<int> q(qq), ans(qq), sz(n + 1), h(n + 1);
    int root = -1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(!x) {
            root = i;
            continue;
        }
        up[0][i] = x;
        adj[x].push_back(i);
    }
    for(int i = 1; i < L; i++) {
        for(int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    for(int i = 0; i < qq; i++) {
        cin >> q[i];
        q[i]--;
        ans[i] += (q[i] / n) * n * n;
        fq[(q[i] / n) + 1].emplace_back(q[i] % n, i);
    }
    seg_tree seg(n);
    function<void(int)> dfs_sz = [&](int u) {
        sz[u] = 1;
        for(auto e : adj[u]) {
            h[e] = h[u] + 1;
            dfs_sz(e);
            sz[u] += sz[e];
        }
    };
    dfs_sz(root);
    seg.update(root, root, sz[root]);
    function<int(int, int)> prv = [&](int a, int b) {
        if(a == b) return a;
        if(h[a] > h[b]) swap(a, b);
        int dff = h[b] - h[a] - 1, cnt = 0;
        while(dff) {
            if(dff & 1) {
                b = up[cnt][b];
            }
            cnt++;
            dff >>= 1;
        }
        if(up[0][b] == a) return b;
        b = up[0][b];
        for(int i = L - 1; i >= 0; i--) {
            if(up[i][a] != up[i][b]) {
                a = up[i][a];
                b = up[i][b];
            }
        }
        return a;
    };
    function<void(int)> dfsfq = [&](int u) {
        for(auto [qqq, i] : fq[u]) {
            int l = 1, r = n, res = -1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(seg.query(1, mid) > qqq) {
                    res = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] += (res - 1) * n;
            sq[res][prv(res, u)].emplace_back(qqq - seg.query(1, res - 1), i);
        }
        for(auto e : adj[u]) {
            seg.update(e, e, sz[e]);
            seg.update(u, u, -sz[e]);
            dfsfq(e);
            seg.update(e, e, -sz[e]);
            seg.update(u, u, sz[e]);
        }
    };
    dfsfq(root);
    vector<indexed_set> v(n + 1);
    function<void(int, bool)> dfssq = [&](int u, bool keep) {
        int mx = -1, bc = -1;
        for(auto e : adj[u]) {
            if(mx < sz[e]) {
                mx = sz[e];
                bc = e;
            }
        }
        for(auto e : adj[u]) {
            if(e != bc) {
                dfssq(e, false);
            }
        }
        if(bc != -1) {
            dfssq(bc, true);
            swap(v[u], v[bc]);            
        }
        indexed_set cur;
        for(auto e : adj[u]) {
            if(e != bc) {
                
            }
        }
    };
    dfssq(root, false);
    for(int i = 0; i < qq; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}