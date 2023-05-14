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
    point() : x(0), y(0){}
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
type dot(point p, point q){return p.x*q.x + p.y*q.y;}


ll area2(point a, point b, point c){
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

point a, b;

bool cmp2(point p, point q){
    ll p_abs = dot((p - a), (b - a));
    ll q_abs = dot((q - a), (b - a));
    return p_abs < q_abs;
}

int direction(point o, point p, point q){return p.dir(o, q);}

int n;
int cnt = 0;
ll s;
point pts[N];

int search_triangle(int l, int r, int pl, int pr, ll area){
    if(l == r) return l;
    while(l < r){
        int mid = (l + r)/2;
        ll cur = area2(pts[pl], pts[pr], pts[mid]);
        if(area + cur >= 2*s) r = mid;
        else l = mid + 1;
    }
    return l;
}

int search_left(point p, vector<point> tmp_pts){
    int l = 0, r = (int)tmp_pts.size() - 1;
    while(l < r){
        int mid = (l + r)/2;
        if(direction(p, a, tmp_pts[mid]) == 1) l = mid + 1;
        else r = mid;
    }
    if(direction(p, a, tmp_pts[l]) == 1) l++;
    return l;
}

int search_right(point p, vector<point> tmp_pts){
    int l = 0, r = (int)tmp_pts.size() - 1;
    while(l < r){
        int mid = (l + r + 1)/2;
        if(direction(p, b, tmp_pts[mid]) == -1) r = mid - 1;
        else l = mid;
    }
    if(direction(p, b, tmp_pts[l]) == -1) l--;
    return l;
}

int main(){
    ll ans = 0;
    scanf("%lld%d", &s, &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &pts[i].x, &pts[i].y);
    }
    map<point, int> id;
    sort(pts, pts + n);
    for(int i = 0; i < n; i++){
        point p = pts[i];
        id[p] = i;
    }
    vector<pair<point, point>> edges;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            edges.push_back({pts[i], pts[j]});
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    ll dif = 0;
    for(auto e : edges){
        int l = id[e.st], r = id[e.nd];
        if(l > r){
            swap(l, r);
            for(int lft = 0; lft < l; lft++){
                ll area_below = area2(pts[l], pts[r], pts[lft]);
                int idx = search_triangle(r + 1, n, l, r, area_below);
                ans += (n - idx);
                if(idx != n){
                    vector<point> tmp_pts;                
                    a = pts[l], b = pts[r];
                    for(int i = idx; i < n; i++) tmp_pts.push_back(pts[i]);
                    sort(tmp_pts.begin(), tmp_pts.end(), cmp2);
                    int idx_right = search_left(pts[lft], tmp_pts);
                    int idx_left = search_right(pts[lft], tmp_pts);
                    if(idx_right < idx_left) continue;
                    dif += (idx_right - idx_left + 1);
                }
            }
        }
        else{
            for(int lft = 0; lft < l; lft++){
                ll area_below = area2(pts[l], pts[r], pts[lft]);
                int idx = search_triangle(r + 1, n, l, r, area_below);
                ans += (n - idx);
                if(idx != n){
                    vector<point> tmp_pts;                
                    a = pts[l], b = pts[r];
                    for(int i = idx; i < n; i++) tmp_pts.push_back(pts[i]);
                    sort(tmp_pts.begin(), tmp_pts.end(), cmp2);
                    int idx_left = search_left(pts[lft], tmp_pts);
                    int idx_right = search_right(pts[lft], tmp_pts);
                    if(idx_right < idx_left) continue;
                    dif += (idx_right - idx_left + 1);
                }
            }
        }
        swap(pts[l], pts[r]);
        swap(id[e.nd], id[e.st]);
    }
    printf("%lld\n", ans - dif/2);
    return 0;
}