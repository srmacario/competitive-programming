#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5;

int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n + 1);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            a[v[i]] = max(a[v[i]], i);
        }
        int ans = -1;
        for(int i = 1; i <= 1000; i++){
            if(!a[i]) continue;
            for(int j = 1; j <= 1000; j++){
                if(!a[j]) continue;
                int gcd = __gcd(i, j);
                if(gcd == 1) ans = max(ans, a[i] + a[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}