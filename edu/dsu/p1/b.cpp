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
const int N = 3e5+5;

int par[N], sz[N], sum[N], mx[N], mn[N];

int find(int a){return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    sum[a] += sum[b];
    mx[a] = max(mx[a], mx[b]);
    mn[a] = min(mn[a], mn[b]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = sum[i] = mn[i] = mx[i] = i, sz[i] = 1;
    for(int i = 0; i < m; i++){
        string op;
        int u, v;
        cin >> op;
        if(op == "union"){
            cin >> u >> v;
            unite(u,v);
        }
        else{
            cin >> u;
            u = find(u);
            cout << mn[u] << " " << mx[u] << " " << sz[u] << "\n";
        }
    }
    return 0;
}