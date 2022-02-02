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

ll l[N], r[N], c[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        pll ans = {-INF, -INF};
        pll mn = {INF, INF};
        pll mx = {-INF, -INF};
        pll sz = {-INF, -INF};
        cin >> n;
        for(int i = 0; i < n; i++) cin >> l[i] >> r[i] >> c[i];
        for(int s = 0; s < n; s++){
            pll cur_sz = {(r[s] - l[s] + 1), -c[s]};
            pll cur_mn = {l[s], c[s]};
            pll cur_mx = {r[s], -c[s]};
            sz = max(sz, cur_sz);
            mn = min(mn, cur_mn);
            mx = max(mx, cur_mx);
            pll sep = {mx.st - mn.st + 1, mx.nd - mn.nd};
            ans = max({ans, sz, sep});
            cout << -ans.nd << "\n";
        }
    }
    return 0;
}