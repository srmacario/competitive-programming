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
    int k, n;
    cin >> k >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i > n - k) break;
        int cur = a[i];
        db(cur);
        ans += cur;
        for(int j = 0; j < k; j++){
            a[i + j] -= cur;
        }
    }
    cout << ans << "\n";
    return 0;
}
// 4 4 4 4 4
// 3 3 3 4 4
// 2 3 3 3 3
// 2 2 2 2 3
// 1 1 2 2 2
// 0 0 1 2 2
// 0 0 0 1 1