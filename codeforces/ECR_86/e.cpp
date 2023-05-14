#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 2e5+5;

ll fat[N];

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e%2) ans = (ans*b) % MOD;
        b = (b*b) % MOD;
        e/=2;
    }
    return ans;
}

ll C(ll n, ll k){
    ll den = (fat[k] * fat[n-k]) % MOD;
    return (fat[n] * fexp(den,MOD - 2)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k > n){
        cout << "0\n";
        return 0;
    }
    for(int i=0;i<=n;i++){
        if(!i) fat[i] = 1;
        else fat[i] = (i*fat[i-1])% MOD;
        //db(fat[i]);
    }
    for(int i=0;i<=n-k;i++){
        ll temp = (C(n-k,i) * fexp((n - k - i),n))% MOD;
        ans = ((i%2 ? -temp : temp) + ans + MOD) % MOD;
        //db(ans);
    }
    ans = (ans * C(n,n-k)) % MOD;
    //db(ans);
    if(k) ans = (ans*2) % MOD;
    cout << ans << "\n";
    return 0;
}