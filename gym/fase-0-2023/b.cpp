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
    ll a, b, c;
    char op;
    cin >> a >> b >> c >> op;
    ll ans = 0;
    //all to a
    if(op == 'A'){
        ans = a;
        ans += (3*b)/2 + (5*c)/2;
    }
    if(op == 'B'){
        //all to b
        ans = b;
        ans += (2*a)/3 + (10*c)/6;
    }
    if(op == 'C'){
        //all to c
        ans = c;
        ans += (2*a)/5 + (6*b)/10;
    }
    cout << ans << "\n";
    return 0;
}