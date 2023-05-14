#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, X;
ld v;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> X >> v;
    vector<pair<pii, ld>> side(n);
    int sum = X;
    ld sum_vd = 0;
    for(int i = 0; i < n; i++){
        int l, r;
        ld vel;
        cin >> l >> r >> vel;
        side.push_back({{l, r}, vel});
        sum_vd += vel * (r - l);
    }
    ld seno = (-sum_vd) / (sum * v);
    if(!le(abs(seno), 1)){
        cout << "Too hard\n";
        return 0;
    }
    ld cosseno = sqrt(1 - seno * seno);
    ld mx = (2 * sum) / v;
    ld ans = (sum / (v * cosseno));
    if(!le(ans, mx)){
        cout << "Too hard\n";
        return 0;
    }
    cout << setprecision(3) << fixed << ans << "\n";
    return 0;
}