
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
const int N = 1e3+5;

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
    point rotate(point p) { return rotate(p.x / p.abs(), p.y / p.abs()); }

};

int direction(point o, point p, point q) { return p.dir(o, q); }

point RotateCCW90(point p)   { return point(-p.y,p.x); }
point RotateCW90(point p)    { return point(p.y,-p.x); }

//for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
type area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

bool LinesParallel(point a, point b, point c, point d) {
    return fabs(cross(b - a, d - c)) < EPS; 
}

bool LinesCollinear(point a, point b, point c, point d) {
    // Degenerate case
    //if((a == c and b == d) || (a == d and b == c)) return true;
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool LineLineIntersect(point a, point b, point c, point d) {
    if(!LinesParallel(a, b, c, d)) return true;
    if(LinesCollinear(a, b, c, d)) return true; 
    return false;
}

point lines_intersect(point p, point q, point a, point b) {
    point r = q - p, s = b - a, c(p%q, a%b);
    if (eq(r%s,0)) return point(LINF, LINF);
    return point(point(r.x, s.x) % c, point(r.y, s.y) % c) / (r%s);
}

bool SegmentLineIntersect(point a, point b, point c, point d){
    // Degenerate case
    // if((a == c and b == d) || (a == d and b == c)) return true;
    if(!LineLineIntersect(a, b, c, d)) return false;
    point inters = lines_intersect(a, b, c, d);
    if(inters.on_seg(a, b)) return true;
    return false;
}

bool upward_edge(point a, point b, point c, point d){
    //Line: a - b
    //Edge: c - d
    //Edge who comes from bottom to top (or from right to left), but does not consider the final endpoint
    return (direction(a, b, c) < 1 and direction(a, b, d) == 1);
}

bool downward_edge(point a, point b, point c, point d){
    //Line: a - b
    //Edge: c - d
    //Edge who comes from top to bottom (or from left to right), but does not consider the initial endpoint
    return (direction(a, b, c) == 1 and direction(a, b, d) < 1);
}

int n, m;
vector <point> pts;
point lines[2][N];
vector<point> inters;

type calc(int i){
    type ans = 0;
    inters.clear();
    vector<pair<point, int>> sweep;
    //See for each edge if it intercepts:

    for(int j = 0; j < n; j++){
        //Check upward and downward for info
        //upward and downward disconsider "horizontal" edges
        if(upward_edge(lines[0][i], lines[1][i], pts[j], pts[(j + 1)%n]) || downward_edge(lines[0][i], lines[1][i], pts[j], pts[(j + 1)%n]))
            inters.push_back(lines_intersect(lines[0][i], lines[1][i], pts[j], pts[(j + 1)%n]));
        //if not upward or downward check if it is a collinear edge
        else if(LinesCollinear(lines[0][i], lines[1][i], pts[j], pts[(j + 1)%n])){
            point a = pts[j];
            point b = pts[(j + 1)%n];
            if(b < a) swap(a, b);
            sweep.push_back({a, -1});
            sweep.push_back({b, 1});
        }
    }
    //Add interceptions to the sweep:
    //even: line enters the polygon
    //odd: line leaves the polygon
    sort(inters.begin(), inters.end());
    int mult = -1;
    for(int j = 0; j < inters.size(); j++){
        sweep.push_back({inters[j], mult});
        mult *= -1;
    }
    sort(sweep.begin(), sweep.end());
    int open = 0;
    point ini;
    for(int j = 0; j < sweep.size(); j++){
        pair <point, int> p = sweep[j];
        //-1: enters the polygon
        if(p.nd == -1){
            open++;
            //first interception
            if(open == 1) ini = p.st;
        }
        //1: leaves the polygon
        if(p.nd == 1) open--;
        if(open == 0) {
            //last interception, compute distance inside the polygon
            ans += sweep[j].st.dist(ini);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    pts.resize(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    //REMOVE COLLINEAR POINTS: not necessary.
    // for(int i = 0; i < pts.size(); i++){
    //     if(direction(pts[i], pts[(i - 1 + (int)pts.size())%pts.size()], pts[(i + 1)%pts.size()]) == 0) db(i), pts.erase(pts.begin() + i), i--;
    // }
    for(int i = 0; i < m; i++){
        cin >> lines[0][i].x >> lines[0][i].y;
        cin >> lines[1][i].x >> lines[1][i].y;
    }
    for(int i = 0; i < m; i++){
        type ans = 0;
        ans = calc(i);
        cout << setprecision(15) << fixed << ans << "\n";
    }
    return 0;
}