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

vector<int> adj[N];
int cnt[2][N], color[N], ans[N];

void dfs(int u){
    cnt[color[u]][u]++;
    for(auto v : adj[u]){
        dfs(v);
        cnt[0][u] += cnt[0][v];
        cnt[1][u] += cnt[1][v];
        ans[u] += ans[v];
    }
    // db(u _ cnt[0][u] _ cnt[1][u]);
    if(cnt[1][u] == cnt[0][u]) ans[u]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        vector<int> par(n + 1);
        int root = 1;
        for(int i = 2; i <= n; i++){
            cin >> par[i];
            adj[par[i]].push_back(i);
            // db(par[i] _ i);
        }
        cin >> s;
        for(int i = 0; i < n; i++){
            if(s[i] == 'B') color[i + 1] = 1;
        }
        dfs(root);
        cout << ans[root] << "\n";
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            cnt[0][i] = cnt[1][i] = 0;
            color[i] = 0;
            ans[i] = 0;
        }
    }
    return 0;
}