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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 5e3+5;

int n, p[N];

ll calc (int l, int r){
    if(r < l) return 1;
    pii m = {INF, INF};
    for(int k = l; k <= r; k++) m = min(m, make_pair(p[k], k));
    ll left = calc(l, m.nd - 1), right = calc(m.nd + 1, r);
    if(l > 0 and r < n - 1)
        return (right * left + right + left - 1) % MOD;
    if(l > 0)
        return (right * left + right) % MOD;
    if(r < n - 1)
        return (right * left + left) % MOD;
    return (right * left) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    cout << calc(0, n - 1) << "\n";
    return 0;
}