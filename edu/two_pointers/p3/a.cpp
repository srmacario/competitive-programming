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
const int N = 2e3+5;

ll n;
ll p, a[N], s, tot, inc;
plll ans = {LINF, {LINF, LINF}};

int main(){
    scanf("%lld%lld", &n, &p);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        a[n + i] = a[i];
        tot += a[i];
    }
    inc = (p/tot)*n;
    p %= tot;
    // db(inc _ p);
    if(p){
        for(int r = 0, l = 0; r < 2 * n; r++){
            s += a[r];
            while(s - a[l] >= p) s -= a[l++];
            if(s >= p){
                plll tmp = {s, {l + 1, r - l + 1}};
                if(ans.nd.nd > tmp.nd.nd)
                    ans = tmp;
            }
        }
    }
    else ans = {0, {1, 0}};
    printf("%lld %lld\n", ans.nd.st, ans.nd.nd + inc);
    return 0;
}