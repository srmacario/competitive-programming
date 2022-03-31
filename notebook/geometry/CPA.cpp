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

point ProjectPointRay(point c, point a, point b) {
    ld r = dot(b - a, b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if (le(r, 0)) return a;
    return a + (b - a)*r;
}

point ProjectPointSegment(point c, point a, point b) {
    ld r = dot(b - a, b - a);
    if (fabs(r) < EPS) return a;
    r = dot(c - a, b - a)/r;
    if (le(r, 0)) return a;
    if (ge(r, 1)) return b;
    return a + (b - a)*r;
}

ld DistancePointLine(point c, point a, point b) {
    return c.dist2(ProjectPointLine(c, a, b));
}

ld DistancePointRay(point c, point a, point b) {
    return c.dist2(ProjectPointRay(c, a, b));
}

ld DistancePointSegment(point c, point a, point b) {
    return c.dist2(ProjectPointSegment(c, a, b));
}

//not tested
ld DistancePointPlane(ld x, ld y, ld z,
                        ld a, ld b, ld c, ld d)
{
    return fabs(a*x + b*y + c*z - d)/sqrt(a*a + b*b + c*c);
}

bool LinesParallel(point a, point b, point c, point d) { 
    return fabs(cross(b - a, d - c)) < EPS; 
}

bool LinesCollinear(point a, point b, point c, point d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
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

bool LineLineIntersect(point a, point b, point c, point d) {
    if(!LinesParallel(a, b, c, d)) return true;
    if(LinesCollinear(a, b, c, d)) return true; 
    return false;
}

bool RayRayIntersect(point a, point b, point c, point d){
    if (a.dist2(c) < EPS || a.dist2(d) < EPS ||
        b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    if (LinesCollinear(a, b, c, d)) {
        if(ge(dot(b - a, d - c), 0)) return true;
        if(ge(dot(a - c, d - c), 0)) return true;
        return false;
    }
    if(!LineLineIntersect(a, b, c, d)) return false;
    point inters = lines_intersect(a, b, c, d);
    if(ge(dot(inters - c, d - c), 0) && ge(dot(inters - a, b - a), 0)) return true;
    return false;
}

bool SegmentSegmentIntersect(point a, point b, point c, point d) {
    if (a.dist2(c) < EPS || a.dist2(d) < EPS ||
        b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    int d1, d2, d3, d4;
    d1 = direction(a, b, c);
    d2 = direction(a, b, d);
    d3 = direction(c, d, a);
    d4 = direction(c, d, b);
    if (d1*d2 < 0 and d3*d4 < 0) return 1;
    return a.on_seg(c, d) or b.on_seg(c, d) or
            c.on_seg(a, b) or b.on_seg(c, d);
}

bool SegmentLineIntersect(point a, point b, point c, point d){
    if(!LineLineIntersect(a, b, c, d)) return false;
    point inters = lines_intersect(a, b, c, d);
    if(inters.on_seg(a, b)) return true;
    return false;
}

bool SegmentRayIntersect(point a, point b, point c, point d){
    if (a.dist2(c) < EPS || a.dist2(d) < EPS ||
        b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    if (LinesCollinear(a, b, c, d)) {
        if(c.on_seg(a, b)) return true;
        if(ge(dot(d - c, a - c), 0)) return true;
        return false;
    }
    if(!LineLineIntersect(a, b, c, d)) return false;
    point inters = lines_intersect(a, b, c, d);
    if(!inters.on_seg(a, b)) return false;
    if(ge(dot(inters - c, d - c), 0)) return true;
    return false; 
}

bool RayLineIntersect(point a, point b, point c, point d){
    if (a.dist2(c) < EPS || a.dist2(d) < EPS ||
        b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    if (!LineLineIntersect(a, b, c, d)) return false;
    point inters = lines_intersect(a, b, c, d);
    if(!LineLineIntersect(a, b, c, d)) return false;
    if(ge(dot(inters - a, b - a), 0)) return true;
    return false;
}

ld DistanceSegmentLine(point a, point b, point c, point d){
    if(SegmentLineIntersect(a, b, c, d)) return 0;
    return min(DistancePointLine(a, c, d), DistancePointLine(b, c, d));
}

ld DistanceSegmentRay(point a, point b, point c, point d){
    if(SegmentRayIntersect(a, b, c, d)) return 0;
    ld min1 = DistancePointSegment(c, a, b);
    ld min2 = min(DistancePointRay(a, c, d), DistancePointRay(b, c, d));
    return min(min1, min2);
}

ld DistanceSegmentSegment(point a, point b, point c, point d){
    if(SegmentSegmentIntersect(a, b, c, d)) return 0;
    ld min1 = min(DistancePointSegment(c, a, b), DistancePointSegment(d, a, b));
    ld min2 = min(DistancePointSegment(a, c, d), DistancePointSegment(b, c, d));
    return min(min1, min2);
}

ld DistanceRayLine(point a, point b, point c, point d){
    if(RayLineIntersect(a, b, c, d)) return 0;
    ld min1 = DistancePointLine(a, c, d);
    return min1;
}

ld DistanceRayRay(point a, point b, point c, point d){
    if(RayRayIntersect(a, b, c, d)) return 0;
    ld min1 = min(DistancePointRay(c, a, b), DistancePointRay(a, c, d));
    return min1;
}

ld DistanceLineLine(point a, point b, point c, point d){
    if(LineLineIntersect(a, b, c, d)) return 0;
    return DistancePointLine(a, c, d);
}

//Closest Point Approach
ld CPA(point p, point u, point q, point v){
    point w = p - q;
    if(fabs(dot(u - v, u - v)) < EPS) return LINF;
    return -dot(w, u - v)/dot(u - v, u - v);
}

pair <bool, ld> time_intersects(point p, point a, point b, point v, point u){
    ld num = (p.x - a.x)*(b.y - a.y) - (p.y - a.y)*(b.x - a.x);
    ld den = (v.x - u.x)*(b.y - a.y) - (v.y - u.y)*(b.x - a.x);
    // db(num _ den);
    if(eq(abs(num), 0.0) and eq(abs(u%v), 0.0)){
        // db(num _ u%v);
        if(!ge((b - a)*(u), 0)) swap(b, a);
        if(!le((p - a)*(b - a), 0)){
            if(le(u * v,  0) or !le(v.abs2(), u.abs2())){
                return{true, p.dist(b)/(u - v).abs()};
            }
            else{
                return {false, LINF};
            }
        }
        else{
            if(ge(u * v, 0) and !le(u.abs2(), v.abs2())){
                return{true, p.dist(a)/(u - v).abs()};
            }
            else{
                return {false, LINF};
            }
        }
    }
    if(eq(abs(den), 0)) return {false, LINF};
    ld ans = -num/den;
    if(ge(ans, 0)) return {true, ans};
    return {false, LINF};
}

point p[2][2], v[2];
ld ans = LINF;
bool ok = false;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) cin >> p[i][j].x >> p[i][j].y;
    for(int i = 0; i < 2; i++) cin >> v[i].x >> v[i].y;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            pair <bool, ld> t = time_intersects(p[i][j], p[i^1][0], p[i^1][1], v[i], v[i^1]);
            // db(t.st _ t.nd);
            if(!t.st) continue;
            if((p[i][j] + v[i]*t.nd).on_seg((p[i^1][0] + v[i^1]*t.nd), (p[i^1][1] + v[i^1]*t.nd))) ans = min(ans, t.nd), ok = true;
        }
    }
    if(!ok) cout << "-1\n";
    else cout << setprecision(18) << fixed << ans << "\n";
    return 0;
}