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
const int N = 4e6+5;

int r, g, b, k;
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fat[0] = inv[0] = 1;
    fat[1] = inv[1] = 1;
    for(int i = 2; i < N; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
        inv[i] = fexp(fat[i], MOD - 2);
    }
    cin >> r >> g >> b >> k;
    r -= k, g -= k;
    ll ans = (((fat[k + g + b] * inv[k]) % MOD) * ((inv[g] * inv[b]) % MOD)) % MOD;
    ans = (ans * ((fat[k + b + r] * ((inv[r] * inv[k + b]) % MOD)) % MOD)) % MOD;
    cout << ans << "\n";
    return 0;
}