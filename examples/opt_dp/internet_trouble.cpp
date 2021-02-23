#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int INF = 0x3f3f3f3f, MOD = 1 e9+7;
const int N = 6005;

ll n, b, c, q[N], qx[N], dp_cur[N], dp_bef[N], L_cur[N], L_bef[N];

ll C(ll j, ll i){
    ll ans = 0;
    ll m = (i+j)/2;
    ans += c*((qx[m] - qx[j]) - j*(q[m] - q[j]) - (qx[i-1] - qx[m]) + i*(q[i-1] - q[m]));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b >> c;
    ll ans = LINF;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        q[i] = q[i-1] + x;
        qx[i] = qx[i-1] + x*i;
    }
    for(ll i=1;i<=n;i++){
        dp_cur[i] = c*(i*q[i-1] - qx[i-1]);
        L_cur[n+1] = L_bef[n+1] = n;
        L_cur[i] = 1;
        ans = LINF;
    }
    for(ll i=1;i<=n;i++){
        ll rest = c*((qx[n] - qx[i]) - i*(q[n] - q[i]));
        ans = min(ans,dp_cur[i] + rest + b);
        dp_bef[i] = dp_cur[i];
        L_bef[i] = L_cur[i];
    }
    cout << ans << " ";

    for(ll l = 2; l<=n; l++){
        for(ll i=n; i>=1; i--){
            pair<ll,ll> best = {LINF, n};
            for(ll j = L_bef[i]; j <= L_cur[i+1] and j < i; j++){
                best = min(best, {dp_bef[j] + C(j, i), j});
            }
            dp_cur[i] = best.first;
            L_cur[i] = best.second;
        }
        ans = LINF;
        for(ll i=1;i<=n;i++){
            ll rest = c*((qx[n] - qx[i]) - i*(q[n] - q[i]));
            ans = min(ans,dp_cur[i] + rest + l*b);
            dp_bef[i] = dp_cur[i];
            L_bef[i] = L_cur[i];
        }
        cout << ans << (l==n ? "\n" : " ");
    }
    return 0;
}