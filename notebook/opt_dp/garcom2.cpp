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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 405;

ll n, k, q[N], qx[N], dp[N][N];

ll C(ll j, ll i){
    ll ans = 0;
    ll m = (i+j)/2;
    ans += (qx[m] - qx[j]) - j*(q[m] - q[j]) - (qx[i-1] - qx[m]) + i*(q[i-1] - q[m]);
    return ans;
}

void compute(ll l, ll r, ll k, ll optl, ll optr){
    // stop condition  
    if(l > r) return;
    ll mid = (l+r)/2;
    //best : cost, pos
    pair<ll,ll> best = {LINF,-1};

    //searchs best, lower bound to right, upper bound to left
    for(ll i = optl; i <= min(mid, optr); i++){
        best = min(best, {dp[i][k-1] + C(i,mid), i});
    }
    dp[mid][k] = best.first;
    ll opt = best.second;

    compute(l, mid-1, k, optl, opt);
    compute(mid + 1, r, k, opt, optr);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    ll ans = LINF;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        q[i] = q[i-1] + x;
        qx[i] = qx[i-1] + x*i;
    }
    for(ll l = 1; l<=k; l++){
        if(l == 1){
            for(ll i=1;i<=n;i++){
                dp[i][1] = i*q[i-1] - qx[i-1];
            }
            continue;
        }
        compute(1,n,l,1,n);
    }
    ans = LINF;
    for(ll i=1;i<=n;i++){
        ll rest = (qx[n] - qx[i]) - i*(q[n] - q[i]);
        ans = min(ans,dp[i][k] + rest);
    }
    cout << ans << "\n";
    return 0;
}