#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 505;

int n, q, cnt, vis[N];
vector<pair<int, ld>> adj[N];
map<string, int> id;

pair<bool, ld> dfs(int u, int t, int dest){
    if(u == dest) return {true, 1.0};
    vis[u] = t;
    for(auto v : adj[u]){
        if(vis[v.st] != t){
            pair<bool, ld> ans = dfs(v.st, t, dest);
            if(ans.st){
                ans.nd *= v.nd;
                return ans;
            }
        }
    }
    return {false, INF};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        string one, from, eq, to;
        ld conv;
        cin >> one >> from >> eq >> conv >> to;
        if(!id.count(from)) id[from] = ++cnt;
        if(!id.count(to)) id[to] = ++cnt;
        adj[id[from]].push_back({id[to], conv});
        adj[id[to]].push_back({id[from], 1.0/conv});
    }
    for(int i = 1; i <= q; i++){
        ld qty;
        string from, cmp, to;
        cin >> qty >> from >> cmp >> to;
        pair<bool, ld> ans = dfs(id[from], i, id[to]);
        if(ans.st){
            cout << setprecision(20) << scientific << (qty * ans.nd) << "\n";
        }
        else cout << "impossible\n";
    }
    return 0;
}