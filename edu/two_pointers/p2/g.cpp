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

int n;
ll s, st[4*N], v[N], ans = LINF;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

void build (int p, int l, int r) {
    if (l == r) {
        st[p] = v[l];
        return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = gcd(st[2*p], st[2*p+1]);
}

ll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return gcd(x, y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n);
    for(int r = 0, l = 0; r < n; r++){
        while(l <= r and query(1, 0, n, l + 1, r) == 1) l++;
        if(query(1, 0, n, l, r) == 1) ans = min(ans, r - l + 1ll);
    }
    if(ans == LINF) ans = -1;
    cout << ans << "\n";
    return 0;
}