/*
    Minkowski Sum from (P, -Q)
    Dist from (0, 0) to polygon will be the distance from one polygon touching the other one
*/

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

typedef long long type;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }

struct point{
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y);}
    point operator -(point p) { return point(x - p.x, y - p.y);}

    point operator *(type k) { return point(x*k, y*k); }
    point operator /(type k) { return point(x/k, y/k); }

    type operator %(point p){ return x*p.y - y*p.x; }

    bool operator ==(const point& p) const{ return x == p.x and y == p.y;}
    bool operator !=(const point& p) const{ return x != p.x or y != p.y;}
    bool operator <(const point& p) const{ return (x < p.x) or (x == p.x and y < p.y);}

    int dir(point o, point p){
        type d = (*this - o) % (p - o);
        return (d >= 0) - (d <= 0);
    }

    type abs2(){ return x*x + y*y; }
    type dist2(point q){ return (*this - q).abs2();}
};

ostream& operator <<(ostream &os, const point& p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

type dot(point p, point q) { return p.x * q.x + p.y * q.y; }
type cross(point p, point q) { return p.x * q.y - p.y * q.x; }

type compute_signed_area(const vector<point> &p){
    type area = 0;
    for(int i = 0; i < p.size(); i++){
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area;
}

void sort_lex_hull(vector<point> &hull){
    if(compute_signed_area(hull) < 0) reverse(hull.begin(), hull.end());
    int n = hull.size();

    int pos = 0;
    for(int i = 1; i < n; i++) if(hull[i] < hull[pos]) pos = i;
    rotate(hull.begin(), hull.begin() + pos, hull.end());
}

typedef vector<point> polygon;

polygon minkowski(polygon& A, polygon& B){
    polygon P;
    point v1, v2;
    sort_lex_hull(A), sort_lex_hull(B);
    int n1 = A.size(), n2 = B.size();
    P.push_back(A[0] + B[0]);
    for(int i = 0, j = 0; i < n1 or j < n2;){
        v1 = A[(i + 1) % n1] - A[i % n1];
        v2 = B[(j + 1) % n2] - B[j % n2];
        if(j == n2 or cross(v1, v2) > EPS){
            P.push_back(P.back() + v1);
            i++;
        }
        else if(i == n1 or cross(v1, v2) < -EPS){
            P.push_back(P.back() + v2);
            j++;
        }
        else{
            P.push_back(P.back() + (v1 + v2));
            i++; j++;
        }
    }
    P.pop_back();
    sort_lex_hull(P);
    return P;
}

bool point_in_triangle(point a, point b, point c, point cur){
    ll s1 = abs(cross(b - a, c - a));
    ll s2 = abs(cross(a - cur, b - cur)) + abs(cross(b - cur, c - cur)) + abs(cross(c - cur, a - cur));
    return s1 == s2;
}

//determine if point is inside or on the boundary of a polygon (O(logn))
bool point_in_convex_polygon(vector<point> &hull, point cur){
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
    return point_in_triangle(hull[l], hull[l + 1], hull[0], cur);
}

ld distance_point_line(point c, point a, point b){
    ll r = dot(b - a, b - a);
    if(abs(r) <= 0){
        return sqrt(c.dist2(a));
    }
    ld xx = (a.x + (ld)(b.x - a.x) * dot(c - a, b - a) / (ld)dot(b - a, b - a));
    ld yy = (a.y + (ld)(b.y - a.y) * dot(c - a, b - a) / (ld)dot(b - a, b - a));
    return sqrt((c.x - xx) * (c.x - xx) + (c.y - yy) * (c.y - yy));
}

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    polygon p(n), q(m), mink;
    for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    for(int i = 0; i < m; i++){
        cin >> q[i].x >> q[i].y;
        q[i].x *= -1, q[i].y *= -1;
    }
    mink = minkowski(p, q);
    cout << setprecision(15) << fixed;
    if(!point_in_convex_polygon(mink, {0, 0})) cout << (ld)0 << "\n";
    else{
        ld ans = LINF;
        for(int i = 0; i < mink.size(); i++){
            ld tmp = distance_point_line({0, 0}, mink[i], mink[(i + 1) % mink.size()]);
            if(le(tmp, ans)) ans = tmp;
        }
        ans -= 60;
        if(le(ans, 0)) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}