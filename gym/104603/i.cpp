#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

typedef long double type;

bool ge(type x, type y) { return x + EPS > y;}
bool le(type x, type y) { return x - EPS < y;}
bool eq(type x, type y) { return ge(x, y) and le(x, y);}

struct point{
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -(){ return point(-x, -y);}
    point operator +(point p){ return point(x + p.x, y + p.y);}
    point operator -(point p){ return point(x - p.x, y - p.y);}

    point operator *(type k) { return point(x*k, y*k);}
    point operator /(type k) { return point(x/k, y/k);}

    type operator *(point p){ return x*p.x + y*p.y;}
    type operator %(point p){ return x*p.y - y*p.x;}

    bool operator ==(const point &p) const{ return x == p.x and y == p.y;}
    bool operator !=(const point &p) const{ return x != p.x or y != p.y;}
    bool operator <(const point &p) const{ return (x < p.x) or (x == p.x and y < p.y);}

    //0 => same direction
    //1 => p is on the left
    //-1 => p is on the right
    int dir(point o, point p){
        type d = (*this - o) % (p - o);
        return ge(d, 0) - le(d, 0);
    }

    bool on_seg(point p, point q){
        if(this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs(){return sqrt(x*x + y*y); }
    type abs2(){return (x*x + y*y); }
    ld dist(point q){return (*this - q).abs(); }
    type dist2(point q){return (*this - q).abs2(); }
};

point rotate_ccw90(point p){ return point(-p.y, p.x);}
point rotate_cw90(point p){ return point(p.y, -p.x);}

int direction(point o, point p, point q){ return p.dir(o, q);}

type dot(point p, point q) {return p.x * q.x + p.y * q.y;}
type cross(point p, point q) {return p.x * q.y - p.y * q.x;}

ostream &operator<<(ostream &os, const point &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

point project_point_segment(point c, point a, point b){
    ld r = dot(b - a, b - a);
    if(fabs(r) < EPS) return a;
    r = dot(c - a, b - a) / r;
    if(le(r, 0)) return a;
    if(ge(r, 1)) return b;
    return a + (b - a) * r;
}

ld distance_point_segment(point c, point a, point b){
    return c.dist2(project_point_segment(c, a, b));
}

bool segment_segment_intersect(point a, point b, point c, point d){
    if(a.dist2(c) < EPS || a.dist2(d) < EPS ||
       b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    int d1, d2, d3, d4;
    d1 = direction(a, b, c);
    d2 = direction(a, b, d);
    d3 = direction(c, d, a);
    d4 = direction(c, d, b);
    if(d1 * d2 < 0 and d3 * d4 < 0) return 1;
    return a.on_seg(c, d) or b.on_seg(c, d) or
           c.on_seg(a, b) or d.on_seg(a, b);
}

ld distance_segment_segment(point a, point b, point c, point d){
    if(segment_segment_intersect(a, b, c, d)) return 0;
    ld min1 = min(distance_point_segment(c, a, b), distance_point_segment(d, a, b));
    ld min2 = min(distance_point_segment(a, c, d), distance_point_segment(b, c, d));
    return min(min1, min2);
}

struct circle{
    point c;
    ld r;
};

struct figure{
    vector<point> pts;
};

ld distance_figure_figure(figure a, figure b){
    ld ans = LINF;
    for(int j = 0; j < a.pts.size(); j++){
        for(int i = 0; i < b.pts.size(); i++){
            ans = min(ans, distance_segment_segment(a.pts[j], a.pts[(j + 1) % a.pts.size()], b.pts[i], b.pts[(i + 1) % b.pts.size()]));
        }
    }
    return sqrt(ans);
}

ld distance_figure_circle(figure a, circle c){
    ld ans = LINF;
    for(int j = 0; j < a.pts.size(); j++){
        ans = min(ans, sqrt(distance_point_segment(c.c, a.pts[j], a.pts[(j + 1) % a.pts.size()])) - c.r);
    }
    return ans;
}


ld distance_circle_circle(circle c1, circle c2){
    return c1.c.dist(c2.c) - c1.r - c2.r;
}

int c, q, t;
circle circles[N];
figure triangles[N], rectangles[N];
//distance, posicao
//[1, c] -> [c + 1, c + q] -> [c + q + 1, c + q + t]
vector<pair<ld, int>> adj[N];
ld dist[N];

ld dijkstra(){
    for(int i = 0; i < N; i++) dist[i] = LINF;
    priority_queue<pair<ld, int>> pq;
    for(int s = c + 1; s <= c + q; s++){
        pq.push({0, s});
        dist[s] = 0;
    }
    while(!pq.empty()){
        int u = pq.top().nd;
        ld ud = -pq.top().st;
        pq.pop();
        if(dist[u] < ud) continue;
        for(auto v : adj[u]){
            ld uw = v.st;
            if(dist[v.nd] > uw + dist[u]){
                dist[v.nd] = uw + dist[u];
                pq.push({-dist[v.nd], v.nd});
            }
        }
    }
    ld ans = LINF;
    for(int i = c + q + 1; i <= c + q + t; i++){
        ans = min(ans, dist[i]);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> c >> q >> t;
    for(int i = 1; i <= c; i++){
        cin >> circles[i].c.x >> circles[i].c.y >> circles[i].r;
        for(int j = 1; j < i; j++){
            ld dist = distance_circle_circle(circles[i], circles[j]);
            adj[j].push_back({dist, i});
            adj[i].push_back({dist, j});
        }
    }
    for(int i = 1; i <= q; i++){
        vector<point> pts(4);
        cin >> pts[0].x >> pts[0].y;
        cin >> pts[2].x >> pts[2].y;
        point mid_point_vector = point((-pts[0].x + pts[2].x) / 2, (-pts[0].y + pts[2].y) / 2);
        point mid_point = point((pts[0].x + pts[2].x) / 2, (pts[0].y + pts[2].y) / 2);
        pts[1] = rotate_cw90(mid_point_vector) + mid_point;
        pts[3] = rotate_ccw90(mid_point_vector) + mid_point;
        rectangles[i].pts = pts;
        for(int j = 1; j <= c; j++){
            ld dist = distance_figure_circle(rectangles[i], circles[j]);
            adj[j].push_back({dist, c + i});
            adj[c + i].push_back({dist, j});
        }
    }
    for(int i = 1; i <= t; i++){
        vector<point> pts(3);
        for(int k = 0; k < 3; k++){
            cin >> pts[k].x >> pts[k].y;
        }
        triangles[i].pts = pts;
        for(int j = 1; j <= c; j++){
            ld dist = distance_figure_circle(triangles[i], circles[j]);
            adj[j].push_back({dist, c + q + i});
            adj[c + q + i].push_back({dist, j});
        }
        for(int j = 1; j <= q; j++){
            ld dist = distance_figure_figure(triangles[i], rectangles[j]);
            adj[c + j].push_back({dist, c + q + i});
            adj[c + q + i].push_back({dist, c + j});
        }
    }
    cout << setprecision(20) << fixed << dijkstra() << "\n";
    return 0;
}