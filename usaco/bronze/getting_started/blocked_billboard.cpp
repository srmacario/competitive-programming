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
    int x = 0, y = 0;
    point(int xx = 0, int yy = 0) : x(xx), y(yy){}
};

struct rect{
    point top_right, bottom_left;
    rect(point tr = point(), point bl = point()) : top_right(tr), bottom_left(bl){}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<rect> r;
    for(int i = 0; i < 3; i++){
        point tr, bl;
        cin >> bl.x >> bl.y >> tr.x >> tr.y;
        r.push_back(rect(tr, bl));
    }
    int ans = 0;
    for(int i = 0; i < 2; i++){
        int x[2] = {INF, INF}, y[2] = {INF, INF};
        x[0] = max(r[2].bottom_left.x, r[i].bottom_left.x);
        x[1] = min(r[2].top_right.x, r[i].top_right.x);
        y[0] = max(r[2].bottom_left.y, r[i].bottom_left.y);
        y[1] = min(r[2].top_right.y, r[i].top_right.y);
        ans += (r[i].top_right.x - r[i].bottom_left.x) * (r[i].top_right.y - r[i].bottom_left.y);
        if(x[0] <= x[1] and y[0] <= y[1])
             ans -= (y[1] - y[0]) * (x[1] - x[0]);
    }
    cout << ans << "\n";
    return 0;
}

/*
  


...
...
.xx   x
.xx
 x
*/