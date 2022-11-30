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

struct point{
    type x, y;

    point() : x(0), y(0){}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p){ return point(x + p.x, y + p.y);}
    point operator -(point p){ return point(x - p.x, y - p.y);}

    point operator *(type k) { return point(k*x, k*y); }
    point operator /(type k) { return point(x/k, y/k); } 

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x or y != p.y; }
    bool operator <(const point &p) const{ return (x < p.x) or (x == p.x and y < p.y); }

    type operator %(point p) { return x*p.y - y*p.x; }

    // 0 => same direction
    // 1 => p is on the left 
    //-1 => p is on the right
    int dir(point o, point p){
        type _x = (*this - o) % (p - o);
        return (_x >= 0) - (_x <= 0);
    }

    bool on_seg(point p, point q){
        if(this->dir(p, q)) return 0;
        return (x >= (min(p.x, q.x))) and (y >= (min(p.y, q.y))) and (x <= (max(p.x, q.x))) and (y <= (max(p.y, q.y)));
    }
};

point rotate_cw90(point p) { return point(p.y, -p.x); }

ostream &operator<<(ostream &os, const point &p){
    os << "( " << p.x << ", " << p.y << ")";
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
    return p.dir(origin, q) > 0;
}

struct radial_point{
    point p;

    radial_point(point _p = {0, 0}) : p(_p) {}

    bool operator <(const radial_point &r) const{ 
        return cmp(this->p, r.p);
    }
};

vector<vector<radial_point>> col_edges;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        ll ans = 0;
        cin >> n;

        vector<pair<point, point>> edges;
        col_edges.clear();
        vector<point> pts;

        for(int i = 0; i < n; i++){
            point a, b;
            cin >> a.x >> a.y >> b.x >> b.y;
            edges.push_back({a, b});
            pts.push_back(a), pts.push_back(b);
        }

        //precalc radial
        sort(pts.begin(), pts.end());
        pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
        map<point, int> id_point;
        for(int i = 0; i < pts.size(); i++){
            point p = pts[i];
            id_point[p] = i;
            col_edges.push_back({});
            for(auto e : edges){
                if(p.on_seg(e.st, e.nd) and p != e.st and p != e.nd){
                    col_edges.back().push_back(radial_point(e.st));
                    col_edges.back().push_back(radial_point(e.nd));
                }
            }
            origin = p;
            sort(col_edges.back().begin(), col_edges.back().end());
        }

        //brute edges
        for(int i = 0; i < edges.size(); i++){
            for(int j = i + 1; j < edges.size(); j++){
                pair<point, point> a = edges[i], b = edges[j];
                origin = {-INF, -INF};
                point l = {-INF, -INF}, r = {-INF, -INF};
                //first, first
                if(a.st == b.st) origin = a.st, l = a.nd, r = b.nd;
                //first, second
                else if(a.st == b.nd) origin = a.st, l = a.nd, r = b.st;
                //second, first
                else if(a.nd == b.st) origin = a.nd, l = a.st, r = b.nd;
                //second, second
                else if(a.nd == b.nd) origin = a.nd, l = a.st, r = b.st;
                //no common point
                if(origin.x == -INF) continue;
                //check collinear
                if(!l.dir(origin, r)) continue;
                //point l must be on the left
                if(l.dir(origin, r) == 1) swap(l, r);
                //one above other below
                // db(origin _ l _ r);
                // db(col_edges[id_point[origin]].size() _ above(l) _ above(r));
                if(!above(l) and above(r)){
                    swap(l, r);
                    int sum_more = (col_edges[id_point[origin]].end() - lower_bound(col_edges[id_point[origin]].begin(), col_edges[id_point[origin]].end(), radial_point(l)));
                    int sum_less = (upper_bound(col_edges[id_point[origin]].begin(), col_edges[id_point[origin]].end(), radial_point(r)) - col_edges[id_point[origin]].begin());
                    // db(sum_more _ sum_less);
                    ans += col_edges[id_point[origin]].size() / 2 - (sum_more + sum_less);
                }
                else{
                    int sum_more = (col_edges[id_point[origin]].end() - upper_bound(col_edges[id_point[origin]].begin(), col_edges[id_point[origin]].end(), radial_point(l)));
                    int sum_less = (lower_bound(col_edges[id_point[origin]].begin(), col_edges[id_point[origin]].end(), radial_point(r)) - col_edges[id_point[origin]].begin());
                    int rest = col_edges[id_point[origin]].size() - (sum_more + sum_less);
                    ans += col_edges[id_point[origin]].size() / 2 - (rest);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}