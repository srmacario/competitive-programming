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

int n, q;
vector<pair<ll, ll>> ans;

ll upper_sqrt(ll x){
    ll l = 0, r = x - 1;
    while(l < r){
        ll m = (l + r)/2;
        if(m * m >= x) r = m;
        else l = m + 1;
    }
    return l;
}

ll new_gcd(ll a, ll b){
    return b ? new_gcd(b, a / b) : a;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        ll s = upper_sqrt(i);
        if(new_gcd(i, s) == gcd(i, s)) ans.push_back({i, s});
        ans.push_back({i, i});
    }
    for(int i = 0; i < q; i++){
        ll p;
        cin >> p;
        if(p >= ans.size()) cout << "-1 -1\n";
        else cout << ans[p].st << " " << ans[p].nd << "\n";
    }
    return 0;
}