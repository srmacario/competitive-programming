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
const int N = 2e5+5;

int n, b, x[N], y[N], t[N], v[N], wt[N], bt[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> t[i] >> v[i];
    vector<int> cand;
    for(int i = 0; i < n; i++){
        wt[i] = y[i] - x[i];
        bt[i] = (y[i] - 1 + b) / b;
        // db(wt[i] _ bt[i]);
        if(wt[i] > t[i] and bt[i] <= t[i]) cand.push_back(v[i]);
    }
    sort(cand.begin(), cand.end());
    pll ans = {-LINF, -LINF};
    for(int i = 0; i < cand.size(); i++){
        pll poss = {1ll * (cand.size() - i) * (cand[i]), - cand[i]};
        ans = max(ans, poss);
    }
    if(ans.nd == -LINF) cout << "0\n";
    else cout << -ans.nd << "\n";
    return 0;
}