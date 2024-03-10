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

ll fat[N], invfat[N], prod[N];

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
    if(n < k) return 0;
    return (((fat[n] * invfat[n - k]) % MOD) * invfat[k]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fat[0] = fat[1] = invfat[0] = invfat[1] = prod[0] = prod[1] = 1;
    for(int i = 2; i < N; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
        invfat[i] = fexp(fat[i], MOD - 2);
        prod[i] = (prod[i - 1] * (2 * i - 1)) % MOD;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(m == 0){
            cout << "1\n";
            continue;
        }
        if(m > n){
            cout << "0\n";
            continue;
        }
        if(m == n){
            cout << (fat[m - 1] * invfat[2]) % MOD << "\n";
            continue;
        }
        ll ans = 0;
        for(int i = 1; i <= n - m; i++){
            ll tmp = 1;
            tmp = (tmp * comb(n, n - m - i)) % MOD;
            tmp = (tmp * fat[m - i]) % MOD;
            tmp = (tmp * comb(m - 1, i - 1)) % MOD;
            tmp = (tmp * comb(m + i, 2 * i)) % MOD;
            tmp = (tmp * prod[i]) % MOD;
            ans = (ans + tmp) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}