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

ld S;
ll num_S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    num_S = 2 * m * 2 * m;

    for(int i = 1; i < m; i++){
        if(((PI * i) / m) < (ld)2) S += 2 * ((PI * i) / m);
        else S += 4;
    }
    S += 2;
    // db(S);
    S *= (m);
    ld ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            // db(i _ j);
            // db(S * i _ abs(i - j)*num_S);
            if(i == j) ans += S * min(i, j);
            else ans += 2 * S * min(i, j) + abs(i - j) * num_S;
        }
        if(m > 1) ans += 2 * m * i;
    }
    // db(S _ num_S);
    cout << setprecision(15) << fixed << ans << "\n";
    return 0;
}