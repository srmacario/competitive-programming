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

int p[N];
vector<int> adj[N];
vector<ll> adj_score[N];
ll s[N], tot;

ll dfs(int u, ll k){
    tot += k * s[u];
    if(!adj[u].size()){
        return s[u];
    }
    int lft = k % adj[u].size();
    for(auto v: adj[u]){
        adj_score[u].push_back(dfs(v, k / adj[u].size()));
    }
    sort(adj_score[u].begin(), adj_score[u].end(), greater<ll>());
    for(int i = 0; i < lft; i++) tot += adj_score[u][i];
    return adj_score[u][lft] + s[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) adj[i].clear(), adj_score[i].clear();
        for(int i = 2; i <= n; i++){
            cin >> p[i];
            adj[p[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++) cin >> s[i];
        tot = 0;
        dfs(1, k);
        cout << tot << "\n";
    }
    return 0;
}