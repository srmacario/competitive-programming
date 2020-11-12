#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

vector <pll> memo, swp;
vector <ll> a;
pll dp(int i){
    if(!i) return {a[i],a[i]};
    ll mn, mx;
    pll pai = dp(i-1);
    mx = max({a[i] - pai.nd, pai.st, a[i]});
    mn = min({a[i] - pai.st, pai.nd, a[i]});
    return memo[i] = {mx,mn};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        a.resize(n);
        swp.resize(q);
        memo.resize(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<q;i++) cin >> swp[i].st >> swp[i].nd;
        cout << dp(n-1).st << "\n";
    }
    return 0;
}