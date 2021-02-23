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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,k;
    vector<ll> a,ps;
    cin >> n >> q >> k;
    a.resize(n+5);
    ps.resize(n+5);
    for(int i=1;i<=n;i++) cin >> a[i];
    a[n+1] = k+1;
    for(int i=1;i<=n;i++){
        ps[i] = (a[i+1] - a[i-1] - 2);
        ps[i] += ps[i-1];
    }
    for(int i=0;i<q;i++){
        int l,r;
        int ans = 0;
        cin >> l >> r;
        cout << ps[r-1] - ps[l] + (a[l] - 1ll + a[l+1] - a[l] - 1) + (k - a[r] + a[r] - a[r-1] - 1) << "\n";
    }
    return 0;
}