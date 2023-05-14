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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll a,b,q;
        cin >> a >> b >> q;
        if(a > b) swap(a,b);
        for(int i=0;i<q;i++){
            ll l,r;
            cin >> l >> r;
            if(r < b or a == b){
                cout << "0 ";
                continue;
            }
            if(l < b) l = b;
            ll mmc = (a/gcd(a,b))*b;
            ll laux = (l/mmc) * mmc;
            ll raux = (r/mmc) * mmc;
            //db(raux), db(laux);
            ll ans = r - l + 1;
            //db(ans);
            ans -= ((raux - laux + mmc) / mmc) * b;
            //db(ans);
            ans += min(l - laux,b);
            //db(ans);
            if(r < raux + b) ans += raux + b - r - 1;
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}