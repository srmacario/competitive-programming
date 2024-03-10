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

ll n, m, s[N], q[N], ps[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s, s + n);
    for(int i = 0; i < n; i++){
        ps[i + 1] = ps[i] + s[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> q[i];
        int k = (upper_bound(s, s + n, q[i]) - s);
        cout << ps[k] + (n - k) * q[i] << "\n";
    }
    return 0;
}