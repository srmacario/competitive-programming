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

ll a, b, c, d, ans;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    for(ll i = 1; i < 1000; i++){
        for(ll j = 1; i + j < 1000; j++){
            if(gcd(i,j) != 1) continue;
            ll lb = max((a-1)/i+1, (c-1)/j+1);
            ll ub = min(b/i, d/j);
            if(lb <= ub) ans += ub - lb + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}