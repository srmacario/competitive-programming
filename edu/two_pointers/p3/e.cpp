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
const int N = 3e5+5;

ll n;
ll p, w[N], c[N], s, ans;

int main(){
    scanf("%lld%lld", &n, &p);
    for(ll i = 1; i <= n; i++) scanf("%lld", &w[i]);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &c[i]);
        c[i] += c[i - 1];
    }
    for(ll r = 1, l = 1; r <= n; r++){
        s += w[r];
        while(s > p) s -= w[l++];
        ans = max(ans, c[r] - c[l - 1]);
    }
    printf("%lld\n", ans);
    return 0;
}