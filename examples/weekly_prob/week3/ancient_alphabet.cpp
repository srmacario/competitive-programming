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
const int N = 1e5+5;

ll n,m,s[2][N];
ll invm;

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%MOD;
        b = (b*b)%MOD;
        e/=2;
    }
    return ans;
}

ll dp(int i){
    if(i == n) return 0;
    if(s[0][i]){
        if(s[1][i]){
            if(s[1][i] == s[0][i]) return dp(i+1);
            else if(s[1][i] > s[0][i]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return (((s[0][i]-1) * invm)%MOD + (((1ll*invm)%MOD)*dp(i+1)%MOD))%MOD;
        }
    }
    else{
        if(s[1][i]){
            return (((m - s[1][i]) * invm)%MOD + (((1ll*invm)%MOD)*dp(i+1)%MOD))%MOD;
        }
        else{
            return (((m-1) * (invm * fexp(2,MOD-2)%MOD)%MOD)%MOD + (((1ll*invm)%MOD)*dp(i+1)%MOD))%MOD;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    invm = fexp(m,MOD-2);
    for(int i=0;i<2;i++) for(int j=0;j<n;j++) cin >> s[i][j];
    cout << dp(0) << "\n";
    return 0;
}