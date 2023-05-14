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
const int N = 5005;

int n, a[N];
ll d[N][N], ps[N], dp[N][N];

ll dist(int d){
    //return 2 * ps[(d / 2)] + (d % 2) * a[(d + 1) / 2];
    return ps[d];
}

ll calc(int i, int j){
    if(((n + j - i)%n - 1) == 0) return dp[i][j] = 0;
    if(dp[i][j] != -1) return dp[i][j];
    //db(i _ j);
    int k = (i + 1) % n;
    dp[i][j] = d[i][j];
    while(k != j){
        dp[i][j] = max(dp[i][j], calc(i, k) + calc(k, j));
        k = (k + 1) % n;
    }
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i - 1] + a[(i) / 2];
        // db(i _ ps[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) d[i][j] = dist(n - 1); 
            else d[i][j] = dist((n + j - i)%n - 1);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, calc(i, i));
    }
    cout << ans << "\n";
    return 0;
}