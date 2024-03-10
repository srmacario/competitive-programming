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
const int N = 1e5+5;

map <int, int> c[N]; 
vi adj[N];
int col[N], par[N];
pair<int,ll> dom[N], ans[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    int root = b;
    if ((a = find(a)) == (b = find(b))) return;
    ans[root] = dom[b];
    if (c[a].size() < c[b].size()) swap(a, b);
    par[b] = a;
    for(auto m : c[b]){
        c[a][m.st] += m.nd;
        if(c[a][m.st] > dom[a].st){
            dom[a].st = c[a][m.st];
            dom[a].nd = m.st;
        }
        else if(c[a][m.st] == dom[a].st){
            dom[a].nd += 1ll*m.st;
        }
    }
    c[b].clear();
}

void dfs(int u){
    dom[u] = {1, col[u]};
    pair<int, int> big = {-1, -1};
    int p = -1;
    for(auto v : adj[u]){
        if(!dom[v].st){
            dfs(v);
            int b = find(v);
            big = max(big, make_pair((int)c[b].size(), v));
        }
        else p = v;
    }
    if(big.st != -1){
        unite(u, big.nd);
        for(auto v : adj[u]){
            if(v != big.nd and v != p){
                unite(u, v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> col[i];
        c[i][col[i]]++;
        par[i] = i;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    ans[1] = dom[find(1)];
    for(int i=1;i<=n;i++){
        cout << ans[i].nd << " ";
    }
    cout << "\n";
    return 0;
}