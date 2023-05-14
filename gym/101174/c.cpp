#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

ll d, r, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> d >> r >> t;

    for (ll y = 3; y <= 1000; y++) {
        ll x = y + d;

        ll sum1 = (x - 3) * (x + 4);
        ll sum2 = (y - 2) * (y + 3);

        if (sum1 % 2 != 0) continue;
        if (sum2 % 2 != 0) continue;
        ll val = r - t;
        val -= sum1/2;
        val += sum2/2;
        if (val < 0 or val % 2 != 0) continue;
        val /= 2;
        if (sum1/2 != r - val or sum2/2 != t + val) continue;
        
        cout << val << "\n";
        return 0;
    }

    assert(false);


    return 0;
}