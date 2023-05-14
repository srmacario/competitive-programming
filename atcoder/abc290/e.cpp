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

int n, a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll ans = 0;
    vector<vector<ll>> num(n + 1);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        ll k = min(i - 1, n - i);
        ans += (n - k - 1) * (k + 1);
        num[a[i]].push_back(i);
    }
    ans /= 2;
    for(ll i = 1; i <= n; i++){
        ll l = 0, r = (int)num[i].size() - 1;
        while(l < r){
            if(num[i][l] < (n - num[i][r] + 1)){
                ans -= (r - l) * num[i][l];
                l++;
            }
            else{
                ans -= (r - l) * (n - num[i][r] + 1);
                r--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}