#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5 + 5;

ll a, b, c, d;

ll func(ll x) {
    ll aux = d % x;
    return (x - aux) * min(d/x * a, b) + aux * min((d/x + 1) * a, b);
}

bool test(ll x) {
    return func(x) >= c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;

    d = max((c + a - 1) / a, (c + b - 1) / b);

    ll l = 1, r = (ll)1e9, mid;
    while (l != r) { 
        mid = (l + r) / 2;
        if (test(mid)) r = mid;
        else l = mid + 1;
    }

    cout << d << " " << l << "\n";

    return 0;
}