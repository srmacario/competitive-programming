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
const int N = 2e5+5;

int t;
ll even_sum[N], tot_sum[N], fact[N], inv[N];

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }
    return ans;
}

void calc(int n){
    for(int i = 0; i <= n; i++){
        if(!i) tot_sum[0] = even_sum[0] = 1;
        ll cur = (fact[n]*( (inv[n-i]*inv[i]) %MOD) )%MOD;
        tot_sum[i] = tot_sum[i-1];
        even_sum[i] = even_sum[i-1];
        tot_sum[i] = (tot_sum[i] + cur)%MOD;
        if(!(i%2)) even_sum[i] = (even_sum[i] + cur)%MOD;
    }
}

int main(){
    scanf("%d", &t);
    fact[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = (i*fact[i-1])%MOD;
    for(int i = 1; i < N; i++) inv[i] = (fexp(fact[i], MOD-2))%MOD;
    while(t--){
        int n, k;
        ll ans = 0;
        scanf("%d %d", &n, &k);
        calc(n);
        ll carry = 1;
        for(int i = 0; i < k; i++){
            if(!(n%2)) ans = (ans + (carry * fexp(tot_sum[n], k - 1 - i))%MOD)%MOD;
            carry = (carry * (even_sum[n] + n%2 - !(n%2)))%MOD;
        }
        ans = (ans + carry)%MOD;
        cout << ans << "\n";
    }
    return 0;
}