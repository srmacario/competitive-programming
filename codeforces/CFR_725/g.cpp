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
const int N = 1e5+5;

ll x, y, a, b;

bool check(ll m){
    if(a == b) return a*m <= x and a*m <= y;
    ll j = (x - a*m)/(b - a);
    ll i = (y - a*m)/(b - a);
    return i >= 0 and j >= 0 and i + j >= m and x >= a*m and y >= a*m; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        if(a > b) swap(a, b);
        ll l = 0, r = y/a;
        while(l < r){
            ll m = (l + r + 1)/2;
            if(check(m)) l = m;
            else r = m - 1;
        }
        cout << l << "\n";
    }
    return 0;
}