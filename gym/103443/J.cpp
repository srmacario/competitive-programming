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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l;
    cin >> l;
    while(l--){
        ll n, s, p, u;
        cin >> n >> s >> p;
        u = n - 1 - s;
        for(int i = 0; i < s; i++){
            int x;
            cin >> x;
        }
        ll ans = s + 2 * u + 
                 (s - 1) * (2 * (s - 1) + 3 * u + 1) + 
                 2 * (s - 1) + 1 + 3 * (p - s) + (u - (p - s)) + 
                 (u - (p - s)) * (1 + 2 + 3 * (s - 1) + 4 * (p - s) + 2 * (u - (p - s) - 1)) + 
                 (p - s) * (2 + 3 + 4 * (u - (p - s)) + 3 * (s - 1) + 4 * (p - s - 1));
        cout << ans << "\n";
    }
    return 0;
}