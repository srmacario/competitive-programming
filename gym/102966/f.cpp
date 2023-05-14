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
const int N = 1e5+5;

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

ll S(ll n){
    ll dif = ((( ( ((n*n)%MOD) * (n-1) )%MOD)*fexp(2,MOD-2))%MOD - ((((((n-1)*n)%MOD)*((2*n-1+MOD)%MOD))%MOD)*fexp(6,MOD-2))%MOD + MOD) % MOD;
    return dif;    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(cin >> n){
        cout << ((n*n)%MOD)*((4*S(3*n))%MOD + (10*S(n))%MOD)%MOD << "\n";
    }
    return 0;
}