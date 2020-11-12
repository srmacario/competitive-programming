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

int n, vis[N], frst[N], lst[N], st[8*N], r[N], cnt = 1, par[N], ans;
vi adj[N], ett;
map <int,int> val, vert, num;

void tour(int s){
    num[s] = cnt;
    r[s] = val[s];
    ett.pb(val[s]);
    frst[s] = ett.size()-1;
    vis[s] = 1;
    for(auto v : adj[s]){
        if(!vis[v]){
            cnt++;
            tour(v);
            r[s] = min(r[s], r[v]);
        }
    }
    ett.pb(val[s]);
    lst[s] = ett.size()-1;
}

void build (int p, int l, int r) {
    if (l == r) {st[p] = ett[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] = v; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) st[p] = min(st[2*p], st[2*p+1]);
}

void dfs(int s){
    int minv = 0, minp = INF;
    minp = query(1,1,2*n,frst[s]+1,lst[s]-1);
    if(minp == INF){
        ans = s;
        update (1, 1, 2*n, frst[s], INF);
        update (1, 1, 2*n, lst[s], INF);
        return;
    }
    else{
        ll v = vert[minp];
        dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ett.pb(0);
    for(int i=1;i<n;i++){
        ll u;
        cin >> u;
        adj[u].pb(i+1);
        par[i+1] = u;
    }
    for(int i=1;i<=n;i++){
        ll u;
        cin >> u;
        val[i] = u;
        vert[u] = i;
    }
    tour(1);
    build(1,1,2*n);
    while(ans!=1){
        dfs(1);
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}