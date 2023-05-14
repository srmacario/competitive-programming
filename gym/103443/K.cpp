#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6+5;

int t, sz_a, sz_b;
ull pr = 313;
vector<ull> p, ha, hb;
string a, b;

int ans[N];

ull fhash(int l, int r) {
  if (l < 0) return 0;
  if (r < 0) return 0;
  if (r >= sz_b) return 0;
  if (l == 0) {
    return hb[r];
  }
  return hb[r] - hb[l-1] * p[r-l+1];
}

ull calc_hash(int i, int sz) {
    if (sz <= i) return hb[sz-1];
    if (sz <= i + sz_a) {
        int pass = sz - i;
        return fhash(0,i-1) * p[pass] + ha[pass-1];
    }

    int pass = sz - i - sz_a;
    return fhash(0, i-1) * p[sz_a + pass] + ha.back() * p[pass] + fhash(i, i+pass-1);
}

char get_char(int i, int j) {
    if (j < i) return b[j];
    if (j < i + sz_a) return a[j-i];
    return b[j-sz_a];
}

bool less_than(int i, int j) {
    int l = 1, r = sz_a + sz_b, mid;
    while (l != r) {
        mid = (l + r) / 2;
        if (calc_hash(i, mid) == calc_hash(j, mid)) l = mid + 1;
        else r = mid;
    }

    if (calc_hash(i, l) != calc_hash(j, l)) l--;
    if (l == sz_a + sz_b) return i > j;
    return get_char(i, l) < get_char(j, l);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> a >> b;

        sz_a = (int)a.size();
        sz_b = (int)b.size();

        for (int i = 0; i <= sz_b; i++) ans[i] = i;

        p.resize(sz_a + sz_b + 1);
        p[0] = 1;
        for (int i = 1; i <= sz_a + sz_b; i++) {
            p[i] = pr * p[i-1];
        }
        
        ha.resize(sz_a);
        ha[0] = a[0];

        for (int i = 1; i < sz_a; i++) {
            ha[i] = ha[i-1] * pr + a[i];
        }

        hb.resize(sz_b);
        hb[0] = b[0];

        for (int i = 1; i < sz_b; i++) {
            hb[i] = hb[i-1] * pr + b[i];
        }

        //for (int i = 0; i <= sz_b; i++) {
        //    for (int j = i+1; j <= sz_b; j++) {
        //        if (!less_than(ans[i], ans[j])) swap(ans[i], ans[j]);
        //    }
        //}

        sort(ans, ans + sz_b + 1, less_than);

        ll resp = 0, pow = 1;
        for (int i = 0; i <= sz_b; i++) {
            ll aux = (pow * ans[i]) % MOD;
            resp += aux;
            if (resp >= MOD) resp -= MOD;
            pow = (pow * 1234567ll) % MOD;
        }

        cout << resp << "\n";
    }

    return 0;
}