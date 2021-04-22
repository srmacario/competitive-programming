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
const int N = 1e6+5;

vi adj[N];
ll n, m, q, tin[N], tout[N], t, root, sub[N], st[4*N], lazy[4*N], vis[N];

void dfs(int s){
    tin[s] = ++t;
    for(auto v : adj[s]){
        if(!tin[v]){
            dfs(v);
        }
    }
    tout[s] = t;
}

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += (r-l+1)*lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

ll query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j, ll k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
}

void revdfs(int s){
    vis[s] = 1;
    for(auto v : adj[s]){
        if(!vis[v]){
            revdfs(v);
            sub[s] += sub[v];
        }
    }
    update(1,1,n,tin[s],tin[s],sub[s]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        adj[p].pb(i);
        if(!p) root = i;
    }
    dfs(root);
    for(int i = 0; i < m; i++){
        int op, e, v;
        cin >> op >> e >> v;
        if(op == 1){
            update(1,1,n,tin[e],tin[e],v);
        }
        if(op == 2){
            sub[e] += v;
        }
    }
    revdfs(root);
    for(int i = 0; i < q; i++){
        int op, e;
        cin >> op >> e;
        if(op == 1){
            cout << query(1,1,n,tin[e],tin[e]) << "\n";
        }
        if(op == 2){
            cout << query(1,1,n,tin[e],tout[e])<< "\n";
        }
    }
    return 0;
}