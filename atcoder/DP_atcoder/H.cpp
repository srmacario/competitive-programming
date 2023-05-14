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
const int N = 1e3+5;
int h,w;
ll memo[N][N];
char a[N][N];

int dp(int i, int j){
    //cout << "i: " << i << " j: " << j << "\n";
    //if(i<1 or j<1) return 0;
    if(i == 1 and j == 1) return memo[i][j] = 1;
    if(~memo[i][j]) return memo[i][j];
    else{
        ll left = 0, top = 0;
        if(a[i][j-1] == '.') left = dp(i,j-1);
        if(a[i-1][j] == '.') top = dp(i-1,j);
        return memo[i][j] = ((left + top) % MOD);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<N;i++) a[0][i] = a[i][0] = '#';
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> a[i][j];
        }
    }
    ll ans = dp(h,w);
    cout << ans << "\n";
    return 0;
}