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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

ll a[N], ind[N], mxind[N];
vector <ll> l,r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ind[a[i]] = i;
    }
    for(int i=0;i<m;i++){
        ll x,y,ix,ib;
        cin >> x >> y;
        ix = ind[x], iy = ind[y];
        if(ix > iy) swap(ix,iy);
        l.pb(ix), r.pb(iy);
    }
    ll lcnt = 1, rcnt = 0;
    sort(r.begin(),r.end());
    ll ans = 0;
    for(int i=0;i<r.size();i++){
        ans += ((r[i] - lcnt)*(r[i] - lcnt - 1))/2;
        lcnt = r[i];
    }
    return 0;
}