#include<bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second

#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x << " == " << x << endl
    #define dbs(x) cerr << x << endl
    #define _ << ", " <<
#else
    #define db(x) ((void)0)
    #define dbs(x) ((void)0)
#endif

using ll = long long;
using ld = long double;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

typedef long long type;

struct point{
    type x, y;
    int id;
    point() : x(0), y(0), id(-1){}
    point(type x, type y) : x(x), y(y){}

    point operator -(){return point(-x, -y);}
    point operator +(point p){return point(x + p.x, y + p.y);}
    point operator -(point p){return point(x - p.x, y - p.y);}

    point operator *(type k){return point(k*x, k*y);}
    point operator /(type k){return point(x/k, y/k);}

    type operator %(point p){return x * p.y - y * p.x;};

    bool on_seg(point p, point q){
        if(this -> dir(p, q)) return false;
        return (x >= min(p.x, q.x) and (x <= max(p.x, q.x)) and (y >= min(p.y, q.y)) and (y <= max(p.y, q.y)));
    }

    type abs2(){return x * x + y * y;}
    type dist2(point p){return (*this - p).abs2();}

    bool operator == (const point &p) const{return x == p.x and y == p.y;}
    bool operator != (const point &p) const{return x != p.x or y != p.y;}
    bool operator < (const point &p) const{return (x < p.x or (x == p.x and y < p.y));}

    int dir(point o, point p){
        type x = (*this - o) % (p- o);
        return (x >= 0) - (x <= 0);
    }

};

point rotate_CW90(point p){return point(p.y, -p.x);}

type cross(point p, point q){return p.x*q.y - p.y*q.x;}

type area2(point a, point b, point c){
    return abs(cross(a, b) + cross(b, c) + cross(c, a));
}

ostream &operator << (ostream &os, const point &p){
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

point origin;

int above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(pair<point, point> a, pair<point, point> b){
    point p = rotate_CW90(a.nd - a.st);
    point q = rotate_CW90(b.nd - b.st);
    
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin, q) > 0;
}

int direction(point o, point p, point q){return p.dir(o, q);}

bool segment_segment_intersect(point a, point b, point c, point d){
    if(a.dist2(c) == 0 || a.dist2(d) == 0 ||
       b.dist2(c) == 0 || b.dist2(d) == 0) return true;
    int d1, d2, d3, d4;
    d1 = direction(a, b, c);
    d2 = direction(a, b, d);
    d3 = direction(c, d, a);
    d4 = direction(c, d, b);
    if(d1*d2 < 0 and d3*d4 < 0) return true;
    return a.on_seg(c, d) or b.on_seg(c, d) or c.on_seg(a, b) or d.on_seg(a, b);
}

int n;
ll s;
point pts[N];
pair<point, point> edges[N];

int main(){
    ll ans = 0;
    scanf("%lld%d", &s, &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
        pts[i].id = i;
    }
    map<int, int> id;
    sort(pts, pts + n);
    for(int i = 0; i < n; i++){
        point p = pts[i];
        id[p.id] = i;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            edges[cnt++] = {pts[i], pts[j]};
        }
    }
    sort(edges, edges + cnt, cmp);
    ll dif = 0;
    for(int i = 0; i < cnt; i++){
        pair<point, point> e = edges[i];
        int l = id[e.st.id], r = id[e.nd.id];
        bool ok = true;
        for(int lft = 0; lft < l; lft++){
            for(int rgt = n - 1; rgt > r; rgt--){
                ll area_above = area2(pts[l], pts[r], pts[rgt]);
                ll area_below = area2(pts[l], pts[r], pts[lft]);
                if(area_above + area_below >= 2 * s){
                    if(segment_segment_intersect(pts[l], pts[r], pts[lft], pts[rgt])) dif++;
                    ans++;
                }
                else{
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        swap(pts[l], pts[r]);
        swap(id[e.nd.id], id[e.st.id]);
    }
    printf("%lld\n", ans - dif/2);
    return 0;
}