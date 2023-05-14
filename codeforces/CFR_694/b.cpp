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
        ll n,x,ans = 0;
        pll mn = {INF,INF};
        cin >> n >> x;
        vi a(n);
        for(ll i=0;i<n;i++){
            cin >> a[i];
            ans += a[i];
            ll cur = a[i], cnt = 0;
            while(!(cur%x)){
                cur /= x;
                cnt++;
            }
            mn = min(mn,{cnt,i});
        }
        for(ll i=0;i<n;i++){
            ans += mn.st*a[i];
            if(i < mn.nd) ans += a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}