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
    type x, y, z;

    point() : x(0), y(0), z(0) {}
    point(type _x, type _y, type _z) : x(_x), y(_y) , z(_z) {}

    point operator -() { return point(-x, -y, -z); }
    point operator +(point p) { return point(x + p.x, y + p.y, z + p.z); }
    point operator -(point p) { return point(x - p.x, y - p.y, z - p.z); }

    point operator *(type k) { return point(x*k, y*k, z*k); }
    point operator /(type k) { return point(x/k, y/k, z/k); }

    ld abs() { return sqrt(x*x + y*y + z*z); }
    type abs2() { return x*x + y*y + z*z; }
    ld dist(point q) { return (*this - q).abs(); }
    type dist2(point q) { return (*this - q).abs2(); }
};

struct circle{
    point center;
    ld radius;

    circle(point _center = {0, 0, 0}, ld _radius = {(ld)LINF}) : center(_center), radius(_radius) {}

    bool contains(point p){
        return le(p.dist(center), radius);
    }
};

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<point> pts(n);
    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y >> pts[i].z;

    circle bound;
    pair<ld, int> xmin, xmax, ymin, ymax, zmin, zmax;
    xmin = xmax = {pts[0].x, 0};
    ymin = ymax = {pts[0].y, 0};
    zmin = ymax = {pts[0].z, 0};
    for(int i = 1; i < n; i++){
        xmin = min(xmin, make_pair(pts[i].x, i));
        xmax = max(xmax, make_pair(pts[i].x, i));
        ymin = min(ymin, make_pair(pts[i].y, i));
        ymax = max(ymax, make_pair(pts[i].y, i));
        zmin = min(zmin, make_pair(pts[i].z, i));
        zmax = min(zmax, make_pair(pts[i].z, i));
    }
    point dx, dy, dz;
    dx = pts[xmax.nd] - pts[xmin.nd];
    dy = pts[ymax.nd] - pts[ymin.nd];
    dz = pts[zmax.nd] - pts[zmin.nd];
    if(dz.abs2() >= dy.abs2() and dz.abs2() >= dx.abs2()){
        bound.center = pts[zmin.nd] + dz / 2;
        bound.radius = (pts[zmax.nd] - bound.center).abs();
    }
    if(dy.abs2() >= dz.abs2() and dy.abs2() >= dx.abs2()){
        bound.center = pts[ymin.nd] + dy / 2;
        bound.radius = (pts[ymax.nd] - bound.center).abs();

    }
    if(dx.abs2() >= dz.abs2() and dx.abs2() >= dy.abs2()){
        bound.center = pts[xmin.nd] + dx / 2;
        bound.radius = (pts[xmax.nd] - bound.center).abs();
    }

    for(int i = 0; i < n; i++){
        if(bound.contains(pts[i])) continue;
        point dir = (pts[i] - bound.center) / (pts[i] - bound.center).abs();
        ld dist = (bound.radius + pts[i].dist(bound.center)) / 2;
        point new_center = bound.center + dir * ((pts[i] - bound.center).abs() - bound.radius);
        bound = circle(new_center, dist);
    }
    cout << setprecision(20) << fixed << bound.center.x << " " << bound.center.y << " " << bound.center.z << "\n";

    return 0;
}