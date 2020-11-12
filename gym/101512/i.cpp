#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " << 

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll a,b,x,y,d;

void extgcd (ll a, ll b, ll &x, ll &y, ll &d) {
    if (b) extgcd(b, a%b, y, x, d), y -= x*(a/b);
    else x = 1, y = 0, d = a;
}

ll fib[50];

void calc(){
    fib[1] = fib[2] = 1;
    for(int i = 3; i <= 45; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    calc();
    while(t--){
        int n;
        cin >> n;
        ll ansx = LINF, ansy = LINF;
        for(int k=3; k<45; k++){
            b = fib[k-1], a = fib[k-2];
            ll mdc = gcd(a,b);
            ll fx = b/mdc, fy = a/mdc;
            if(n % mdc) continue;
            d = mdc;
            ll mul = n/mdc;
            extgcd(a, b, x, y, d);
            ll ct;
            x *= mul, y*=mul;
            if(x < y){
                ct = (y-x)/(fx + fy);
                x += ct*fx;
                y -= ct*fy;
            }
            else if(y < x){
                ct = (x-y-1)/(fx + fy) + 1;
                x -= ct*fx;
                y += ct*fy;
            }
            if(x > 0 and y > 0){
                if(y < ansy){
                    ansy = y;
                    ansx = x;
                }
                else if(y == ansy){
                    if(x < ansx){
                        ansx = x;
                    }
                }
            }
            //cout << x << " " << y << "\n";
        }
        cout << ansx << " " << ansy << "\n";
    }
    return 0;
}