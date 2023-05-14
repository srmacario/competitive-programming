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
const int N = 1e5+5;

ll d,q,num;
vector <ll> pr,den;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void getprimes(ll n){
    for(ll i=2; i*i <= n;i++){
        //db(i);
        if(n%i == 0) pr.pb(i);
        while(n % i == 0){
            n/=i;
        }
    }
    if(n > 1) pr.pb(n);
}

void factorize(ll n){
    for(int i=0; pr[i]*pr[i] <= n; i++){
        ll aux = 0;
        while(n % pr[i] == 0){
            num++;
            n/=pr[i];
            aux++;
        }
        if(aux) den.pb(aux);
        if(i == pr.size()-1) break;
    }
    if(n > 1) num++;
}

ll fat(ll n){
    if(n <= 1) return 1;
    return (n * fat(n-1) % MOD); 
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d >> q;
    if(d != 1) getprimes(d);
    for(int i=0;i<q;i++){
        num = 0, den.clear();
        ll u,v,top = 1,bot = 1, ans = 1;
        cin >> u >> v;
        if(d == 1){
            cout << "1\n";
            continue;
        }
        factorize(u/gcd(u,v));
        top = fat(num);
        for(int j=0;j<den.size();j++) bot = bot * fat(den[j]) % MOD;
        ans = ans * top % MOD;
        ans = ans * fexp(bot,MOD-2) % MOD;
        num = 0, den.clear(), top = 1, bot = 1;
        factorize(v/gcd(u,v));
        top = fat(num);
        for(int j=0;j<den.size();j++) bot = bot * fat(den[j]) % MOD;
        ans = ans * top % MOD;
        ans = ans * fexp(bot,MOD-2) % MOD;
        cout << ans << "\n";
    }
    return 0;
}