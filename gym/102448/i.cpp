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
const int N = 1e6+5;

int n, m, s, mxdp, visnow = 1;
pii dx[4] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
vii vis, dp;

int dfs(int i, int j, int dpth){
    int cnt = 0;
    if(i < 1 or i > n) return cnt;
    if(j < 1 or j > m) return cnt;
    vis[i][j]++;
    // boundaries
    //if depth of position is less than depth that node cant be used
    if(dp[i][j] < dpth) return cnt;
    cnt++;
    //adjacents
    for(int k=0;k<4;k++){
        int nxt_i = i + dx[k].st, nxt_j = j + dx[k].nd;
        if(nxt_i < 1 or nxt_i > n) continue;
        if(nxt_j < 1 or nxt_j > m) continue;
        if(vis[nxt_i][nxt_j] != visnow){
            cnt += dfs(nxt_i, nxt_j, dpth);
        }
    }
    return cnt;
}

int main(){
    scanf("%d %d %d", &s, &n, &m);
    // read
    vis.resize(n+5), dp.resize(n+5);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i].resize(m+5), dp[i].resize(m+5);
            int x;
            scanf("%d",&x);
            //depth of node i, j
            dp[i][j] = x;
            // vis of node i, j
            vis[i][j] = 0;
            mxdp = max(mxdp,x);
        }
    }
    // binary search on size
    int l = 1, r = mxdp;
    while(l < r){
        int val = (l+r+1)/2;
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j] != visnow){
                    // dfs on node
                    ans = max(dfs(i,j,val),ans);
                }
            }
        }
        visnow++;
        if(ans < s) r = val - 1;
        else l = val;
    }
    printf("%d\n", l);
    return 0;
}