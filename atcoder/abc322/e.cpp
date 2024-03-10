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
const int N = 105;

int c[N], a[N][10];
ll dp[10][10][10][10][10];

bool cmp(int a, int b){
    return c[a] < c[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 63, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i;
        cin >> c[i];
        for(int j = 1; j <= k; j++) cin >> a[i][j];
        for(int j = k + 1; j <= 5; j++) a[i][j] = 5;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        for(int i1 = p; i1 >= 0; i1--){
            for(int i2 = p; i2 >= 0; i2--){
                for(int i3 = p; i3 >= 0; i3--){
                    for(int i4 = p; i4 >= 0; i4--){
                        for(int i5 = p; i5 >= 0; i5--){
                            int ni1 = min(p, i1 + a[v[i]][1]);
                            int ni2 = min(p, i2 + a[v[i]][2]);
                            int ni3 = min(p, i3 + a[v[i]][3]);
                            int ni4 = min(p, i4 + a[v[i]][4]);
                            int ni5 = min(p, i5 + a[v[i]][5]);
                            dp[ni1][ni2][ni3][ni4][ni5] = min(dp[ni1][ni2][ni3][ni4][ni5], dp[i1][i2][i3][i4][i5] + c[v[i]]);
                        }
                    }
                }
            }
        }
    }
    cout << (dp[p][p][p][p][p] == LINF ? -1 : dp[p][p][p][p][p]) << "\n";
    return 0;
}