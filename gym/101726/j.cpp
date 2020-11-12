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
        ll n,m,c,k, ans = 0;
        cin >> n >> m >> c >> k;
        vector <ll> x(c), y(c), r(c);
        // read circles
        for(int i=0;i<c;i++) cin >> x[i] >> y[i] >> r[i];
        swap(x,y);
        // sweep in lines
        for(ll i=1;i<=n;i++){
            vector<pll> events;
            for(int j=0;j<c;j++){
                // h = dist from center to line
                ll h = abs(y[j] - i), left = 1, right = m;
                //if dist > r that circle cant find that line
                if(h > r[j]) continue;
                // find interval [a,b] which circle intercepts the line
                ll dx = (sqrt(r[j]*r[j] - h*h) + EPS);
                ll xlo = -dx-10;
                while((xlo)*(xlo) + (h)*(h) > (r[j]*r[j])) xlo++;
                ll xhi = dx+10;
                while((xhi)*(xhi) + (h)*(h) > (r[j]*r[j])) xhi--;

                //interval = [xc - lim, xc + lim], respecting boundaries
                left = max<ll>(xlo + x[j], left);
                right = min<ll>(xhi + x[j], right);
                //0 for opening and 1 for closing interval
                events.pb({left,0}), events.pb({right,1});
            }
            sort(events.begin(), events.end());
            //cnt counts opened and lst marks when a suitable interval opened
            ll cnt = 0, lst = 1;
            for(auto e : events){
                if(!e.nd){
                    //increase counts and see if interval is suitable
                    if(++cnt == k) lst = e.st;
                }
                else{
                    //decrease counts, if interval goes from k to k-1, add to answer
                    if(--cnt == k-1) ans += e.st - lst + 1;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}