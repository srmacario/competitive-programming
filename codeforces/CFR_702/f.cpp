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
const int N = 2e5+5;

ll n, a[N],f[N], xf[N];
map<int,int> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
            m[a[i]]++;
        }
        for(auto u: m) f[u.nd]++;
        for(ll i=1;i<=n;i++){
            xf[i] = i*f[i] + xf[i-1];
            f[i] += f[i-1];
        }
        ll total = LINF;
        for(ll i=1;i<=n;i++){
            ll ans = 0;
            ll mid = i/2;
            ll r = (xf[n] - xf[i]) - i*(f[n]-f[i]);
            ll l = xf[i-1];
            ans = r + l;
            total = min(ans,total);
        }
        cout << total << "\n";
        for(int i=0;i<=n;i++) f[i] = 0, xf[i] = 0;
        m.clear();
    }
    return 0;
}