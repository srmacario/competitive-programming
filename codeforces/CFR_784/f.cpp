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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> w(n + 5), ps(n + 5), ss(n + 5);
        for(int i = 1; i <= n; i++){
            cin >> w[i];
            ps[i] = ps[i - 1] + w[i];
        }
        for(int i = n; i >= 1; i--){
            ss[i] = ss[i + 1] + w[i];
        }
        int ans = 0;
        for(int l = 1, r = n; l < r; l++){
            // db(ss[r] _ ps[l]);
            while(l < r - 1 and ss[r] < ps[l]) r--;
            if(ss[r] == ps[l]) ans = max(ans, l + n - r + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}