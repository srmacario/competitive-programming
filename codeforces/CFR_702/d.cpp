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
const int N = 105;

int st[4*N], v[N], n, pos[N], h[N];
vi adj[N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void dfs(int l, int r, int cnt){
    int mx = query(1,0,n-1,l,r);
    int m = pos[mx];
    h[m] = cnt;
    if(m != l){
        adj[m].pb(query(1,0,n-1,l,m-1));
        dfs(l,m-1,cnt+1);
    }
    if(m != r){
        adj[m].pb(query(1,0,n-1,m+1,r));
        dfs(m+1,r,cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> v[i];
            pos[v[i]] = i;
        }
        build(1,0,n-1);
        dfs(0,n-1,0);
        for(int i=0;i<n;i++) cout << h[i] << " ";
        cout << "\n";
        for(int i=0;i<n;i++) adj[i].clear();
        memset(st,0,sizeof(st));
        memset(v,0,sizeof(v));
    }
    return 0;
}