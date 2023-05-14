#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl;
#define dbs(x) cerr << x << endl;
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 2e5 + 5;

typedef long long type;

bool ge(type x, type y){return x >= y;}
bool le(type x, type y){return x <= y;}

struct point{
    type x, y;
    point() : x(0), y(0){}
    point(type x, type y) : x(x), y(y){}

    point operator -(){return point(-x, -y);}
    point operator +(point p){return point(x + p.x, y + p.y);}
    point operator -(point p){return point(x - p.x, y - p.y);}

    type operator %(point p){return x*p.y - y*p.x;}

    bool operator ==(const point &p) const{return x == p.x and y == p.y;}
    bool operator !=(const point &p) const{return x != p.x or y != p.y;}
    bool operator <(const point &p) const{return (x < p.x) or (x == p.x and y < p.y);}

    int dir(point o, point p){
        type x = (*this - o) % (p - o);
        return ge(x, 0) - le(x, 0);
    }

    bool on_seg(point p, point q){
        if(this -> dir(p, q)) return 0;
        return(ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y)));
    }
};

type cross(point p, point q){return p.x*q.y - p.y*q.x;}

type area_2(point a, point b, point c){return cross(a, b) + cross(b, c) + cross(c, a);}

#define REMOVE_REDUNDANT
#ifdef REMOVE_REDUNDANT
bool between(const point &a, const point &b, const point &c){
    return (abs(area_2(a, b, c)) == 0 and (a.x - b.x)*(c.x - b.x) <= 0 and (a.y - b.y)*(c.y - b.y) <=0);
}
#endif

void monotone_hull(vector<point> &pts){
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> up, dn;
    for(int i = 0; i < pts.size(); i++){
        while(up.size() > 1 && area_2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while(dn.size() > 1 && area_2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for(int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

    #ifdef REMOVE_REDUNDANT
    if(pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for(int i = 2; i < pts.size(); i++){
        if(between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if(dn.size() >= 3 && between(dn.back(), dn[0], dn[1])){
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
    #endif
}

bool point_in_triangle(point a, point b, point c, point cur){
    ll s1 = 1ull * abs(cross(b - a, c - a));
    ll s2 = 1ull * abs(cross(a - cur, b - cur)) + 1ull * abs(cross(b - cur, c - cur)) + 1ull * abs(cross(c - cur, a - cur));
    return s1 == s2;
}

bool on_hull(point pt, vector<point> &pts){
    int n = pts.size();
    for(int i = 0; i < n; i++) {
        if(pts[i] == pt or pts[(i + 1) % n] == pt) return true;
        if(pt.on_seg(pts[i], pts[(i + 1) % n])) return true;
    } 
    return false;
}

bool point_in_convex_polygon(vector<point>& hull, point cur){
    int n = hull.size();
    if(cur.dir(hull[0], hull[1]) != 0 and cur.dir(hull[0], hull[1]) != hull[n - 1].dir(hull[0], hull[1]))
        return false;
    if(cur.dir(hull[0], hull[n - 1]) != 0 and cur.dir(hull[0], hull[n - 1]) != hull[1].dir(hull[0], hull[n - 1]))
        return false;

    int l = 1, r = n - 1;
    while(r - l > 1){
        int mid = (l + r)/2;
        if(cur.dir(hull[0], hull[mid]) <= 0) l = mid;
        else r = mid;
    }
    return point_in_triangle(hull[l], hull[l + 1], hull[0], cur);
}

int t, n, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> q;
        set<point> pts;
        vector<vector<point>> hull;
        for(int i = 0; i < n; i++){
            point p;
            cin >> p.x >> p.y;
            pts.insert(p);
        }
        while(pts.size() > 2){
            vector<point> rem, tmp;
            for(auto p : pts) tmp.push_back(p);
            hull.push_back(tmp);
            monotone_hull(hull[hull.size() - 1]);
            // db(hull.back().size());
            for(auto pt : pts){
                if(on_hull(pt, hull.back())) rem.push_back(pt);
            }
            for(auto p : rem) pts.erase(p);
        }
        for(int i = 0; i < q; i++){
            point p;
            cin >> p.x >> p.y;
            int cnt = 0;
            for(auto& h : hull){
                if(h.size() > 2){
                    if(point_in_convex_polygon(h, p) and !on_hull(p, h)){
                        cnt++;
                    }
                }
                else break;
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}