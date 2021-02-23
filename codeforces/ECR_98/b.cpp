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
        cin >> n;
        vector<ll> a(n+5);
        ll mx = -LINF, smx = -LINF, sum = 0, ans = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            if(a[i] <= mx and a[i] > smx) smx = a[i];
            if(a[i] >= mx) smx = mx, mx = a[i];
            sum += a[i];
        }
        for(int i=1;i<=n;i++){
            ll mxnow = mx;
            if(a[i] == mx) mxnow = smx;
            ll need = (n-2)*mxnow - (sum-mxnow-a[i]);
            if(need >= a[i]) ans = max(need - a[i],ans);
            else{
                ans = max(ans,((n-1) - ((a[i]-need) % (n-1)))%(n-1));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}