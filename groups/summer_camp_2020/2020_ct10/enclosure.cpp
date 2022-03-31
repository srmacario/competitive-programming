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
const int N = 3e5+5;

typedef long long type;
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

int angleLess(const point& a1, const point& b1, const point& a2, const point& b2) {
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

point origin;

int above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(point p, point q){
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin,q) > 0;
    //if(p.dir(origin,q) == 0) return p.abs2
}

//Monotone chain O(nlog(n))

void ConvexHull(vector<point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

bool pointInTriangle(point a, point b, point c, point cur){
    ll s1 = abs(cross(b - a, c - a));
    ll s2 = abs(cross(a - cur, b - cur)) + abs(cross(b - cur, c - cur)) + abs(cross(c - cur, a - cur));
    return s1 == s2;
}

void sort_lex_hull(vector<point> &hull){
    int n = hull.size();

    //Sort hull by x
    int pos = 0;
    for(int i = 1; i < n; i++) if(hull[i] <  hull[pos]) pos = i;
    rotate(hull.begin(), hull.begin() + pos, hull.end());
}

//determine if point is inside or on the boundary of a polygon (O(logn))
bool pointInConvexPolygon(vector<point> &hull, point cur){
    int n = hull.size();
    //Corner cases: point outside most left and most right wedges
    if(cur.dir(hull[0], hull[1]) != 0 && cur.dir(hull[0], hull[1]) != hull[n - 1].dir(hull[0], hull[1]))
        return false;
    if(cur.dir(hull[0], hull[n - 1]) != 0 && cur.dir(hull[0], hull[n - 1]) != hull[1].dir(hull[0], hull[n - 1]))
        return false;

    //Binary search to find which wedges it is between
    int l = 1, r = n - 1;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(cur.dir(hull[0], hull[mid]) <= 0)l = mid;
        else r = mid;
    }
    return pointInTriangle(hull[l], hull[l + 1], hull[0], cur);
}

int tangent(vector<point> &hull, point vec, int dir_flag) {
	// this code assumes that there are no 3 colinear points
    // dir_flag = -1 for right tangent
    // dir_flag =  1 for left taangent
	int ans = 0;
	int n = hull.size();
	if(n < 20) {
		for(int i = 0; i < n; i++) {
			if(hull[ans].dir(vec, hull[i]) == dir_flag) {
				ans = i;
			}
		}
	} else {
		if(hull[ans].dir(vec, hull[1]) == dir_flag) {
			ans = 1;
		}
		for(int rep = 0; rep < 2; rep++) {
			int l = 2, r = n - 1;
			while(l != r) {
				int mid = (l + r + 1) / 2;
				bool flag = hull[mid - 1].dir(vec, hull[mid]) == dir_flag;
				if(rep == 0) { flag = flag && (hull[0].dir(vec, hull[mid]) == dir_flag); }
				else { flag = flag || (hull[0].dir(vec, hull[mid - 1]) != dir_flag); }
				if(flag) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			if(hull[ans].dir(vec, hull[l]) == dir_flag) {
				ans = l;
			}
		}
	}
	return ans;
}

ll area[N];
point p[N];
//avoid using long double for comparisons, change type and remove division by 2
void ComputeSignedArea(const vector<point> &hull) {
    int n = (int)hull.size();
    for(int i = 0; i < n; i++){
        p[i] = p[i + n] = hull[i];
    }
    for(int i = 0; i < 2*n - 1; i++) {
        int j = (i+1);
        area[j] = area[i];
        area[j] += p[i].x*p[j].y - p[j].x*p[i].y;
    }
}

int n, k; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector <point> hull, pts, tmp;
    for(int i = 0; i < n; i++){
        point p;
        cin >> p.x >> p.y;
        if(i < k) hull.pb(p);
        else pts.pb(p);
    }
    ConvexHull(hull);
    sort_lex_hull(hull);
    for(int i = 0; i < pts.size(); i++){
        if(!pointInConvexPolygon(hull, pts[i])) tmp.push_back(pts[i]);
    }
    pts.clear();
    pts = tmp;
    
    ComputeSignedArea(hull);
    ll cur_area = abs(area[(int)hull.size()]);
    ll ans = cur_area;
    n = (int)hull.size();

    for(int i = 0; i < pts.size(); i++){
        int l, r;
        r = tangent(hull, pts[i], -1);
        l = tangent(hull, pts[i], 1);
        if(r < l) r += n;
        ll dif_area = abs((area[r] - area[l] + p[r].x*p[l].y - p[l].x*p[r].y));
        ll tot = cur_area + abs(area2(pts[i], p[l], p[r])) - abs(dif_area);
        ans = max(ans, tot);
    }
    cout << ans/2;
    if(ans%2) cout << ".5";
    else cout << ".0";
    cout << "\n";

    return 0;
}