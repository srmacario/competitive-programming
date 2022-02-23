/*
    rotating calipers (same problem as minimum triangle):
    idea:   sort points by x, than y
            sort all posible edges radially with respect to the edge perpendicular!
            start processing they on a sweep, every time you encounter one edge its time to process
            process means that the points from the edge will change places on the vector
            for min triangle: min triangle will be made with the current edge and adjacent points
            for max triangle: max triangle will be made with current edge and farthest points (0, n - 1)
            for this problem: pick first after r and first before l
*/
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

typedef long long type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
    type x, y;

    point() : x(0), y(0){}
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
        return (x >= 0) - (x <= 0);
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

point RotateCCW90(point p)   { return point(-p.y, p.x); }
point RotateCW90(point p)    { return point(p.y, -p.x); }

//for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
type area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

point origin;

int above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(pair<point, point> a, pair<point, point> b){
    point p = RotateCW90(a.nd - a.st);
    point q = RotateCW90(b.nd - b.st);
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin, q) > 0;
}

int n;
int main(){
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++){
        scanf("%d", &n);
        vector<point> pts(n);
        for(int i = 0; i < n; i++){
            scanf("%lld%lld", &pts[i].x, &pts[i].y);
        }
        //sort points (base direction: x)
        map<point, int> id;
        sort(pts.begin(), pts.end());
        for(int i = 0; i < n; i++){
            point p = pts[i];
            id[p] = i;
        }

        //create edges and sort perpendicular radially
        vector<pair<point, point>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                edges.pb({pts[i], pts[j]});
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        
        ll ans = LLONG_MAX;

        //min quad area
        //points will be adjacent if theres not 3 collinear points
        //a.nd - a.st => rotateCW
        //a.st - a.nd => rotateCCW
        for(auto e : edges){
            ll tmp = 0;
            int l = id[e.st], r = id[e.nd];
            if(l > r) swap(l, r);
            //choose first point above and first point below
            if(l > 0 and r < n - 1){
                tmp = abs(area2(pts[l - 1], pts[l], pts[r])) + abs(area2(pts[l], pts[r], pts[r + 1]));
                ans = min(ans, tmp);
            }
            swap(pts[l], pts[r]);
            swap(id[e.nd], id[e.st]);
        }
        printf("Case #%d: %lld\n", k, ans);
    }
    return 0;
}