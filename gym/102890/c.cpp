#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3ff3, MOD = 1e9+7;
const int N = 1e5+5;

ll mult(ll a, ll b) { return (a * b) % MOD; }

ll inv() {
    ll b = 2;
    ll e = MOD - 2;
    ll ans = 1;
    while (e) {
        if (e & 1) ans = mult(ans, b);
        b = mult(b, b);
        e /= 2;
    }
    return ans;
}

int t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll inv2 = inv();
    ll n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << mult(mult(mult(n+1, n+2), k+1), inv2) << "\n";
    } 



    return 0;
}