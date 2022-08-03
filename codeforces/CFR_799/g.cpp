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
const int N = 2e5+5;

int a[N], cmp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cmp[i] = 0;
            cin >> a[i];
            if(2 * a[i] > a[i - 1]) cmp[i] = 1;
            //cout << cmp[i] << " ";
        }
        int ans = 0;
        int l = 1, r = 1;
        for(l = 1, r = 1; r <= n; r++){
            if(!cmp[r]){
                ans += max(0, (r - l) - k);
                //db(ans);
                l = r;
            }
        }
        ans += max(0, (r - l) - k);
        cout << ans << "\n";
    }
    return 0;
}