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
    int q, d, p;
    while(true){
        cin >> q;
        if(q == 0) break;
        cin >> d >> p;
        ll ans = (1ll * q * (p * d)) / (p - q);
        cout << ans;
        if(ans > 1) cout << " Paginas\n";
        else cout << " Pagina\n";
    }
    return 0;
}

// q * d = p * (d - D)
// d (q - p) = - p * D
// d = p * D / (q - p)