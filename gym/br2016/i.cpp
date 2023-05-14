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
const int N = 6005;

int n,b,c;
ll h[N], hxi[N], dp[N][2], L[N][2], ans;

ll C(ll j, ll i){
    ll ans = 0;
    ll m = (i+j)/2;
    ans += c*((hxi[m] - hxi[j]) - j*(h[m] - h[j]) - (hxi[i-1] - hxi[m]) + i*(h[i-1] - h[m]));
    return ans;
}

int main(){
    scanf("%d%d%d",&n,&b,&c);
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        h[i] = h[i-1] + x;
        hxi[i] = hxi[i-1] + x*i;
    }

    for(ll i=1;i<=n;i++){
        dp[i][1] = c*(i*h[i-1] - hxi[i-1]);
        L[n+1][0] = L[n+1][1] = n;
        L[i][1] = 1;
        ans = LINF;
    }

    for(ll i=1;i<=n;i++){
        ll rest = c*(hxi[n] - hxi[i] - i*(h[n]-h[i]));
        ans = min(ans,dp[i][1] + rest + b);
        dp[i][0] = dp[i][1];
        L[i][0] = L[i][1];
    }
    printf("%lld",ans);
    if(n == 1) printf("\n");
    else printf(" ");
    //dp
    for(ll l = 2; l<=n; l++){
        for(ll i=n; i>=1; i--){
            //best: cost, pos
            pair<ll,ll> best = {LINF, n};
            //searches best using the necessary condition
            for(ll j = L[i][0]; j <= L[i+1][1] and j < i; j++){
                best = min(best, {dp[j][0] + C(j, i), j});
            }
            dp[i][1] = best.first;
            L[i][1] = best.second;
        }
        ans = LINF;
        for(int i=1;i<=n;i++){
            ll rest = c*(hxi[n] - hxi[i] - i*(h[n]-h[i]));
            ans = min(ans, dp[i][1] + rest + l*b);
            dp[i][0] = dp[i][1];
            L[i][0] = L[i][1];
        }
        printf("%lld",ans);
        if(l == n) printf("\n");
        else printf(" ");
    }
    return 0;
}