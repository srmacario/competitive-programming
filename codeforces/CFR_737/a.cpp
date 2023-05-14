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
        ll n, numa = 0, numb = 0, dena = 0, denb = 0;
        double ans = 0;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            numb += a[i];
            denb ++;
        }
        ans = -LINF;
        sort(a.begin(), a.end());
        for(int i = 0; i < n - 1; i++){
            numa += a[i], numb -= a[i];
            dena++, denb--;
            double tmp = 1.0*numa/dena + 1.0*numb/denb;
            // db(tmp);
            ans = max(ans, tmp);
        }
        cout << setprecision(10) << fixed << ans << "\n";
    }
    return 0;
}