#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

vector<int> adj[N];
int vis[N], min_leaf[N], par[N], root;
bool rooted = false;

bool cmp(int a, int b){
    return min_leaf[a] < min_leaf[b];
}

//calculate minimum leaf in subtree
void dfs_min(int u){
    vis[u] = 1;
    if(adj[u].size() == 1) min_leaf[u] = u;

    for(auto v : adj[u]){
        if(!vis[v]){
            par[v] = u;
            dfs_min(v);
            min_leaf[u] = min(min_leaf[u], min_leaf[v]);
        }
    }
}

void calc(int u){
    // db(u);
    if(adj[u].size() == 1 and root != u){
        cout << u << " ";
        return;
    }

    //go through all neighbours
    for(int i = 1; i + 1 < adj[u].size(); i++) calc(adj[u][i]);

    //last neighbour, decide this node comes from this neighbour or if it goes to it
    if(u < min_leaf[adj[u].back()] and !rooted){
        cout << u << " ";
        calc(adj[u].back());
    }
    else{
        rooted = true;
        calc(adj[u].back());
        cout << u << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        //reset
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            vis[i] = 0;
            min_leaf[i] = INF;
            par[i] = 0;
            rooted = false;
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //choose root of dfs, it will be the minimum leaf because the minimum leaf will be the first to be printed
        for(int i = 1; i <= n; i++){
            if(adj[i].size() == 1){
                root = i;
                break;
            }
        }
        dfs_min(root);
        for(int i = 1; i <= n; i++){
            // db(i _ min_leaf[i]);
            //puts parent to be the first in adjacency list
            for(int j = 0; j < adj[i].size(); j++){
                if(adj[i][j] == par[i]) swap(adj[i][j], adj[i][0]);
            }
            //sort rest of the list
            sort(adj[i].begin() + 1, adj[i].end(), cmp);
        }
        calc(root);
        cout << "\n";
    }
    return 0;
}