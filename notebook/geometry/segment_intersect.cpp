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

typedef long double type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

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

    bool operator ==(point p) { return x == p.x and y == p.y; }
    bool operator !=(point p) { return x != p.x  or y != p.y; }
    bool operator <(const point p) const { return (x < p.x) or (x == p.x and y < p.y); }

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
    point rotate(point p) { return rotate(p.x / p.abs(), p.y / p.abs()); }

};

int direction(point o, point p, point q) { return p.dir(o, q); }

point RotateCCW90(point p)   { return point(-p.y,p.x); }
point RotateCW90(point p)    { return point(p.y,-p.x); }

type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

type area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

point ProjectPointLine(point c, point a, point b) {
    ld r = dot(b - a,b - a);
    if (fabs(r) < EPS) return a;
    return a + (b - a)*dot(c - a, b - a)/dot(b - a, b - a);
}

point ProjectPointSegment(point c, point a, point b) {
    ld r = dot(b - a,b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a)/r;
    if (!ge(r, 0)) return a;
    if (!le(r, 1)) return b;
    return a + (b - a)*r;
}

point ProjectPointRay(point c, point a, point b) {
    ld r = dot(b - a,b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if (!ge(r, 0)) return a;
    return a + (b - a)*r;
}

ld DistancePointSegment(point c, point a, point b) {
    return c.dist2(ProjectPointSegment(c, a, b));
}

ld DistancePointLine(point c, point a, point b) {
    return c.dist2(ProjectPointLine(c, a, b));
}

ld DistancePointRay(point c, point a, point b) {
    return c.dist2(ProjectPointRay(c, a, b));
}

ld DistancePointPlane(ld x, ld y, ld z,
                        ld a, ld b, ld c, ld d)
{
    return fabs(a*x + b*y + c*z - d)/sqrt(a*a + b*b + c*c);
}

bool LinesParallel(point a, point b, point c, point d) { 
    return fabs(cross(b - a, c - d)) < EPS; 
}

bool LinesCollinear(point a, point b, point c, point d) { 
    return LinesParallel(a, b, c, d)
        && fabs(cross(a - b, a - c)) < EPS
        && fabs(cross(c - d, c - a)) < EPS; 
}

point lines_intersect(point p, point q, point a, point b) {
    point r = q - p, s = b - a, c(p%q, a%b);
    if (eq(r%s,0)) return point(LINF, LINF);
    return point(point(r.x, s.x) % c, point(r.y, s.y) % c) / (r%s);
}

point ComputeLineIntersection(point a, point b, point c, point d) {
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

bool LinesIntersect(point a, point b, point c, point d) {
    if(!LinesParallel(a, b, c, d)) return true;
    if(LinesCollinear(a, b, c, d)) return true; 
    return false;
}

bool SegmentsIntersect(point p, point q, point a, point b) {
    int d1, d2, d3, d4;
    d1 = direction(p, q, a);
    d2 = direction(p, q, b);
    d3 = direction(a, b, p);
    d4 = direction(a, b, q);
    if (d1*d2 < 0 and d3*d4 < 0) return 1;
    return p.on_seg(a, b) or q.on_seg(a, b) or
            a.on_seg(p, q) or b.on_seg(p, q);
}

vector<point> CalcSegInter(point a, point b, point c, point d){
    vector<point> ans;
    if(!SegmentsIntersect(a, b, c, d)) return ans;
    if(c.on_seg(a, b)) ans.pb(c);
    if(d.on_seg(a, b)) ans.pb(d);
    if(a.on_seg(c, d)) ans.pb(a);
    if(b.on_seg(c, d)) ans.pb(b);
    if(!LinesParallel(a, b, c, d)){
        point inter = lines_intersect(a, b, c, d);
      if(inter.x + EPS < INF) ans.pb(inter);
    }
    return ans;
}
 
bool cmp(point a, point b){
  if(eq(a.x,b.x)) return le(a.y,b.y);
  return le(a.x,b.x);
}

point pts[4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(18) << fixed;
    for(int i = 0; i < 4; i++) cin >> pts[i].x >> pts[i].y;
    vector<point> ans = CalcSegInter(pts[0], pts[1], pts[2], pts[3]);
    if(!ans.size()) cout << "Empty\n";
    else{
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0; i < ans.size(); i++){
        point p = ans[i];
        if(i)
          if(eq(ans[i].x, ans[i-1].x) and eq(ans[i].y, ans[i-1].y)) continue;
            cout << p.x << " " << p.y << "\n";
        }
    }
    return 0;
}