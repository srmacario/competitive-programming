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

int n, id[N], revid[N], mx[N], v[N], cnt, st[4*N], lazy[4*N];
vi adj[N];

void dfs(int s){
    id[s] = ++cnt;
    revid[cnt] = s;
    for(auto v : adj[s]){
        if(!id[v]) dfs(v);
    }
    mx[id[s]] = cnt;
}

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[p] = 0;
    }
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j);
    update(2*p+1, (l+r)/2+1, r, i, j);
    st[p] = st[2*p] + st[2*p+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=2;i<=n;i++){
        int p;
        cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cin >> v[id[i]];
    build(1,1,n);
    int q;
    cin >> q;
    while(q--){
        string s;
        int val;
        cin >> s >> val;
        if(s == "get") cout << query(1,1,n,id[val],mx[id[val]]) << "\n";
        else update(1,1,n,id[val],mx[id[val]]);
    }
    return 0;
}