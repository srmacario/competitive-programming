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
const int N = 1e4+1;

ll fat[N], sum[N][N], inv[N];

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

void calc(){
    fat[0] = 1;
    inv[0] = fexp(fat[0],MOD-2);
    for(int i=1;i<N;i++){
        fat[i] = (fat[i-1]*i)%MOD;
        inv[i] = fexp(fat[i],MOD-2);
    }
    for(int i=0;i<N;i++){
        sum[i][0] = 1;
        for(long long j=1;j<=i;j++){
            sum[i][j] = (sum[i][j-1] + (((fat[i]*inv[j])%MOD)*inv[i-j])%MOD)%MOD;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b;
    int t;
    cin >> t;
    calc();
    while(t--){
        ll ans = 0;
        cin >> n >> a >> b;
        if(a > n) cout << "0\n";
        else{
            ans = (sum[n][min(n,b)] - sum[n][a-1] + MOD)%MOD;
            cout << ans << "\n";
        }
    }
    return 0;
}