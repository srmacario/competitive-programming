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
const int N = 105;

int n;
ll dp[10][11][N][N], freq[10], C[N][N], inv[N];

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

ll calc(int dig, int mod, int pos, int neg){
    if(dig == 10){
        if(!mod) return 1;
        else return 0;
    }
    if(~dp[dig][mod][pos][neg]) return dp[dig][mod][pos][neg];
    ll resp = 0;
    for(int i=0;i<=freq[dig];i++){
        ll p = i, n = freq[dig]-i;
        if(p > pos or n > neg) continue;
        resp = (resp + (((C[pos][p]*C[neg][n])%MOD)*calc(dig+1, (mod+dig*(n-p)+11)%11, pos-p, neg-n)%MOD))%MOD;
    }
    return dp[dig][mod][pos][neg] = resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    for(int i=0;i<N;i++) C[i][0] = 1;
    for(int i=1;i<N;i++) inv[i] = fexp(i, MOD-2, MOD);
    for(int i=0;i<N;i++){
        for(int j=1;j<=i;j++){
            C[i][j] = (((C[i][j-1]*(i-j+1))%MOD)*inv[j])%MOD;
        }
    }
    while(cin >> s){
        n = s.size();
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++) freq[s[i]-'0']++;
        ll ans = 0;
        for(int i=1;i<10;i++){
            freq[i]--;
            memset(dp,-1,sizeof(dp));
            ans = (ans + calc(0,i%11, n/2, n/2 - !(n%2)))%MOD;
            freq[i]++;
        }
        cout << ans << "\n";
    }
    return 0;
}