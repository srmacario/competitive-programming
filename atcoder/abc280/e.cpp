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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 2e5+5;

int n, p;
ll fat[N], inv[N], inv_fat[N];

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
    if(k > n) return 0;
    return (((fat[n] * inv_fat[k]) % MOD) * inv_fat[n - k]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    fat[0] = inv[0] = inv_fat[0] = 1;
    for(ll i = 1; i < N; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
        inv_fat[i] = fexp(fat[i], MOD - 2);
        inv[i] = (fexp(i, MOD - 2));
    }
    ll ans = 0;
    if(p == 0){
        cout << n << "\n";
        return 0;
    }
    if(p == 100){
        cout << (n + 1)/2 << "\n";
        return 0;
    }
    for(int i = 0; i <= n; i++){
        ll cur = i + 1;
        int a, b;
        //end with n-1
        b = n - 1 - i;
        a = i - b;
        if(a >= 0 and a <= i and b >= 0 and b <= i){
            cur = (cur * comb(i, a)) % MOD;
            cur = (cur * fexp(p, b)) % MOD;
            cur = (cur * fexp(100 - p, a)) % MOD;
            cur = (cur * fexp(inv[100], a + b)) % MOD;
            // db((n - 1) _ a _ b _ i);
        }
        else cur = 0;
        ans = (ans + cur) % MOD;
        // db(ans);
        cur = i + 1;
        //end with n - 2;
        b = n - 2 - i;
        a = i - b;
        if(a >= 0 and a <= i and b >= 0 and b <= i){
            cur = (cur * comb(i, a)) % MOD;
            cur = (cur * fexp(p, b + 1)) % MOD;
            cur = (cur * fexp(100 - p, a)) % MOD;
            cur = (cur * fexp(inv[100], a + b + 1)) % MOD;
            // db((n - 2) _ a _ b _ i);
        }
        else cur = 0;
        ans = (ans + cur) % MOD;
        // db(ans);
    }
    cout << ans << "\n";
    return 0;
}