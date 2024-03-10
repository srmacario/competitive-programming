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
const int N = 1e6+5;

int get_sum(int n){
    int ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int n, k, f[N], cnt_fi[N], mx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> f[i];
        cnt_fi[f[i]]++;
        mx = max(mx, f[i]);
    }
    int ans = 0;
    for(int i = mx; i >= 0; i--){
        int sum = get_sum(i);
        if(k <= cnt_fi[i]){
            ans = sum;
            break;
        }
        k -= cnt_fi[i];
        cnt_fi[i - sum] += cnt_fi[i];
    }
    cout << ans << "\n";
    return 0;
}