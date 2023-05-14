#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 205, M = 1e5+5;

int c[N], w[N], v[N], vis[N], cnt, DSP[N], PPP[N],D,P,R,B, dp[M];
vi adj[N];

void dfs(int s){
    vis[s] = cnt;
    if(s <= D) DSP[cnt]++;
    else PPP[cnt]++;
    for(auto v : adj[s]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int knapD(){
    cl(w,0);
    cl(v,0);
    cl(dp,0);
    int ans = D;
    for(int i=1;i<=D+P;i++){
        if(DSP[vis[i]] < PPP[vis[i]]){
            w[vis[i]] += c[i];
            if(i <= D) v[vis[i]] -= 1;
            else v[vis[i]] += 1;
        }
    }
    for(int i=1;i<cnt;i++){
        for(int j = M-1;j >= w[i];j--){
            dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
        }
    }
    ans += dp[B];
    return ans;
}

int knapP(){
    cl(w,0);
    cl(v,0);
    cl(dp,0);
    int ans = P;
    for(int i=1;i<=D+P;i++){
        if(DSP[vis[i]] > PPP[vis[i]]){
            w[vis[i]] += c[i];
            if(i > D) v[vis[i]] -= 1;
            else v[vis[i]] += 1;
        }
    }
    for(int i=1;i<cnt;i++){
        for(int j = M-1;j >= w[i];j--){
            dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
        }
    }
    ans += dp[B];
    return ans;
}

int main(){
    scanf("%d%d%d%d",&D,&P,&R,&B);
    for(int i=1;i<=D;i++) scanf("%d",&c[i]);
    for(int i=1;i<=P;i++) scanf("%d",&c[i+D]);
    for(int i=1;i<=R;i++){
        int u,v;
        scanf("%d%d",&u, &v);
        adj[u].pb(v+D);
        adj[v+D].pb(u);
    }
    cnt = 1;
    for(int i=1;i<=D+P;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    printf("%d %d\n", knapD(), knapP());
    return 0;
}