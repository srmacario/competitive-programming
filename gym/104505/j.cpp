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
const int N = 5e5+5;

int n, m, vis[N], enabled[N];
vector<pii> adj[N];
vector<int> ans;

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v.st]){
            dfs(v.st);
            if(enabled[v.st]){
                enabled[v.st] ^= 1, enabled[u] ^= 1;
                ans.push_back(v.nd);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for(int i = 1; i <= m; i++){
        cin >> enabled[i];
    }
    for(int i = 1; i <= m; i++){
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= m; i++){
        if(enabled[i]){
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a << " ";
    cout << "\n";
    return 0;
}