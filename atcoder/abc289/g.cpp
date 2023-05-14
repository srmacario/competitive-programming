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
const int N = 2e5+5;

typedef long long type;

type n, m;
type b[N], ans[N];
pll c[N];

struct line {
    type b, m;
    line(ll _b = 0, ll _m = 0) : b(_b), m(_m) {}
};

int nh, pos;
line hull[N];

bool check(line s, line t, line u) {
  // verify if it can overflow. If it can just divide using long double
  __int128 a = (s.b - t.b);
  a = a * (u.m - s.m);
  __int128 b = (s.b - u.b) * (t.m - s.m);
  b = b * (t.m - s.m);
  return a < b;
}

void update(line s){
  if(nh == 1 and hull[nh-1].b == s.b) nh--;
  if (nh > 0  and hull[nh-1].m >= s.m) return;
  while (nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) nh--;
  pos = min(pos, nh);
  hull[nh++] = s;
}

type eval(int id, type x) { return hull[id].b + hull[id].m*x; }

// Linear Query
// queries always move to the right

type query(type x) {
  while (pos+1 < nh and eval(pos, x) < eval(pos+1, x)) pos++;
  return eval(pos, x);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= m; i++){
        cin >> c[i].st;
        c[i].nd = i;
    }
    sort(b, b + n + 1);
    for(int i = n; i >= 1; i--) update({(n - i + 1) * b[i], (n - i + 1)});
    sort(c, c + m + 1);
    for(ll i = 1; i <= m; i++){
        ans[c[i].nd] = query(c[i].st);
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}