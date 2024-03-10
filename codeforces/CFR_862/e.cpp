#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, col[N], ans[N], sz[N], par[N], cnt[N], tot[N];
bool big[N];
map<int, int> id;
vector<int> adj[N];
set<int> two_tot({0}), two_cur({0});
map<pii, int> edge_id;

void count_size(int u){
    if(++tot[col[u]] == 2) two_tot.insert(col[u]);
    for(auto v : adj[u]){
        if(v != par[u]){
            par[v] = u;
            count_size(v);
            sz[u] += sz[v];
        }
    }
    sz[u]++;
}

void add(int u, int x){
    if(cnt[col[u]] == 1 and x == 1) two_cur.insert(col[u]);
    if(cnt[col[u]] == 2 and x == -1) two_cur.erase(col[u]);
    
    if(tot[col[u]] == 1 and x == -1) two_tot.insert(col[u]);
    if(tot[col[u]] == 2 and x == 1) two_tot.erase(col[u]);

    cnt[col[u]] += x;
    tot[col[u]] -= x;
    for(auto v : adj[u])
        if(v != par[u] and !big[v])
            add(v, x);
}

void dfs(int u, bool keep){
    pii big_child = {-1, -1};
    
    //find big child
    for(auto v : adj[u])
        if(v != par[u])
            big_child = max(big_child, make_pair(sz[v], v));

    //go through small childs, but reseting the colors
    for(auto v : adj[u])
        if(v != par[u] and v != big_child.nd)
            dfs(v, 0);
    
    //go through big child, keeping the color
    if(big_child.nd != -1)
        dfs(big_child.nd, 1), big[big_child.nd] = true; //big_child marked to not repeat in next dfs
    
    //now our colors have everything from big_child, we need to count again from small child
    add(u, 1);

    //now we have all the colors on this subtree
    ans[edge_id[{min(u, par[u]), max(u, par[u])}]] = max(*two_tot.rbegin(), *two_cur.rbegin());

    //unmark big child
    if(big_child.nd != -1) big[big_child.nd] = 0;

    //if small child, its time to reset
    if(keep == 0)
        add(u, -1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_id[{min(u, v), max(u, v)}] = i;
    }
    vector<int> colors;
    for(int i = 1; i <= n; i++){
        cin >> col[i];
        colors.push_back(col[i]);
    }
    sort(colors.begin(), colors.end());
    colors.resize(unique(colors.begin(), colors.end()) - colors.begin());
    for(int i = 0; i < colors.size(); i++) id[i + 1] = colors[i];
    for(int i = 1; i <= n; i++) col[i] = lower_bound(colors.begin(), colors.end(), col[i]) - colors.begin() + 1;
    count_size(1);
    dfs(1, 1);
    for(int i = 1; i < n; i++) cout << id[ans[i]] << "\n";
    return 0;
}