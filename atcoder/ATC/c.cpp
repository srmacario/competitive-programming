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
typedef vector<ll> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 200003;
const int N = 1e5+5;

map <ll,ll> maproot;

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m;
  return r;
}

ll root(ll p) {
  ll n = p-1;
  vector<ll> fact;

  for (int i=2; i*i<=n; ++i) if (n % i == 0) {
    fact.push_back (i);
    while (n % i == 0) n /= i;
  }

  if (n > 1) fact.push_back (n);

  for (int res=2; res<=p; ++res) {
    bool ok = true;
    for (size_t i=0; i<fact.size() && ok; ++i)
      ok &= fexp(res, (p-1) / fact[i], p) != 1;
    if (ok)  return res;
  }

  return -1;
}

namespace fft {
    typedef double dbl;

    struct num {
        dbl x, y;
        num() { x = y = 0; }
        num(dbl x, dbl y) : x(x), y(y) {}
    };

    inline num operator+ (num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator- (num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator* (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }

    int base = 1;
    vector <num> roots = {{0, 0}, {1, 0}};
    vi rev = {0, 1};

    const dbl PI = acosl(-1.0);

    void ensure_base(int nbase) {
        if (nbase <= base) return;

        rev.resize(1 << nbase);
        for (int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        roots.resize(1 << nbase);

        while (base < nbase) {
            dbl angle = 2*PI / (1 << (base + 1));
            for(int i = 1 << (base - 1); i < (1 << base); i++) {
                roots[i << 1] = roots[i];
                dbl angle_i = angle * (2 * i + 1 - (1 << base));
                roots[(i << 1) + 1] = num(cos(angle_i), sin(angle_i));
            }
            base++;
        }
    }

    void fft (vector<num> &a, int n = -1) {
        if (n == -1) {
            n = a.size();
        }
        assert((n & (n-1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for (int i = 0; i < n; i++) {
            if (i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for (int k = 1; k < n; k <<= 1) {
            for (int i = 0; i < n; i += 2*k) {
                for (int j = 0; j < k; j++) {
                    num z = a[i+j+k] * roots[j+k];
                    a[i+j+k] = a[i+j] - z;
                    a[i+j] = a[i+j] + z;
                }
            }
        }
    }

    vector <num> fa, fb;
    vi multiply (vi &a, vi &b) {
        int need = a.size() + b.size() - 1;
        int nbase = 0;
        while ((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        if (sz > (int) fa.size()) {
            fa.resize(sz);
        }
        for (int i = 0; i < sz; i++) {
            int x = (i < (int) a.size() ? a[i] : 0);
            int y = (i < (int) b.size() ? b[i] : 0);
            fa[i] = num(x, y);
        }
        fft(fa, sz);
        num r(0, -0.25/sz);
        for (int i = 0; i <= (sz >> 1); i++) {
            int j = (sz-i) & (sz-1);
            num z = (fa[j]*fa[j] - conj(fa[i]*fa[i]))*r;
            if(i != j) {
                fa[j] = (fa[i]*fa[i] - conj(fa[j]*fa[j]))*r;
            }
            fa[i] = z;
        }
        fft(fa, sz);
        vi res(need);
        for(int i = 0; i < need; i++) {
            res[i] = fa[i].x + 0.5;
        }
        return res;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    //find primitive root
    ll g = root(MOD);
    //precompute '2' exponentials values
    vector <ll> pot(MOD-1);
    pot[0] = 1;
    for(ll i=1;i<MOD-1;i++){
        pot[i] = 2*pot[i-1]%MOD;
    }
    //map g^k%MOD with k
    for(ll i=0;i<MOD-1;i++){
        maproot[pot[i]] = i;
    }
    ll total = 0;
    //vector to count how many are there from some exponent
    vector <ll> cnt(MOD-1);
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        //for each x valid, increment the respective exponent
        if(x) cnt[maproot[x]]++;
        //this algorithm will fft for the answer so we are already subtracting Ai*Ai % MOD
        total -= (x*x)%MOD;
    }
    //fft to count answer
    vector <ll> ans = fft::multiply(cnt,cnt);
    for(ll i=0; i<ans.size();i++){
        if(ans[i]){
            //associate coeficient with respective value
            ll val = pot[i%(MOD-1)];
            total += ans[i]*val;
        }
    }
    // divide by two to only count i<j pairs
    cout << total/2 << "\n";
    return 0;
}