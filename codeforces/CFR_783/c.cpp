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
    int n;
    cin >> n;
    vector<ll> a(n + 5), b(n + 5);
    ll ans = LINF;
    for(int i = 0; i < n; i++) cin >> a[i];
    //choose pivot
    for(int i = 0; i < n; i++){
        ll temp = 0;
        //move backward
        b[i] = 0;
        for(int j = 1; (i - j) >= 0; j++){
            //b[i - j] > b[i - j + 1]
            //a[i - j] * k > b[i - j + 1]
            ll k = b[i - j + 1] / a[i - j] + 1;
            temp += k;
            b[i - j] = k * a[i - j];
            // db(k);
        }
        //move forward
        for(int j = 1; (i + j) < n; j++){
            //b[i + j] < b[i + j - 1]
            //a[i + j] * k < b[i + j - 1]
            ll k = b[i + j - 1] / a[i + j] + 1;
            temp += k;
            b[i + j] = k * a[i + j];
            // db(k);
        }
        // db(i);
        // for(int j = 0; j < n; j++) cout << b[j] << " ";
        // cout << "\n";
        ans = min(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}