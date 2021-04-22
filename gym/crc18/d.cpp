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

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

typedef vector <int> vi;

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

vi fexp (vi b, ll e) {
    vi ans(1000);
    ans[0] = 1;
    while (e) {
        if (e&1){
            ans = fft::multiply(ans,b); 
            for(int i=0;i<ans.size()-1;i++){
                if(ans[i] >= 10) ans[i+1] += ans[i]/10;
                ans[i] = ans[i]%10;
            }
        }
        b = fft::multiply(b,b);
        for(int i=0;i<b.size()-1;i++){
            if(b[i] >= 10) b[i+1] += b[i]/10;
            b[i] = b[i]%10;
        }
        e >>= 1;
    }   
    return ans;
}

bool gr(vi a, vi b){
    for(int i = a.size()-1; i >= 0; i--){
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return false;
}

int main(){
    int k;
    scanf("%d", &k);
    primes();
    vi fact;
    for(int i = 0; pr[i]*pr[i] <= k; i++){
        while(k%pr[i] == 0){
            k/=pr[i];
            fact.pb(pr[i]);
        }
    }
    if(k > 1) fact.pb(k);
    vi ans(1000);
    ans[0] = 1;
    vi two(1000);
    two[0] = 2;
    int cnt = 0;
    if(fact.size()){
        sort(fact.begin(),fact.end(),greater<int>());
        for(int i = 0, j = 0; i < fact.size(); i++){
            vi b, cur;
            int p = pr[j];
            while(p){
                b.pb(p%10);
                p/=10;
            }
            cur = fexp(b,fact[i]-1);
            vi tmp = fexp(two,cnt + fact[i]-1);
            if(i and gr(two, cur)){
                ans = fft::multiply(ans, tmp);
                for(int i=0;i<ans.size()-1;i++){
                    if(ans[i] >= 10) ans[i+1] += ans[i]/10;
                    ans[i] = ans[i]%10;
                }
                cnt += fact[i]-1;
                continue;
            }
            ans = fft::multiply(ans, cur);
            for(int i=0;i<ans.size()-1;i++){
                if(ans[i] >= 10) ans[i+1] += ans[i]/10;
                ans[i] = ans[i]%10;
            }
            if(!j){
                cnt += fact[i]-1;
            }
            j++;
        }
    }
    bool lzero = true;
    for(int i=ans.size()-1;i>=0;i--){
        if(lzero){
            if(!ans[i] and i) continue;
            else lzero = false;
        }
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}