#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll fat[N], inv[N];

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll comb(ll n, ll k){
    return (((fat[n] * inv[n - k]) % MOD) * inv[k]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    fat[0] = inv[0] = 1;
    fat[1] = inv[1] = 1;
    for(int i = 2; i <= n; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
        inv[i] = (fexp(fat[i], MOD - 2));
    }
    ll ans = 0;
    for(int i = 0; i <= min(n, k); i++){
        ans = (comb(n, i) + ans) % MOD;
    }
    cout << ans << "\n";
    return 0;
}