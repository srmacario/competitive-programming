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
const int N = 1e5+5;

int n, m;
ll s, A, B, a[N], b[N], cost, tot, ans, l, r;

int main(){
    scanf("%d%d%lld%lld%lld", &n, &m, &s, &A, &B);
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for(int i = 0; i < m; i++) scanf("%lld", &b[i]);
    sort(a, a + n), sort(b, b + m);
    // printf("\n");
    // for(int i = 0; i < n; i++) printf("%lld ", a[i]);
    // printf("\n");
    // for(int i = 0; i < m; i++) printf("%lld ", b[i]);
    // printf("\n");
    for(l = n - 1; l >= 0 and cost + A <= s; l--){
        tot += a[l], cost += A;
    }
    l++;
    ans = tot;
    // db(ans _ cost _ l);
    for(r = m - 1; r >= 0; r--){
        tot += b[r], cost += B;
        while(l < n and cost > s){
            tot -= a[l++];
            cost -= A;
        }
        if(cost <= s) ans = max(ans, tot);
    }
    printf("%lld\n", ans);
    return 0;
}