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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        ll ans = 0;
        cin >> n;
        ll bits[63] = {0};
        vector<ll> x(n+5);
        for(ll i=0;i<n;i++){
            cin >> x[i];
            for(ll j=0;j<60;j++){
                if(1ll<<j & x[i]) bits[j]++;
            }
        }
        for(ll i=0;i<n;i++){
            ll curj = 0, curk = 0;
            for(ll j=0;j<60;j++){
                if(1ll<<j & x[i]){
                    curj = (curj + (((1ll<<j)%MOD) * bits[j])%MOD)%MOD;
                }
            }
            for(ll k=0;k<60;k++){
                if(1ll<<k & x[i]){
                    curk = (curk + (((1ll<<k)%MOD) * n)%MOD)%MOD;
                }
                else{
                    curk = (curk + (((1ll<<k)%MOD) * bits[k])%MOD)%MOD;
                }
            }
            ans = (ans + (curj*curk)%MOD) %MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}