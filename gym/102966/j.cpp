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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll c, f, b, s;
        cin >> c >> f >> b >> s;
        ll mdc = gcd(f,b);
        ll mult = mdc;
        ll l = 1ll, r = 1e13, k;
        if(!(mult%2)) mult /= 2;
        if(!(mult%2)) mult /= 2;
        if(!(mult%3)) mult /= 3;
        while(l < r){
            k = (l+r)/2ll;
            if(12*k*mult/mdc < (12*s + c - 1)/c) l = k + 1;
            else r = k;
        }
        cout << (12*l*mult)/mdc << "\n";
    }
    return 0;
}