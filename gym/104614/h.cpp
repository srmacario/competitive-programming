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

typedef long double type;

bool ge(type x, type y){ return x + EPS > y;}
bool le(type x, type y){ return x - EPS < y;}
bool eq(type x, type y){ return ge(x, y) and le(x, y);}

struct point{
    type x, y;

    point() : x(0), y(0) {}
    point (type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p){ return point(x + p.x, y + p.y);}
    point operator -(point p){ return point(x - p.x, y - p.y);}

    point operator *(type k){ return point(x*k, y*k); }
    point operator /(type k){ return point(x/k, y/k); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const { return x == p.x and y == p.y; }
    bool operator !=(const point &p) const { return x != p.x or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }

    int dir(point o, point p){
        type d = (*this - o) % (p - o);
        return ge(d, 0) - le(d, 0);
    }

    bool on_seg(point p, point q){
        if(this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs(){ return sqrt(x * x + y * y);}
    type abs2(){ return x * x + y * y ;}
    ld dist(point q){return (*this - q).abs();}
    type dist2(point q){return (*this - q).abs2();}
};

type dot(point a, point b){ return a * b;}
type cross(point a, point b){ return a % b;}

point project_point_line(point c, point a, point b){
    ld r = dot(b - a, b - a);
    if(fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    return a + (b - a)*r;
}

point project_point_ray(point c, point a, point b){
    ld r = dot(b - a, b - a);
    if(fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if(le(r, 0)) return a;
    return a + (b - a)*r;
}

point project_point_segment(point c, point a, point b){
    ld r = dot(b - a, b - a);
    if(fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if(le(r, 0)) return a;
    if(ge(r, 1)) return b;
    return a + (b - a)*r;
}

ld distance_point_ray(point c, point a, point b){
    return c.dist2(project_point_ray(c, a, b));
}

ld distance_point_segment(point c, point a, point b){
    return c.dist2(project_point_segment(c, a, b));
}

pair<bool, type> circle_segment_intersection(circle c, point a, point b){
    point proj = project_point_line(c.c, a, b);
    type d = LINF;
    if(proj.on_seg(a, b)) d = 0;
    d = min({d, proj.dist(a), proj.dist(b)});
    if(!le(d, c.r)){
        return {false, 0.0};
    }
    return {true, c.c.dist(proj) - sqrt(c.r * c.r - d * d)};
}

pair<bool, type> circle_ray_intersection(circle c, point a, point b){
    point proj = project_point_line(c.c, a, b);
    type d = LINF;
    if(!a.dir(proj, b)) d = 0;
    d = min(d, proj.dist(a));
    if(!le(d, c.r)){
        return {false, 0.0};
    }
    return {true, c.c.dist(proj) - sqrt(c.r * c.r - d * d)};
}

struct circle{
    point c;
    type r;
};

type v;
point pts[N];
point camera, d;
circle circ;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) cin >> pts[i].x >> pts[i].y;
    cin >> camera.x >> circ.c.x >> circ.c.y >> d.x >> d.y >> v;
    d = d / d.abs();
    int pos = 0;
    for(int i = 0; i <= n; i++){
        if(camera.x == pts[i].x){
            camera.y = pts[i].y;
            pos = i;
            break;
        }
        if(camera.x > pts[i].x and camera.x < pts[i + 1].x){
            camera.y = ((camera.x - pts[i].x) * pts[i].y + (pts[i + 1].x - camera.x) * pts[i + 1].y) / (pts[i + 1].x - pts[i].x);
            pos = i;
            break;
        }
    }
    ld ans = LINF;
    //left
    for(int i = pos; i >= 0; i--){
        if(camera.x == pts[i].x) continue;
        //ray: (camera, pts[i])
        bool is_ray = true;
        point inters;
        for(int j = i - 1; j >= 0; j--){
            //segment: (pts[j], pts[j + 1])
            if(segment_ray_intersection(pts[j], pts[j + 1], camera, pts[i])){
                inters = compute_line_intersection(pts[j], pts[j + 1], camera, pts[i]);
                is_ray = false;
                break;
            }
        }
        if(is_ray){
            if(ray_ray_intersection(camera, pts[i], circ.c, circ.c + d)){
                pair<bool, type> csinters = circle_ray_intersection(circ, camera, pts[i]);
                if(csinters.st == true){
                    type temp_dist = csinters.nd / (v * (sin(acos(dot(d, (pts[i] - camera)) / (pts[i] - camera).abs()))));
                    ans = min(ans, temp_dist);
                }
            }
        }
        else{
            if(segment_ray_intersection(camera, inters, circ.c, circ.c + d)){
                pair<bool, type> csinters = circle_segment_intersection(circ, camera, pts[i]);
                if(csinters.st == true){
                    type temp_dist = csinters.nd / (v * (sin(acos(dot(d, (pts[i] - camera)) / (pts[i] - camera).abs()))));
                    ans = min(ans, temp_dist);
                }
            }
        }
    }
    //right
    for(int i = pos + 1; i <= n; i++){

    }
    //circle / segment
    return 0;
}