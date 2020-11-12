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
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x,y,xa,xb,ya,yb;
        cin >> x >> y >> xa >> ya >> xb >> yb;
        bool ok = true;
        if(a > b) if((a-b) > (x - xa)) ok = false;
        else {if((b-a) > (xb - x)) ok = false;}
        if(c > d) if((c-d) > (y - ya)) ok = false;
        else {if((d-c) > (yb - y)) ok = false;}
        if((x == xa) and (x == xb)) if((a>0) or (b>0)) ok = false;
        if((y == ya) and (y == yb)) if((c>0) or (d>0)) ok = false;
        cout << ( ok ? "YES\n" : "NO\n");
    }
    return 0;
}