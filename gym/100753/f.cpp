#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef pair<int,pii>piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector <int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+1;

vector<ll> v;

ll gcd(ll a, ll b){ return b ? gcd(b, a%b) : a; }

ll mulmod(ll a,  ll b, ll mod){
    ll ans = 0;
    while(b){
        if(b&1) ans = (ans + a) % mod;
        a = (a+a) % mod;
        b /= 2;
    }
    return ans;
}

ll fexp(ll b, ll e, ll mod){
    ll ans = 1;
    while(e){
        if(e&1) ans = mulmod(ans, b, mod);
        b = mulmod(b, b, mod);
        e /= 2;
    }
    return ans;
}

bool miller (ll a, ll n){
    if(a >= n) return 1;
    ll s = 0, d = n-1;
    while (d%2 == 0 and d) d >>=1, s++;
    ll x = fexp(a,d,n);
    if(x == 1 or x == n-1) return 1;
    for(int r = 0; r < s; r++, x = mulmod(x,x,n)){
        if(x == 1) return 0;
        if(x == n-1) return 1;
    }
    return 0;
}

bool isprime(ll n){
    ll base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int i=0; i < 12; ++i) if(!miller(base[i],n)) return 0;
    return 1;
}

ll pollard(ll n){
    ll x, y, d, c = 1;
    if(n%2 == 0) return 2;
    while(1){
        y = x = 2;
        while(1){
            x = mulmod(x,x,n); x = (x-c)%n;
            y = mulmod(y,y,n); y = (y-c)%n;
            y = mulmod(y,y,n); y = (y-c)%n;
            d = gcd(abs(n+y-x), n);
            if(d == n) break;
            else if (d > 1) return d;
        }
        c++;
    }
}

void fator(ll n){
    if(isprime(n)){v.pb(n); return;}
    ll f = pollard(n);
    fator(f); fator(n/f);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    if(x == 1){
        cout << "1\n";
        return 0;
    }
    fator(x);
    ll last = 0, sum = 1, cnt = 1;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(v[i] == 0 or v[i] == 1) continue;
        if(v[i] != last){
            if(last){
                //db(sum);
                cnt *= ++sum;
                sum = 1;
            }
        }
        else{
            sum++;
        }
        last = v[i];
        //cout << v[i] << " ";
    }
    cnt*=++sum;
    cout << cnt << "\n";

    return 0;
}
