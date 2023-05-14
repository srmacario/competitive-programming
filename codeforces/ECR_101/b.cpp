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
        int n,m,ans = 0, sum = 0, mx = 0;
        cin >> n;
        vi r(n);
        for(int i=0;i<n;i++){
            cin >> r[i];
            sum += r[i];
            mx = max(mx,sum);
        }
        ans += mx;
        mx = sum = 0;
        cin >> m;
        vi b(m);
        for(int i=0;i<m;i++){
            cin >> b[i];
            sum += b[i];
            mx = max(mx,sum);
        }
        ans += mx;
        cout << ans << "\n";
    }
    return 0;
}