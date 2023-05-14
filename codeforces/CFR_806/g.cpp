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

int coin[N], pot[32];
ll dp[32][N];
int n, k;

ll calc(int div, int pos){
    if(div >= 30) return 0;
    if(pos == n) return 0;
    if(dp[div][pos] != LINF) return dp[div][pos];
    ll ans = coin[pos];
    return dp[div][pos] = max(ans/pot[div] + calc(div, pos + 1) - k, calc(div + 1, pos + 1) + ans/pot[div + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    pot[0] = 1;
    for(int i = 1; i < 31; i++) pot[i] = pot[i - 1] * 2;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++) dp[j][i] = LINF;
        }
        for(int i = 0; i < n; i++) cin >> coin[i];
        cout << calc(0, 0) << "\n";
    }
    return 0;
}