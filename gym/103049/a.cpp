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
const int N = 105, M = 1e5;

int n, q;
ll mn[M];
pair<ld, int> best = {INF, INF};

int main(){
    cl(mn, 63);
    scanf("%d%d", &n, &q);

    for(int i = 1; i <= n; i++){
        scanf("%lld", &mn[i]);
        best = min(best, {mn[i]/(ld)i, i});
    }
    for(int i = n+1; i <= 2*n + 1; i++){
        for(int j = 1; j <= n; j++){
            mn[i] = min(mn[i], mn[i-j] + mn[j]);
        }
    }
    for(int i = 0; i < q; i++){
        ll k;
        scanf("%lld", &k);
        if(k > 2 * n + 1){
            ll x = (k - (2*n + 1) * n - 1)/(best.nd) + 1;
            printf("%lld\n", mn[k - x*best.nd] + x*mn[best.nd]);
        }
        else printf("%lld\n", mn[k]);
    }
    return 0;
}