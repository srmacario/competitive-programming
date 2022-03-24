#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

using ll = long long;
using ld = long double;

const int N = 1e5+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll n, m;
ll u, v, w;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    while (cin >> n >> m) {
        ll mult = 1;
        ll cnt_odd = 0;
        while (m--) {
            cin >> w >> u >> v;
            if (w & 1) cnt_odd++, mult *= w;
        }

        cout << mult << "\n";
    }
 
    return 0;
}