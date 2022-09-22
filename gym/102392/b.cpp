#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n, s1, s2;
int x[N], r[N], y[N], t[N];
ll dp[N][N];
pii ord[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 63, sizeof(dp));
    cin >> n >> s1 >> s2;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> t[i] >> y[i] >> r[i];
        ord[i] = {x[i], i};
    }
    dp[0][0] = 0;
    sort(ord, ord + n);
    for(int p = 0; p < n; p++){
        int i = ord[p].nd;
        for(int j = s1 - 1 + x[i]; j >= 0; j--){
            for(int k = N - 1; k >= 0; k--){
                if(j >= x[i])
                    dp[j][k] = min(dp[j][k], dp[j - x[i]][k] + t[i]);
                if(k >= y[i])
                    dp[j][k] = min(dp[j][k], dp[j][k - y[i]] + r[i]);
            }
        }
    }
    ll ans = LINF;
    for(int i = s1; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i + j >= s1 + s2) ans = min(ans, dp[i][j]);
        }
    }
    if(ans == LINF) cout << "-1\n";
    else cout << ans << "\n";
}