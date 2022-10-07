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
const int N = 105;

typedef long double type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }
int sign(type x) { return ge(x, 0) - le(x, 0); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(k*x, k*y); }
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
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
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

    // Project point on vector y
    point project(point y) { return y * ((*this * y) / (y * y)); }

    // Project point on line generated by points x and y
    point project(point x, point y) { return x + (*this - x).project(y-x); }

    ld dist_line(point x, point y) { return dist(project(x, y)); }

    ld dist_seg(point x, point y) {
        return project(x, y).on_seg(x, y) ? dist_line(x, y) :  min(dist(x), dist(y));
    }

    point rotate(ld sin, ld cos) { return point(cos*x - sin*y, sin*x + cos*y); }
    point rotate(ld a) { return rotate(sin(a), cos(a)); }

    // rotate around the argument of vector p
    point rotate(point p) { return rotate(p.y / p.abs(), p.x / p.abs()); }

};

int direction(point o, point p, point q) { return p.dir(o, q); }

point rotate_ccw90(point p)   { return point(-p.y,p.x); }
point rotate_cw90(point p)    { return point(p.y,-p.x); }

//for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
type area_2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

int angle_less(const point& a1, const point& b1, const point& a2, const point& b2) {
    //angle between (a1 and b1) vs angle between (a2 and b2)
    //1  : bigger
    //-1 : smaller
    //0  : equal
    point p1(dot(   a1, b1), abs(cross(   a1, b1)));
    point p2(dot(   a2, b2), abs(cross(   a2, b2)));
    if(cross(p1, p2) < 0) return 1;
    if(cross(p1, p2) > 0) return -1;
    return 0;
}

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

struct circle {
    point c;
    ld r;
    circle() { c = point(); r = 0; }
    circle(point _c, ld _r) : c(_c), r(_r) {}
    bool contains(point p) { return le(c.dist2(p), r * r); }
};

vector<point> circle_circle_intersection(point a, point b, ld r, ld R) {
    vector<point> ret;
    ld d = sqrt(a.dist2(b));
    if (d > r + R || d + min(r, R) < max(r, R)) return ret;
    ld x = (d*d - R*R + r*r)/(2*d);
    ld y = sqrt(r*r - x*x);
    point v = (b - a)/d;
    ret.push_back(a + v*x + rotate_ccw90(v)*y);
    if (y > 0)
        ret.push_back(a + v*x - rotate_ccw90(v)*y);
    return ret;
}

int n, cost[N], mark[N], o;
circle circ[N];
circle origin;

int above(point p){
    if(p.y == origin.c.y) return p.x > origin.c.x;
    return p.y > origin.c.y;
}

bool cmp(pair<pii, point> a, pair<pii, point> b){
    point p = a.nd, q = b.nd;
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    if(p.dir(origin.c,q) == 0) return a.st.st < b.st.st;
    return p.dir(origin.c,q) > 0;
    //Be Careful: p.dir(origin,q) == 0
}

bool point_circles_intersection(point p){
    for(int i = 0; i < n; i++){
        if(!circ[i].contains(p)) return false;
    }
    return true;
}

bool check(ld dist){
    for(int i = 0; i < n; i++){
        origin = circ[i];
        o = i;
        for(int i = 0; i < n; i++){
            circ[i].r = dist / cost[i];
            mark[i] = 0;
        }
        //open, id, point
        vector<pair<pii, point>> sweep;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(i == o) continue;
            if(le(circ[o].c.dist(circ[i].c) + circ[o].r, circ[i].r)){
                mark[i] = 1;
                cnt++;
                continue;
            }
            vector<point> inter = circle_circle_intersection(circ[o].c, circ[i].c, circ[o].r, circ[i].r);
            if(inter.empty()) continue;
            if(inter.size() == 1) return point_circles_intersection(inter[0]);
            sweep.push_back({{-1, i}, inter[1]});
            sweep.push_back({{1, i}, inter[0]});
        }
        sort(sweep.begin(), sweep.end(), cmp);
        int sz = sweep.size();
        sweep.resize(2 * sz);
        for(int i = 0; i < sz; i++) sweep[i + sz] = sweep[i];
        if(cnt == n - 1) return true;
        for(auto e : sweep){
            if(e.st.st == -1){
                if(!mark[e.st.nd]) cnt++;
                if(cnt == n - 1) return true;
                mark[e.st.nd] = 1;
            }
            else{
                if(mark[e.st.nd]) cnt--;
                mark[e.st.nd] = 0;
            }
        }
        if(cnt == n - 1) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> circ[i].c.x >> circ[i].c.y >> cost[i];
    }
    ld l = 0.0, r = 1e9;
    while((r - l) > EPS){
        ld m = (r + l) / 2;
        bool ok = check(m);
        if(ok) r = m;
        else l = m;
    }
    cout << setprecision(15) << fixed << l << "\n";
    return 0;
}