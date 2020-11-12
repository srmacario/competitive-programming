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
const int N = 1e5+5;
ll n,h[N][3],dp[N][3];

ll call_dp(ll i, ll k){
    if(i > n) return 0;
    if(~dp[i][k]) return dp[i][k];
    return dp[i][k] = max(h[i][(k+1+3)%3] + call_dp(i+1,(k+1+3)%3),h[i][(k-1+3)%3] + call_dp(i+1,(k-1+3)%3));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> h[i][0] >> h[i][1] >> h[i][2];
    }
    ll ans0 = h[1][0] + call_dp(2,0);
    ll ans1 = h[1][1] + call_dp(2,1);
    ll ans2 = h[1][2] + call_dp(2,2);
    cout << max({ans0,ans1,ans2}) << "\n";
    return 0;
}