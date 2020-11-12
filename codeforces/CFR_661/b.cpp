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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        ll amin = LINF, bmin = LINF;
        for(int i=0;i<n;i++){
            cin >> a[i];
            amin = min({a[i],amin});
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            bmin = min({b[i],bmin});
        }
        ll ans = 0;
        for(int i=0;i<n;i++){
            ll aneed = a[i] - amin;
            ll bneed = b[i] - bmin;
            ans += min(aneed,bneed);
            a[i] -= min(aneed,bneed);
            b[i] -= min(aneed,bneed);
        }
        for(int i=0;i<n;i++){
            ll aneed = a[i] - amin;
            ll bneed = b[i] - bmin;
            ans += aneed + bneed;
        }
        cout << ans << "\n";
    }
    return 0;
}