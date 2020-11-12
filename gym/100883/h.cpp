#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

ll n, c1, n1, c2, n2, a, b, x, y, d;

void extgcd (ll a, ll b, ll &x, ll &y, ll &d) {
    if (b) extgcd(b, a%b, y, x, d), y -= x*(a/b);
    else x = 1, y = 0, d = a;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    while(1){
        cin >> n;
        if(!n) return 0;
        cin >> c1 >> n1;
        cin >> c2 >> n2;
        if(n%gcd(n1,n2)){
            printf("failed\n");
            continue;
        }
        bool sw = false;
        //if(c1*n1 > c2*n2) swap(c1,c2), swap(n1,n2), sw = true;
        x = y = d = 0;
        extgcd(n1,n2,x,y,d);
        ll dx = n2/d, dy = n1/d;
        x *= n/d, y*=n/d;
        if(c1*dx > c2*dy) swap(c1,c2), swap(n1,n2), swap(x,y), swap(dx,dy), sw = true;
        ll k = y/dy;
        if(k < 0 and abs(y)%abs(dy) != 0) k--;
        y -= k*dy, x += k*dx;
        if(x<0 or y<0){
            printf("failed\n");
            continue;
        }
        if(sw) swap(y,x);
        printf("%lld %lld\n",x,y);
    }
    return 0;
}