#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+9;
const int N = 5e5+5;

ull h[N], p[N], inv[N];
ull pr = 1777771;

void build(string &s) {
    p[0] = 1, p[1] = pr;
    for(int i = 1; i <= s.size(); i++) {
        h[i] = ((p[1] * h[i - 1]) + s[i - 1]);
        p[i] = (p[1] * p[i - 1]);
    }

    for(int i = s.size(); i >= 1; i--){
        inv[i] = ((p[1] * inv[i + 1]) + s[i - 1]);
    }
}

// 1-indexed
ull fhash(int l, int r) {
  return (h[r] - ((h[l - 1] * p[r - l + 1])));
}

ull invhash(int l, int r) {
  return (inv[l] - ((inv[r + 1] * p[r - l + 1])));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    cin >> n >> m >> s;
    bool ok = false;
    build(s);
    for(int i = 0; i + m <= n; i++){
        if(fhash(i + 1, i + m/2) == invhash(i + 1 + (m + 1)/2, i + m)) ok = true;
    }
    cout << (ok ? "Accept" : "Reject") << "\n";
    return 0;
}