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
const int N = 2e5+5;

int n, cnt, ing[N], vis[N];
map<string, int> id;
vector<int> adj[N];

bool dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(vis[v]) return false;
        dfs(v);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        string u, v;
        cin >> u >> v;
        if(!id.count(u)) id[u] = ++cnt;
        if(!id.count(v)) id[v] = ++cnt;
        adj[id[v]].push_back(id[u]);
        ing[id[u]]++;
    }
    vector<int> dfs_list;
    for(int i = 1; i <= cnt; i++) if(!ing[i]) dfs_list.push_back(i);
    bool ok = true;
    for(auto u : dfs_list) if(!dfs(u)) ok = false;
    for(int i = 1; i <= cnt; i++) if(!vis[i]) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

/*
    b -> m
    m -> d

    z -> y -> x
    d -> c -> b -> a


*/