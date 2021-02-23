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

ll x[N], y[N], u[N], v[N];
map <pll,ll> pos[2], neg[2];

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int t;
    cin >> t;
    while(t--){
        ll r = 0, l = 0, up = 0, b = 0, ans = 0;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i] >> u[i] >> v[i];
            ll num = v[i] - y[i];
            if(!num){
                if(u[i]-x[i] > 0) r++;
                else l++;
                continue;
            }
            ll den = u[i] - x[i];
            if(!den){
                if(v[i]-y[i] > 0) up++;
                else b++;
                continue;
            }
            ll mdc = gcd(abs(num),abs(den));
            if(num*den < 0){
                if(num > 0){
                    neg[0][{abs(num)/mdc,abs(den)/mdc}]++;
                    ans += neg[1][{abs(num)/mdc,abs(den)/mdc}];
                }
                if(num < 0){
                    neg[1][{abs(num)/mdc,abs(den)/mdc}]++;
                    ans += neg[0][{abs(num)/mdc,abs(den)/mdc}];
                }
            }
            else{
                if(num > 0){
                    pos[0][{abs(num)/mdc,abs(den)/mdc}]++;
                    ans += pos[1][{abs(num)/mdc,abs(den)/mdc}];
                }
                if(num < 0){
                    pos[1][{abs(num)/mdc,abs(den)/mdc}]++;
                    ans += pos[0][{abs(num)/mdc,abs(den)/mdc}];
                }
            }
        }
        ans += l*r + up*b;
        cout << ans << "\n";
        pos[0].clear();        
        pos[1].clear();
        neg[0].clear();
        neg[1].clear();
    }
    return 0;
}