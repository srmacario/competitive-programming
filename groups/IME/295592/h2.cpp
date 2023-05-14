#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef unsigned long long ll;
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

ll gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }

ll addmod(ll a, ll b, ll m) {
    if(a >= m - b) return a + b - m;
    return a + b;
}

ll mulmod(ll a, ll b, ll m) {
    ll ans = 0;
    while (b) {
    if (b&1) ans=addmod(ans, a, m);
    a=addmod(a, a, m);
    b>>=1;
    }
    return ans;
}

ll fexp (ll b, ll e, ll m) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b)% m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}


bool miller(ll a, ll n) {
    if (a >= n) return 1;
    ll s = 0, d = n-1;
    while (d%2 == 0 and d) d >>= 1, s++;
    ll x = fexp(a, d, n);
    if (x == 1 or x == n-1) return 1;
    for (int r = 0; r < s; r++, x = mulmod(x,x,n)) {
    if (x == 1) return 0;
    if (x == n-1) return 1;
    }
    return 0;
}

bool isprime(ll n) {
    if(n == 1) return 0;
    int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < 10; ++i) if (!miller(base[i], n)) return 0;
    return 1;
}

ll pollard(ll n) {
    ll x, y, d, c = 1;
    if (n%2==0) return 2;
    while (1) {
    y = x = 2;
    while (1) {
        x = addmod(mulmod(x,x,n), c, n);
        y = addmod(mulmod(y,y,n), c, n);
        y = addmod(mulmod(y,y,n), c, n);
        d = gcd(abs(x-y), n);
        if (d == n) break;
        else if (d > 1) return d;
    }
    c++;
    }
}

void factor(ll n, vector<ll>& v) {
    if (n == 1 or isprime(n)) return v.pb(n);
    ll f = pollard(n);
    factor(f, v), factor(n/f, v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll c;
    vector <ll> fact;
    cin >> c;
    factor(c, fact);
    ll d = 1;
    sort(fact.begin(), fact.end());
    ll last = fact[0];
    ll cnt = 1;
    for(int i=1;i<fact.size();i++){
        if(fact[i] == last){
            cnt++;
        }
        else{
            if(cnt%2) d *= last;
            cnt = 1;
        }
        last = fact[i];
    }
    if(cnt%2) d *= last;
    cout << d << "\n";
    return 0;
}