#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n,k,f[N],vis[N],cur[N],id[N],vis1[N], cycle[N], dp[N];
vi adj[N];

int dfs(int i, int d){
    vis[i] = 1;
    for(auto u:adj[i]) if(!vis[u]) d = dfs(u,d+1);
    return d;
}

void dfs_cycle(int i){
    if(cur[f[i]]){
        cycle[i] = cycle[f[i]] = id[i] - id[f[i]] + 1;
    }
    else if(!vis1[f[i]]){
        cur[f[i]] = vis1[f[i]] = 1;
        id[f[i]] = id[i] + 1;
        dfs_cycle(f[i]);
    }
    cur[i] = 0;
    cycle[i] = cycle[f[i]];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> f[i];
        adj[i].pb(f[i]);
        adj[f[i]].pb(i);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cur[i] = vis1[i] = 1;
            id[i] = 1;
            dfs_cycle(i);
        }
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int l = cycle[i];
            int r = dfs(i,1);
            for(int j=N-1;j>=0;j--){
                for(int x=l;x<=r;x++){
                    if(j-x >= 0) dp[j] |= dp[j-x];
                }
            }
        }
    }
    for(int i=k;i>=0;i--)
        if(dp[i]){
            cout << i << "\n";
            return 0;
        }

    return 0;
}