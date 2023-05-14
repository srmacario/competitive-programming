#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-5, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 5e5 + 5;

typedef long double type;

bool ge(type x, type y){ return x + EPS > y; }
bool le(type x, type y){ return x - EPS < y; }
bool eq(type x, type y){ return ge(x, y) and le(x, y); }
int sign(type x) { return ge(x, 0) - le(x, 0); }

struct point{
    type x, y;
    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -(){ return point(-x, -y); }
    point operator +(point p){ return point(x + p.x, y + p.y);}
    point operator -(point p){ return point(x - p.x, y - p.y);}

    point operator *(type k){ return point(k*x, k*y); }
    point operator /(type k){ return point(x/k, y/k); }

    type operator * (point p){ return x*p.x + y*p.y; }
    type operator % (point p){ return x*p.y - y*p.x; }

    int dir(point o, point p){
        type x = (*this - o) % (p - o);
        return ge(x, 0) - le(x, 0);
    }

};

ostream &operator<<(ostream &os, const point &p){
    os << "(" << p.x << ", " << p.y << ") ";
    return os;
}

type compute_signed_area(const vector<point> &p){
    type area = 0;
    for(int i = 0; i < p.size(); i++){
        int j = (i + 1) % p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area;
}

ld compute_area(const vector<point> &p){
    return fabs(compute_signed_area(p) / 2.0);
}

typedef vector<point> polygon;

int cmp(ld x, ld y = 0, ld tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

bool comp(point a, point b){
    if ( (cmp(a.x) > 0 || (cmp(a.x) == 0 and cmp(a.y) > 0)) and (cmp(b.x) < 0 || (cmp(b.x) == 0 and cmp(b.y) < 0))) return 1;
    if ( (cmp(b.x) > 0 || (cmp(b.x) == 0 and cmp(b.y) > 0)) and (cmp(a.x) < 0 || (cmp(a.x) == 0 and cmp(a.y) < 0))) return 0;
    ld R = a % b;
    if(le(R, 0.0)) return false;
    return true;
}

namespace halfplane{
    struct L{
        point p, v;
        L(){}
        L(point P, point V) : p(P), v(V){}
        bool operator<(const L &b)const{ return comp(v, b.v); }
    };
    vector<L> line;
    void addL(point a, point b){ line.push_back(L(a, b - a)); }
    bool left(point &p, L &l){ return cmp(l.v % (p - l.p)) > 0;}
    bool left_equal(point &p, L &l){ return cmp(l.v % (p - l.p)) >= 0;}
    void init(){ line.clear(); }

    point pos(L &a, L &b){
        point x = a.p - b.p;
        ld t = (b.v % x) / (a.v % b.v);
        return a.p + a.v * t;
    }

    polygon intersect(){
        sort(line.begin(), line.end());
        deque<L> q;
        deque<point> p;
        q.push_back(line[0]);
        for(int i = 1; i < (int) line.size(); i++){
            while(q.size() > 1 and !left(p.back(), line[i]))
                q.pop_back(), p.pop_back();
            while(q.size() > 1 and !left(p.front(), line[i]))
                q.pop_front(), p.pop_front();
            if(!cmp(q.back().v % line[i].v) and !left(q.back().p, line[i]))
                q.back() = line[i];
            else if(cmp(q.back().v % line[i].v))
                q.push_back(line[i]), p.push_back(point());
            if(q.size() > 1)
                p.back() = pos(q.back(), q[q.size() - 2]);
        }
        while(q.size() > 1 and !left(p.back(), q.front()))
            q.pop_back(), p.pop_back();
        if(q.size() <= 2) return polygon();
        if(!cmp(q.back().v % q.front().v)) return polygon();
        point ult = pos(q.back(), q.front());

        bool ok = 1;
        for(int i = 0; i < (int) line.size(); i++)
            if(!left_equal(ult, line[i])){ ok = 0; break;}
        if(ok) p.push_back(ult);
        polygon ret;
        for(int i = 0; i < (int) p.size(); i++)
            ret.push_back(p[i]);
        return ret;
    }
}

int n;
vector<point> pts;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    pts.resize(n);
    halfplane::init();
    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    for(int i = 0; i < n; i++){
        //halfplane::addL(pts[(i + 1) % n], pts[i]);
        halfplane::addL(pts[i], pts[(i - 1 + n) % n]);
    }
    polygon poly = halfplane::intersect();
    cout << setprecision(15) << fixed << compute_area(poly) << "\n";
    return 0;
}