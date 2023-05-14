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
const int N = 2e3+5;

int n,m,q,k;
ll grid[N][N], w[N], v[N], dp[N];

int main(){
    scanf("%d%d%d%d",&n,&m,&q,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&grid[i][j]);
            grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
        }
    }
    for(int i=1;i<=q;i++){
        int li,lj,ri,rj;
        scanf("%d%d%d%d",&li,&lj,&ri,&rj);
        w[i] = grid[ri][rj] + grid[li-1][lj-1] - grid[ri][lj-1]-grid[li-1][rj];
        v[i] = (ri-li+1)*(rj-lj+1);
    }
    for(int i=1;i<=q;i++){
        for(int j = k; j>=w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    printf("%lld\n",dp[k]);
    return 0;
}