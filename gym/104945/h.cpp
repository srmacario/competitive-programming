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

typedef long double type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }
int sign(type x) { return ge(x, 0) - le(x, 0); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(x*k, y*k); }
    point operator /(type k) { return point(x/k, y/k); }

    //inner product
    type operator *(point p) { return x*p.x + y*p.y; }
    //cross product
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x  or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }

    // 0 => same direction
    // 1 => p is on the left 
    //-1 => p is on the right    
    int dir(point o, point p) {
        type d = (*this - o) % (p - o);
        return ge(d, 0) - le(d, 0);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
    ld dist(point q) { return (*this - q).abs(); }
    type dist2(point q) { return (*this - q).abs2(); }

    ld arg() { return atan2l(y, x); }
};

point origin;

int above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(point p, point q){
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin, q) > 0;
}

type compute_signed_area(const vector<point> &p) {
    type area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area;
}


point compute_centroid(vector<point> &p) {
    point c(0,0);
    ld scale = 3.0 * compute_signed_area(p);
    for (int i = 0; i < p.size(); i++){
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<point> pts(n), npts;
    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    point center = compute_centroid(pts);
    origin = center;
    for(auto p : pts){
        if(eq(center.x, p.x) and eq(center.y, p.y)) continue;
        npts.push_back(p);
    }
    pts = npts;
    n = pts.size();
    sort(pts.begin(), pts.end(), cmp);
    pts.resize(3 * n);
    vector<ll> lval(3 * n), psval(3 * n + 1);
    for(int i = 0; i < n; i++) pts[i + 2 * n] = pts[i + n] = pts[i];

    ll ans = 0;
    for(int l = 0, r = n; r < 3 * n; r++){
        while(pts[r].dir(origin, pts[l]) >= 0 and l < r){
            if(pts[r].dir(origin, pts[l]) == 0 and origin.on_seg(pts[r], pts[l])) ans -= n - 2;
            l++;
        }
        lval[r] = l;
    }
    ans /= 4;
    //[i, j] => psval[j + 1] - psval[i]
    for(int i = 0; i < 3 * n; i++){
        psval[i + 1] = psval[i] + lval[i];
    }
    for(int l = 2 * n; l < 3 * n; l++){
        ll cur = (l - lval[l]) * lval[l] - (psval[l] - psval[lval[l]]);
        ans += cur;
    }
    cout << ans/3  << "\n";
    return 0;
}