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

int n;
ll s[N], ps[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    int l = 1, r = 0;
    for(int i = n; i >= 1; i--){
        if(s[i] == 3) r++;
        if(s[i] == 2){
            ps[l] = (ps[l] + 1);
            ps[r + 1] = (ps[r + 1] - 1);
            db(l _ r);
        }
    }
    for(int i = 1; i <= n; i++){ ps[i] = (ps[i - 1] + ps[i]);}
    for(int i = 1; i <= n; i++){ ps[i] = (ps[i - 1] + ps[i]);}
    ll ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 1)
            ans = (ans + ps[r] - ps[l - 1] - cnt * (r - l + 1) + MOD) % MOD, db(ans);
        if(s[i] == 2)
            cnt++;
        if(s[i] == 3)
            r--;
    }
    cout << ans << "\n";
    return 0;
}