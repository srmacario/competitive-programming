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
const int N = 2e5+5;
const int M = 100;

int n, k;

typedef double type;
struct line { type b, m; };

struct cht{
    int nh = 0, pos = 0;
    vector<line> hull;

    bool check(line s, line t, line u) {
        return (t.b - s.b) / ld(s.m - t.m) < (u.b - s.b) / ld(s.m - u.m);
    }

    void update(line s) {
        while (nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) hull.pop_back(), nh--;
        hull.pb(s);
        nh++;
    }
    type eval(line t, line s) { return (t.b - s.b) / ld(s.m - t.m);}

    type query(type x) {
        int lo = 0, hi = nh-1;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (eval(hull[mid-1], hull[mid]) >= ld (x)) hi = mid-1;
            else lo = mid;
        }
        return hull[lo].b + hull[lo].m * x;
    }
};

double t[N], sum[N], revsum[N], pre[N], dp[N][M];

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &t[i]);
        sum[i] = sum[i-1] + t[i];
        revsum[i] = revsum[i-1] + 1.0/t[i];
        pre[i] = pre[i-1] + sum[i]/t[i];
        dp[i][1] = pre[i];
    }
    for(int j = 2; j <= k; j++){
        cht h;
        for(int i = j; i <= n; i++){
            ld aux = 0;
            h.update({dp[i-1][j-1] - pre[i-1] + revsum[i-1]*sum[i-1], -sum[i-1]});
            dp[i][j] = pre[i] + h.query(revsum[i]);
        }
    }
    printf("%.10lf\n", dp[n][k]);
    return 0;
}