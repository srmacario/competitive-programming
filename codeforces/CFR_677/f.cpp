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
const int N = 75;

int n,m,k;
int mat[N][N], memo[N][N][N], best[N][N], f[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    //presetting dp
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> mat[i][j];
    //calculating each row dp (row, mod, qtd)
    for(int r=0;r<n;r++){
        //with zero qt, sum 0 always reachable
        for(int j=0;j<k;j++) memo[r][j][0] = 0;
        for(int i=0;i<m;i++){
            for(int l=i;l>=0;l--){
                //bottom up dp
                for(int j=0;j<k;j++){
                    // if -1 means cant reach mod j using l itens (from 0 to i) 
                    if(memo[r][j][l] == -1) continue;
                    //else, we can reach so we try to add i-th value to the sum and see if it is bigger
                    int sum = mat[r][i] + memo[r][j][l];
                    memo[r][sum%k][l+1] = max(memo[r][sum%k][l+1],sum);
                }
            }
        }
        //getting better answer for each row, on each mod, using no more than m/2 itens
        for(int j=0;j<k;j++){
            for(int l=0;l<=m/2;l++){
                best[r][j] = max(best[r][j],memo[r][j][l]);
            }
        }
    }
    int ans = 0;
    //second dp, iterate through each row, adding to the sum and gettin maximum
    for(int r=0;r<n;r++){
        for(int j=0;j<k;j++){
            for(int i=0;i<k;i++){
                int sum = best[r][j];
                if(r) sum += f[r-1][i];
                f[r][sum%k] = max({sum,f[r][sum%k]});
            }
        }
        ans = max(ans,f[r][0]);
    }
    cout << ans << "\n";
    return 0;
}