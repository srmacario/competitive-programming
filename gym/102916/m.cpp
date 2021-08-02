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
const int N = 5e5+5;

int n, vis[N], ok;
vi adj[N];
map<int, int> memo[N], max_tree[N], min_tree[N];

piii dfs(int u, int par){
    if(memo[u].count(par)) return {memo[u][par],{max_tree[u][par], min_tree[u][par]}};
    vi child;
    for(auto v : adj[u]){
        if(v == par) continue;
        child.pb(v);
    }
    sort(child.begin(), child.end());
    if(child.size() == 0){
        return {memo[u][par] = 1, {max_tree[u][par] = u, min_tree[u][par] = u}};
    }
    else if(child.size() == 1){
        piii nxt = dfs(child[0], u);
        if(child[0] < u){
            if(nxt.st == 1 and nxt.nd.st < u){
                return {memo[u][par] = 1, {max_tree[u][par] = max(nxt.nd.st, u), min_tree[u][par] = min(nxt.nd.nd, u)}};
            }
            else{
                return {memo[u][par] = 0, {max_tree[u][par] = 0, min_tree[u][par] = 0}};
            }
        }
        else{
            if(nxt.st == 1 and nxt.nd.nd > u){
                return {memo[u][par] = 1, {max_tree[u][par] = max(nxt.nd.st, u), min_tree[u][par] = min(nxt.nd.nd, u)}};
            }
            else{
                return {memo[u][par] = 0, {max_tree[u][par] = 0, min_tree[u][par] = 0}};
            }
        }
    }
    //else
    piii nxt_l = dfs(child[0], u);
    piii nxt_r = dfs(child[1], u);
    // db(u _ child[0] _ child[1]);
    // db(nxt.)
    if(nxt_l.st == 1 and nxt_r.st == 1 and nxt_l.nd.st < u and nxt_r.nd.nd > u){
        return {memo[u][par] = 1, {max_tree[u][par] = max(nxt_r.nd.st, u), min_tree[u][par] = min(nxt_l.nd.nd, u)}};
    }
    return {memo[u][par] = 0, {max_tree[u][par] = 0, min_tree[u][par] = 0}};
}

int main(){

    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].pb(b);
        adj[b].pb(a);
        if(adj[a].size() == 4 or adj[b].size() == 4) ok = 1;
    }
    if(ok){
        printf("-1\n");
        return 0;
    }
    vi ans;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() > 2) continue;
        piii tmp = dfs(i, 0);
        // db(tmp.st _ tmp.nd.st _ tmp.nd.nd);
        if(tmp.st) ans.pb(i);
    }
    if(!ans.size()) printf("-1");
    for(auto a : ans) printf("%d ", a);
    printf("\n");
    return 0;
}