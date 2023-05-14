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
const int N = 1e6+5;

// Sieve of Erasthotenes
ll fat[N], invfat[N];

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll comb(int n, int k){
    return (((fat[n] * invfat[n - k]) % MOD) * invfat[k]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fat[0] = invfat[0] = 1;
    for(ll i = 1; i < N; i++){
        fat[i] = (i * fat[i - 1]) % MOD;
        invfat[i] = fexp(fat[i], MOD - 2);
    }
    int t;
    cin >> t;
    while(t--){
        ll l, r, g, ans = 0;
        cin >> l >> r;
        //found pot2  
        ll lb = 1, pot2 = 0;
        while((lb * 2) * l <= r){
            lb *= 2;
            pot2++;
        }
        ans += ((r / lb) - l + 1);
        ll cur = pot2, pot3 = 0;
        //find pot3
        while(cur and (lb / 2) * 3 * l <= r){
            pot3++, cur--;
            lb = (lb / 2) * 3;
            ans = (ans + ((r/lb - l + 1) * comb(pot2, pot3)) % MOD) % MOD;
        }
        cout << pot2  + 1 << " " << ans << "\n";
    }
    return 0;
}
/*
    (n )               n
    k * (n - k)       (k + 1) * (n - k + 1)
*/