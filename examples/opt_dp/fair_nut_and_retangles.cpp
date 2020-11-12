#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int N = 1e6+5;

typedef long long type;
struct line { type b, m; };

int nh, pos;
line hull[N];

bool check(line s, line t, line u) {
    return (u.b - t.b) / ld(u.m - t.m) > (t.b - s.b) / ld(t.m - s.m);
}

void update(line s) {
  while (nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) nh--;
  pos = min(pos, nh);
  hull[nh++] = s;
}

type eval(int id, type x) { return hull[id].b + hull[id].m * x; }

type query(type x) {
  while (pos+1 < nh and eval(pos, x) < eval(pos+1, x)) pos++;
  return eval(pos, x);
}

struct rect{
    type x = 0,y = 0,a = 0;
};

bool cmp(rect a, rect b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

type n, dp[N];
vector <rect> r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        rect aux;
        r.pb(aux);
        cin >> r[i].x >> r[i].y >> r[i].a;
    }
    ll ans = -LINF;
    sort(r.begin(),r.end(),cmp);
    //update({0,0});
    for(int i=0;i<n;i++){
        ll aux = 0;
        if(i) aux = max(query(r[i].y),aux);
        dp[i] = (r[i].x*r[i].y - r[i].a) + aux;
        ans = max(ans,dp[i]);
        update({dp[i],-r[i].x});
    }
    cout << ans << "\n";
    return 0;
}