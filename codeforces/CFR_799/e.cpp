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

int a[N], l[N], r[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, s, sum = 0;
        cin >> n >> s;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
            l[i] = r[i] = 0;
        }
        if(sum < s){
            cout << "-1\n";
            continue;
        }
        int cum = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == 0) continue;
            cum += a[i];
            l[cum] = i;
        }
        cum = 0;
        for(int i = n; i >= 1; i--){
            if(a[i] == 0) continue;
            cum += a[i];
            r[cum] = (n - i) + 1;
        }
        int ans = INF;
        for(int i = 0; sum - i >= s; i++){

            int tmp = l[i] + r[sum - i - s];
            ans = min(ans, tmp);
        }
        cout << ans << "\n";
    }
    return 0;
}