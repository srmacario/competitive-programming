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
const int N = 1e7+5;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

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

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a = mulmod(a,a,m)) if (b&1) r=mulmod(r,a,m);
  return r;
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
  int base[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (int i = 0; i < 12; ++i) if (!miller(base[i], n)) return 0;
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

map<ll,int> fact;

void factor(ll n) {
    if(n == 1) return;
    if (isprime(n)){
        fact[n]++;
        return;
    }
    ll f = pollard(n);
    factor(f), factor(n/f);
}

int main(){
    ll n;
    FILE *arq , *in;
    in = fopen("little.in","r");
    arq = fopen("little.out","w");
    fscanf(in,"%lld", &n);
    factor(n);
    if((fact.size() == 1 and fact[2]) or (!fact.size())){
        fprintf(arq,"-1\n");
        fclose(in), fclose(arq);
        return 0;
    }
    map<ll,ll> div;
    div[1] = 1;
    for(auto u: fact){
        for(int j=0;j<u.nd;j++){
            map <ll,ll> aux;
            aux = div;
            for(auto v: div){
                aux[v.st*u.st]++;
            }
            div = aux;
        }
    }
    vector <vector<ll>> ans;
    for(auto u : div){
        if(u.st == 1 or u.st == 2) continue;
        ll cnt1 = 0, cnt2 = 0;
        ll n_tmp = n;
        while(!(n_tmp%u.st)){
            n_tmp /= u.st;
            cnt1++;
        }
        if(n_tmp == 1){
            vector <ll> tmp;
            for(int i=0;i<cnt1;i++) tmp.pb(u.st);
            ans.pb(tmp);
        }
        else if(div[u.st - 1]){
            while(!(n_tmp%(u.st-1))){
                n_tmp /= (u.st-1);
                cnt2++;
            }
            if(n_tmp == 1){
                vector <ll> tmp;
                for(int i=0;i<cnt1;i++) tmp.pb(u.st);
                for(int i=0;i<cnt2;i++) tmp.pb(u.st-1);
                ans.pb(tmp);
            }
        }
    }
    ll k = ans.size();
    fprintf(arq, "%lld\n", k);
    for(int i=0;i<ans.size();i++){
        k = ans[i].size();
        fprintf(arq, "%lld ", k);
        for(int j = 0;j < ans[i].size();j++) fprintf(arq,"%lld ",ans[i][j]);
        fprintf(arq,"\n");
    }
    fclose(in), fclose(arq);
    return 0;
}