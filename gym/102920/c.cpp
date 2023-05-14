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

int vis[N], cnt[N], ans;
vector<pii> adj[N];
set <int> s;

int dfs(int u){
    vis[u] = 1;
    if(s.count(u)) cnt[u]++;
    for(auto p : adj[u]){
        int v = p.nd;
        if(!vis[v]){
            cnt[u] |= dfs(v);
        }
    }
    return cnt[u];
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int a = 0; a< n-1; a++){
        int i, j, w;
        scanf("%d%d%d", &i, &j, &w);
        adj[i].pb({w,j});
        adj[j].pb({w,i});
    }
    int root = 0;
    for(int i = 0; i < k; i++){
        int ap;
        scanf("%d", &ap);
        if(!root) root = ap;
        s.insert(ap);
    }
    dfs(root);
    for(int i = 1; i <= n; i++) ans += cnt[i];
    printf("%d\n", ans);
    return 0;
}