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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 3e5+5;

ll f[N];
map <int,int> id;
ll n, k;

void fact(){
    f[0] = 1;
    for(int i=1;i<=n;i++){
        f[i] = (i * f[i-1])  % MOD;
    }
}

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

ll inv (ll a) {
    return fexp(a, MOD-2, MOD);
}

ll comb(ll m, ll n){
    ll den = (f[n] * f[m-n]) % MOD;
    ll ans = ((f[m]*inv(den)) % MOD)%MOD;
    return (ans%MOD);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    fact();
    vector <pii> lamp(n);
    set<int> e;
    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        e.insert(l), e.insert(r);
        lamp[i] = {l,r};
    }
    int cnt = 1;
    for(auto u : e){
        id[u] = cnt++;
    }
    vector<pii> eve;
    for(int i=0;i<n;i++){
        pii x = lamp[i];
        lamp[i] = {id[x.st],id[x.nd]};
        pii ini = {id[x.st],-(i+1)};
        pii fim = {id[x.nd],(i+1)};
        eve.pb(ini);
        eve.pb(fim);
    }
    sort(eve.begin(),eve.end());
    int on = 0;
    ll ans = 0;
    for(auto u : eve){
        if(u.nd < 0){
            if(on >= k-1){
                ll partans = comb(on,k-1);
                ans = (ans + partans)%MOD;
            }
            on++;
        }
        else on--;
    }
    cout << ans << "\n";
    return 0;
}