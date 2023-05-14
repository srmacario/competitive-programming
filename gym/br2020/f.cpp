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
const int N = 1e4+5;

int v[N];
ll dp[N][N], L[N][N], ans;

ll C(ll i, ll j);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        dp[i][1] = C(0, i);
        L[n+1][i] = n;
        L[i][i] = 1;
    }

    for(ll l = 1; l <= n; l++){
        for(ll i = n; i >= 1; i--){
            //best: cost, pos
            pair<ll,ll> best = {LINF, n};
            //searches best using the necessary condition
            for(ll j = L[i][l-1]; j <= L[i+1][l] and j < i; j++){
                best = min(best, {dp[j][l-1] + C(j, i), j});
            }
            dp[i][l] = best.first;
            L[i][l] = best.second;
            for(ll i=1;i<=n;i++){
                ll rest = c*((qx[n] - qx[i]) - i*(q[n] - q[i]));
                ans = min(ans, dp[i] + rest + l*b);
                dp_bef[i] = dp_cur[i];
                L_bef[i] = L_cur[i];
            }
        }
    }
    return 0;
}