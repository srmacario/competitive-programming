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
const int N = 2005;

int h,w;
string grid[N];
ll x[N][N],y[N][N],d[N][N], memo[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for(int i=0;i<h;i++) cin >> grid[i];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(!i and !j){
                memo[i][j] = 1;
                continue;
            }
            if(grid[i][j] == '#'){
                continue;
            }
            if(j) x[i][j] = (x[i][j-1] + memo[i][j-1])%MOD;
            if(i) y[i][j] = (y[i-1][j] + memo[i-1][j])%MOD;
            if(i and j) d[i][j] = (d[i-1][j-1] + memo[i-1][j-1])%MOD;
            memo[i][j] = (x[i][j] + y[i][j] + d[i][j])%MOD;
        }
    }
    cout << memo[h-1][w-1] << "\n";
    return 0;
}