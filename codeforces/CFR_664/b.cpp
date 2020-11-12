#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 105;

int grid[N][N];

void p(int a, int b){
    cout << a << " " << b << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,sx,sy;
    cin >> n >> m >> sx >> sy;
    grid[sx][sy] = 1, p(sx,sy);
    sx = 1, grid[sx][sy] = 1, p(sx,sy);
    sy = 1, grid[sx][sy] = 1, p(sx,sy);
    for(int i=1;i<=n;i++){
        sx = i;
        if(!grid[sx][sy]) grid[sx][sy] = 1, p(sx,sy);
        if(sy == 1){
            for(int j=1;j<=m;j++){
                sy = j;
                if(!grid[sx][sy]) grid[sx][sy] = 1, p(sx,sy);
            }
        }
        else if(sy == m){
            for(int j=m;j>=1;j--){
                sy = j;
                if(!grid[sx][sy]) grid[sx][sy] = 1, p(sx,sy);
            }
        }
    }
    return 0;
}