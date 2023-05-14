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

int n, vis[N], rev_vis[N];
vector<int> adj[N], rev_adj[N];
set<int> trapped, unreachable;
map<int, int> id_order;

void dfs(int u){
    vis[u] = 1;
    unreachable.erase(u);
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void rev_dfs(int u){
    rev_vis[u] = 1;
    trapped.erase(u);
    for(auto v : rev_adj[u]){
        if(!rev_vis[v]){
            rev_dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int u, k;
        cin >> u >> k;
        id_order[i] = u;
        for(int j = 0; j < k; j++){
            int v;
            cin >> v;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }
        trapped.insert(u), unreachable.insert(u);
    }
    rev_dfs(0);
    for(auto p : id_order)
        if(trapped.count(p.nd))
            cout << "TRAPPED " << p.nd << "\n";
    dfs(0);
    for(auto p : id_order)
        if(unreachable.count(p.nd))
            cout << "UNREACHABLE " << p.nd << "\n";
    if(!trapped.size() and !unreachable.size()) cout << "NO PROBLEMS\n";
    return 0;
}