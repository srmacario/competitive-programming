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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,xa,ya,xb,yb;
    ld ans;
    cin >> x >> y >> xa >> ya >> xb >> yb;
    if(x < xa){
        if(y < ya){
            ans = sqrt((xa-x)*(xa-x) + (ya-y)*(ya-y));
        }
        if(y >= ya and y <= yb){
            ans = abs(xa-x);
        }
        if(y > yb){
            ans = sqrt((xa-x)*(xa-x) + (yb-y)*(yb-y));
        }
    }
    if(x >= xa and x <= xb){
        if(y < ya){
            ans = abs(y-ya);
        }
        if(y > yb){
            ans = abs(y-yb);
        }
    }
    if(x > xb){
        if(y < ya){
            ans = sqrt((xb-x)*(xb-x) + (ya-y)*(ya-y));
        }
        if(y >= ya and y <= yb){
            ans = abs(xb-x);
        }
        if(y > yb){
            ans = sqrt((xb-x)*(xb-x) + (yb-y)*(yb-y));
        }
    }
    cout << fixed << setprecision(3) << ans << "\n";
    return 0;
}