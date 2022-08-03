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
const int N = 1e5+5;

struct point{
    ll x = 0, y = 0;
    point(ll xx = 0, ll yy = 0) : x(xx), y(yy){}
};

struct rect{
    point bottom_left, top_right;
    rect(point bl = point(), point tr = point()) : bottom_left(bl), top_right(tr){}
};

rect calc_inter(rect a, rect b){
    ll x[2], y[2];
    x[0] = max(a.bottom_left.x, b.bottom_left.x);
    x[1] = min(a.top_right.x, b.top_right.x);
    y[0] = max(a.bottom_left.y, b.bottom_left.y);
    y[1] = min(a.top_right.y, b.top_right.y);
    return {{x[0], y[0]}, {x[1], y[1]}};
}

inline ll calc_area(rect cur){
    return (cur.top_right.x - cur.bottom_left.x) * (cur.top_right.y - cur.bottom_left.y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);
    vector<rect> r, inter;
    for(int i = 0; i < 3; i++){
        point tr, bl;
        cin >> bl.x >> bl.y >> tr.x >> tr.y;
        r.push_back(rect(bl, tr));
    }
    ll ans = calc_area(r[0]);
    for(int i = 1; i <= 2; i++){
        rect cur = calc_inter(r[0], r[i]);
        if(cur.bottom_left.x < cur.top_right.x and cur.bottom_left.y < cur.top_right.y){
            inter.push_back(cur);
            ans -= calc_area(cur);
        }
    }
    if(inter.size() == 2){
        rect cur = calc_inter(inter[0], inter[1]);
        if(cur.bottom_left.x < cur.top_right.x and cur.bottom_left.y < cur.top_right.y){
            ans += calc_area(cur);
        }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

/*
  


...
...
.xx   x
.xx
 x
*/