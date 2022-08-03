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
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a.begin() + 1, a.end(), greater<int>());
        for(int i = 1; i <= n; i++) a[i] += a[i - 1];

        for(int i = 0; i < q; i++){
            int x;
            cin >> x;
            int ans = (lower_bound(a.begin(), a.end(), x) - a.begin());
            if(ans == a.size()) cout << "-1\n";
            else cout << ans << "\n";
        }
    }
    return 0;
}