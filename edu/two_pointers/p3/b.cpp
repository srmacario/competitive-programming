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

ll n;
ll p, a[N], s, ans;

int main(){
    scanf("%lld%lld", &n, &p);
    for(ll i = 0; i < n; i++) scanf("%lld", &a[i]);
    for(ll r = 0, l = 0; r < n; r++){
        s += a[r];
        while(s > p) s -= a[l++];
        ans += ((1 + r - l + 1) * (r - l + 1))/ 2;
    }
    printf("%lld\n", ans);
    return 0;
}