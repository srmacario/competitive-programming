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
const int N = 1e3+5;

ld memo[2][N][N];

ld dp(int c, int p, int b){
    if(memo[c][p][b]!=-1) return memo[c][p][b];
    if(b<0 or p<0) return memo[c][p][b] = 0;
    if(c){
        if(b==0) return memo[c][p][b] = 0;
        if(p==0) return memo[c][p][b] = 1;
        return memo[c][p][b] = ((ld)b/(p+b) + ((ld)p/(p+b))*dp(0,p-1,b));
    }
    else{
        if(b==0) return memo[c][p][b] = 0;
        if(p==0) return memo[c][p][b] = 0;
        return memo[c][p][b] = (((ld)p/(p+b))*(dp(1,p-1,b-1)*((ld)b/(p+b-1)) + dp(1,p-2,b)*((ld)(p-1)/(p+b-1))));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<=1;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                memo[i][j][k] = -1;
            }
        }
    }
    int p,b;
    cin >> b >> p;
    cout << setprecision(10) << dp(1,p,b) << "\n";
    return 0;
}