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

ll x, y;
vector<ll> coords;
vector<ld> fs, l, u;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y;
    cin >> n;
    coords.reserve(2 * n + 2);
    fs.resize(n);
    l.resize(n);
    u.resize(n);

    coords.push_back(0);

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> u[i] >> fs[i];
    }
    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 0);
    sort(idxs.begin(), idxs.end(), [](int a, int b) { return l[a] < l[b]; });

    for (int i = 0; i < n; i++) {
        coords.push_back(l[idxs[i]]);
        coords.push_back(u[idxs[i]]);
    }

    coords.push_back(y);

    ld den = 0;
    int k = 0;

    for (int i = 0; i + 1 < (int)coords.size(); i++) {
        ld val;
        if (i & 1) {
            val = fs[idxs[k]] * (coords[i + 1] - coords[i]);
            k++;
        } else {
            val = coords[i + 1] - coords[i];
        }
        den += val;
    }

    ld ans = (x * 1.0) / den;

    cout << fixed << setprecision(20) << ans << "\n";



    return 0;
}
