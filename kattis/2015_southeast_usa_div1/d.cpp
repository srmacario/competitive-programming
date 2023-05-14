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

int n, a[N], b[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a/gcd(a, b)*b; }

void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

ll norm(ll x, ll mod) { x %= mod; return x<0 ? x+mod : x; }

ll chinese() {
  ll ans = a[0], l = b[0];
  for (int i = 1; i < n; i++) {
    ll x, y, d;
    euclid(l, b[i], x, y, d);
    if ((a[i] - ans) % d != 0) {
      // no solution
      return -1;
    }

    ans = norm(ans + x * (a[i] - ans) / d % (b[i] / d) * l, l * b[i] / d);
    l = lcm(l, b[i]);
  }

  return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &b[i], &a[i]);
            if(i%2) a[i] = b[i] - a[i];
        }
        ll ans = chinese();
        if(ans == -1) printf("Impossible\n");
        else printf("%lld\n", ans);
    }
    return 0;
}