
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
const int N = 5e5+5;

typedef long double type;
//for big coordinates change to long long

bool ge(type x, type y) { return x >= y; }
bool le(type x, type y) { return x <= y; }
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

ll n, w, h;
vector <point> pts;

type idx = 0;

point compute_line_intersection(point a, point b, point c, point d) {
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

bool cmp(pair<point, point> a, pair<point, point> b){
    point l = {-1, idx + 0.5}, r = {N - 1, idx + 0.5};
    point lhs = compute_line_intersection(l, r, a.st, a.nd);
    point rhs = compute_line_intersection(l, r, b.st, b.nd);
    return lhs < rhs;
}

type calc(int i){
    idx = i;
    //declare
    db(i);
    long long ans = 0;
    vector<pair<point, point>> inters;

    //See for each edge if it intercepts:
    pair<point, point> line = {{-1, i + 0.5}, {N - 1, i + 0.5}};
    for(int j = 0; j < n; j++){
        if(direction(line.st, line.nd, pts[j]) * direction(line.st, line.nd, pts[(j + 1) % n]) < 1){
            point a = pts[j];
            point b = pts[(j + 1) % n];
            if(b < a) swap(a, b);
            inters.push_back({a, b});
        }
    }

    //Add interceptions to the sweep:
    //even: line enters the polygon
    //odd:  line leaves the polygon
    sort(inters.begin(), inters.end(), cmp);
    type ini;
    for(int j = 0; j < inters.size(); j++){
        pair<point, point> cur = inters[j];
        if(cur.nd.y < cur.st.y) swap(cur.nd, cur.st);
        // db(cur.st _ cur.nd);
        //-1: enters the polygon
        if(!(j % 2)){ 
            point lhs = compute_line_intersection(line.st, line.nd, a.st, a.nd);
        }
        //1: leaves the polygon
        else {
            // db(1 _ cur.st _ cur.nd);
            //last interception, compute interval inside the polygon
            int h = i + 1;
            if(cur.st.x > cur.nd.x) h = i - 1;
            // db(h);
            type a = ini;
            // db(a _ b);
            if(a % 2) a--;
            if(b % 2) b++;
            ans += b - a;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //multiply points per 2
    cin >> n >> w >> h;
    pts.resize(n);
    type min_y = INF, max_y = 0;
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
        min_y = min(min_y, pts[i].y);
        max_y = max(max_y, pts[i].y);
    }

    long long ans = 0;
    for(int i = max_y; i > min_y; i --){
        ans += calc(i);
    }
    cout << ans/2 << "\n";
    return 0;
}