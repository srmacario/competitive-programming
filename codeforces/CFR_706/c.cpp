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


bool cmp(pll a, pll b){
    if(a.st == 0) return abs(a.nd) < abs(b.nd);
    else return abs(a.st) < abs(b.st);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        vector<pll> m, d;
        int n;
        scanf("%d", &n);
        for(int i = 0; i < 2*n; i++){
            ll x,  y;
            scanf("%lld%lld", &x, &y);
            if(x == 0) m.pb({x,y});
            else d.pb({x,y});
        }
        sort(d.begin(), d.end(), cmp);
        sort(m.begin(), m.end(), cmp);
        ld ans = 0;
        // for(auto x: m) printf("%lld %lld ", x.st, x.nd);
        // printf("\n\n");
        // for(auto x: d) printf("%lld %lld ", x.st, x.nd);
        // printf("\n\n");
        for(int i = 0; i < n; i++){
            ll x = (m[i].st-d[i].st)*(m[i].st-d[i].st);
            ll y = (m[i].nd-d[i].nd)*(m[i].nd-d[i].nd);
            ans += sqrt(x + y);
        }
        printf("%.15Lf\n", ans);
    }
    return 0;
}