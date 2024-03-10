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

    ld abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
    ld dist(point q) { return (*this - q).abs(); }
    type dist2(point q) { return (*this - q).abs2(); }
};

point rotate_ccw90(point p)   { return point(-p.y,p.x); }
point rotate_cw90(point p)    { return point(p.y,-p.x); }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

struct circle {
    point c;
    ld r;
    circle() { c = point(); r = 0; }
    circle(point _c, ld _r) : c(_c), r(_r) {}

    bool intersects(circle other) {
        return le(c.dist(other.c), r + other.r);
    }

    bool contains(point p) { return le(c.dist(p), r); }
};

vector<point> circle_circle_intersection(point a, point b, ld r, ld R) {
    vector<point> ret;
    ld d = sqrt(a.dist2(b));
    if (!le(d, r + R) || !ge(d + min(r, R), max(r, R))) return ret;
    ld x = (d * d - R * R + r * r)/(2 * d);
    ld y = sqrt(r*r - x*x);
    point v = (b - a)/d;
    ret.push_back(a + v*x + rotate_ccw90(v)*y);
    if (y > 0)
        ret.push_back(a + v*x - rotate_ccw90(v)*y);
    return ret;
}

circle circ[3];

bool check(ld radius){
    for(int i = 0; i < 3; i++) circ[i].r -= radius;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 3; j++){
            vector<point> inters = circle_circle_intersection(circ[i].c, circ[j].c, circ[i].r, circ[j].r);
            for(auto it : inters){
                if (circ[(3 - i - j)].contains(it)){
                    for(int i = 0; i < 3; i++) circ[i].r += radius;
                    return true;
                }
            }
        }
    }
    for(int i = 0; i < 3; i++) circ[i].r += radius;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> circ[0].r;

    cin >> circ[1].c.x >> circ[1].c.y;
    circ[1].r = circ[1].c.abs();

    cin >> circ[2].c.x >> circ[2].c.y;
    circ[2].r = circ[2].c.abs();

    ld l = 0, r = min({circ[0].r, circ[1].r, circ[2].r});
    while(r - l > EPS){
        ld mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(20) << fixed << l << "\n";
    return 0;
}
