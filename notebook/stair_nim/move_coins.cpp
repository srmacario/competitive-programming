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

int n, q, ans, c[N], id[N], mx[N], vis[N], pxor[N], par[N];
vi adj[N];

int dfs(int s, int cnt, int p){
    vis[s] = 1;
    mx[cnt] = cnt;
    id[s] = cnt;
    par[cnt] = p;
    pxor[cnt] = pxor[cnt-1]^c[s];
    if(p) ans ^= c[s];
    for(auto v: adj[s]){
        if(!vis[v]){
            mx[cnt] = dfs(v,mx[cnt]+1,p^1);
        }
    }
    return mx[cnt];
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1,0);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int partans = ans;
        int u,v;
        scanf("%d%d",&u,&v);
        if(id[v] >= id[u] and id[v] <= mx[id[u]]) printf("INVALID\n");
        else{
            if(par[id[u]] == par[id[v]])  partans = partans^pxor[mx[id[u]]]^pxor[id[u]-1];
            if(partans) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}