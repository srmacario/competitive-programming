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

int n;
string s;
ll h[N], invh[N], p[N], invp[N];

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

void pre(){
    p[0] = 1, p[1] = 1777771;
    invp[0] = 1, invp[1] = fexp(p[1], MOD - 2);
    for(int i = 2; i < N; i++){
        p[i] = (p[i - 1] * p[1]) % MOD;
        invp[i] = fexp(p[i], MOD - 2);
    }
}

void calc_hash(){
    for(int i = 0; i < n; i++){
        h[i] = (s[i] - 'a') * p[i] % MOD;
        if(i) h[i] = (h[i - 1] + h[i]) % MOD;
    }
    for(int i = n - 1; i >= 0; i--){
        invh[i] = (s[i] - 'a') * p[n - 1 - i] % MOD;
        invh[i] = (invh[i + 1] + invh[i]) % MOD;
    }
}

int bins(int l, int r){
    int sz_l = 0, sz_r = n;
    while(sz_l < sz_r){
        int sz = (sz_l + sz_r + 1) / 2;
        if((r - 1 + sz >= n) or (l + 1 - sz < 0) or ((h[r - 1 + sz] - h[r - 1]) * invp[r - 1] != (invh[l + 1 - sz] - invh[l + 1]) * invp[n - 1 - (l + 1)])) sz_r = sz - 1;
        else sz_l = sz;
    }
    return sz_l;
}

ll calc(int l, int r){
    db(l _ r);
    int sz = bins(l, r);
    db(l _ r _ sz);
    if(l - sz >= 0 and r + sz < n){
        sz++;
        sz += bins(l - sz, r + sz);
    }
    db(l _ r _ sz);
    ll ans = (r + sz - (l - sz) - 1 + 1) / 2;
    db(ans);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    pre();
    calc_hash();
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += calc(i - 1, i + 1);
        ans += calc(i, i + 1);
    }
    cout << ans << "\n";
    return 0;
}