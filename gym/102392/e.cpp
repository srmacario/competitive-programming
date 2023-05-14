#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, k, can[3][N];
ll a[N], give[3][N], need[3][N], l[3], p[3], t, d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> l[2] >> p[2] >> l[1] >> p[1] >> t >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++) give[j][i] = give[j][i - 1], need[j][i] = need[j][i - 1];

        give[0][i] += min(a[i] - 1ll, d);
        give[1][i] += min(max(a[i] - l[1], 0ll), d);
        give[2][i] += min(max(a[i] - l[2], 0ll), d);

        need[1][i] += max(0ll, l[1] - a[i]);
        if(l[1] - a[i] > d) can[1][i] = 0;
        else can[1][i] = 1;

        need[2][i] += max(0ll, l[2] - a[i]);
        if(l[2] - a[i] > d) can[2][i] = 0;
        else can[2][i] = 1;
    }

    //0 ->  moto, 1 -> carro
    //need, give 1 -> moto, 2 -> carro
    ll ans = LINF;
    for(int m = 0; m <= n; m++){
        ll c = (n - m + k - 1) / k;
        if(m and !can[1][n - c - m + 1]) continue;
        if(c and !can[2][n - c + 1]) continue;
        ll tot_need = (need[2][n] - need[2][n - c]) + (need[1][n - c] - need[1][n - c - m]);
        ll tot_give = (give[2][n] - give[2][n - c]) + (give[1][n - c] - give[1][n - c - m]) + give[0][n - c - m];
        if(tot_need > tot_give) continue;
        ll cur = tot_need * t + p[2] * c + p[1] * m;
        ans = min(cur, ans);
    }

    if(ans == LINF) cout << "-1\n";
    else cout << ans << "\n";
}