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
const int N = 1e6+5;

vector<int> adj[N], cur[N];
int g[N], ans[N], cnt;

void dfs(int u){
    cur[g[u]].push_back(u);
    cnt += (cur[g[u]].size() == 1);
    ans[u] = cnt;
    for(auto v : adj[u]) dfs(v);
    cur[g[u]].pop_back();
    cnt -= (cur[g[u]].size() == 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i + 1);
    }
    for(int i = 0; i < n; i++){
        cin >> g[i + 1];
    }
    dfs(adj[0].back());
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}