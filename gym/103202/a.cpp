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

struct long_point {
    ll x, y;

    long_point() : x(0), y(0) {}
    long_point(ll _x, ll _y) : x(_x), y(_y) {}

    long_point operator -() { return long_point(-x, -y); }
    long_point operator +(long_point p) { return long_point(x + p.x, y + p.y); }
    long_point operator -(long_point p) { return long_point(x - p.x, y - p.y); }

    long_point operator *(ll k) { return long_point(k*x, k*y); }

    //inner product
    ll operator *(long_point p) { return x*p.x + y*p.y; }
    //cross product
    ll operator %(long_point p) { return x*p.y - y*p.x; }

    bool operator ==(const long_point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const long_point &p) const{ return x != p.x  or y != p.y; }
    bool operator  <(const long_point &p) const{ return (x < p.x) or (x == p.x and y < p.y); }

    // 0 => same direction
    // 1 => p is on the left 
    //-1 => p is on the right    
    int dir(long_point o, long_point p) {
        ll x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }

    bool on_seg(long_point p, long_point q) {
        if (this->dir(p, q)) return 0;
        return x >= min(p.x, q.x) and x <= max(p.x, q.x) and y >= min(p.y, q.y) and y <= max(p.y, q.y);
    }
};

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}
    point(long_point p) : x(p.x), y(p.y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(k*x, k*y); }
    point operator /(type k) { return point(x/k, y/k); }

    //inner product
    type operator *(point p) { return x*p.x + y*p.y; }
    //cross product
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x  or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }
};

long_point rotate_ccw90(long_point p)   { return long_point(-p.y,p.x); }
long_point rotate_cw90(long_point p)    { return long_point(p.y,-p.x); }

ostream &operator<<(ostream &os, const long_point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}


typedef vector<point> polygon;

int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

bool comp(point a, point b){
    if((cmp(a.x) > 0 || (cmp(a.x) == 0 && cmp(a.y) > 0) ) && (cmp(b.x) < 0 || (cmp(b.x) == 0 && cmp(b.y < 0)))) return 1;
    if((cmp(b.x) > 0 || (cmp(b.x) == 0 && cmp(b.y) > 0) ) && (cmp(a.x) < 0 || (cmp(a.x) == 0 && cmp(a.y < 0)))) return 0;
    ld R = a % b;
    if(R) return R > 0;
    return false;
}

//outside: sort clockwise
//inside: sort counter clockwise

namespace halfplane{
  struct L{
    point p,v;
    L(){}
    L(point P, point V):p(P),v(V){}
    bool operator<(const L &b)const{ return comp(v, b.v); }
  };
  vector<L> line;
  void addL(point a, point b){line.pb(L(a, b - a));}
  bool left(point &p, L &l){ return cmp(l.v % (p - l.p)) > 0; }
  bool left_equal(point &p, L &l){ return cmp(l.v % (p - l.p)) >= 0; }
  void init(){ line.clear(); }

    point pos(L &a, L &b){
        point x = a.p - b.p;
        ld t = (b.v % x)/(a.v % b.v);
        return a.p + a.v*t;
    }

    polygon intersect(){
    sort(line.begin(), line.end());
    deque<L> q; //linhas da intersecao
    deque<point> p; //pontos de intersecao entre elas
    q.push_back(line[0]);
    for(int i=1; i < (int) line.size(); i++){
        while(q.size() > 1 && !left(p.back(), line[i]))
            q.pop_back(), p.pop_back();
        while(q.size() > 1 && !left(p.front(), line[i]))
            q.pop_front(), p.pop_front();
        if(!cmp(q.back().v % line[i].v) && !left(q.back().p,line[i]))
            q.back() = line[i];
        else if(cmp(q.back().v % line[i].v))
            q.push_back(line[i]), p.push_back(point());
        if(q.size() > 1)
            p.back()=pos(q.back(),q[q.size()-2]);
    }
    while(q.size() > 1 && !left(p.back(),q.front()))
      q.pop_back(), p.pop_back();
    if(q.size() <= 2) return polygon(); //Nao forma poligono (pode nao ter intersecao)
    if(!cmp(q.back().v % q.front().v)) return polygon(); //Lados paralelos -> area infinita
    point ult = pos(q.back(),q.front());

    bool ok = 1;
    for(int i = 0; i < (int) line.size(); i++)
        if(!left_equal(ult,line[i])){ ok=0; break; }

    if(ok) p.push_back(ult); //Se formar um poligono fechado
    polygon ret;
    for(int i = 0; i < (int) p.size(); i++)
        ret.pb(p[i]);
    return ret;
  }
}

ld compute_signed_area(const polygon &p) {
    ld area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

ld compute_area(const polygon &p) {
    return fabs(compute_signed_area(p));
}

ld calc(pair<long_point, long_point> l1, pair<long_point, long_point> l2){
    ld ans;
    if(l1.nd < l1.st) swap(l1.st, l1.nd);
    if(l2.nd < l2.st) swap(l2.st, l2.nd);
    if(l2.st < l1.st) swap(l1, l2);
    
    //one segment above the other
    if(!l2.st.dir(l1.st, l1.nd) and !l2.nd.dir(l1.st, l1.nd)){
        long_point l, r;
        l = max(l1.st, l2.st), r = min(l1.nd, l2.nd);
        if(r < l or r == l){
            return 0.0;
        }
        long_point u = (r - l);
        if(l1.st != l2.st){
            halfplane::line.push_back({l, rotate_cw90(u)});
        }
        if(l1.nd != l2.nd){
            halfplane::line.push_back({r, rotate_ccw90(u)});
        }
        ans = compute_area(halfplane::intersect());
        return ans;
    }
    
    //l2.st may be the "pivot"
    if(l2.st.on_seg(l1.st, l1.nd)){
        vector<long_point> tmp;
        if(l2.st == l1.st){
            tmp.push_back(l2.nd);
            tmp.push_back(l2.st);
            tmp.push_back(l1.nd);
            long_point u = (tmp[1] - tmp[2]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            u = (tmp[1] - tmp[0]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            ans = compute_area(halfplane::intersect());
            return ans;
        }
        else if(l2.st == l1.nd){
            tmp.push_back(l2.nd);
            tmp.push_back(l2.st);
            tmp.push_back(l1.st);
            long_point u = (tmp[1] - tmp[2]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            u = (tmp[1] - tmp[0]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            ans = compute_area(halfplane::intersect());
            return ans;
        }
        return 0.0;
    }
    //l2.nd may be the "pivot"
    else if(l2.nd.on_seg(l1.st, l1.nd)){
        vector<long_point> tmp;
        if(l2.nd == l1.st){
            tmp.push_back(l2.st);
            tmp.push_back(l2.nd);
            tmp.push_back(l1.nd);
            long_point u = (tmp[1] - tmp[2]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            u = (tmp[1] - tmp[0]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            ans = compute_area(halfplane::intersect());
            return ans;
        }
        else if(l2.nd == l1.nd){
            tmp.push_back(l2.st);
            tmp.push_back(l2.nd);
            tmp.push_back(l1.st);
            long_point u = (tmp[1] - tmp[2]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});
            u = (tmp[1] - tmp[0]);
            halfplane::line.push_back({tmp[1], rotate_cw90(u)});

            ans = compute_area(halfplane::intersect());
            return ans;
        }
        return 0.0;
    }
    return 0.0;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        halfplane::init();
        cout << setprecision(15) << fixed;
        long_point bl, tr;
        cin >> bl.x >> bl.y >> tr.x >> tr.y;
        halfplane::addL(bl, {tr.x, bl.y});
        halfplane::addL({tr.x, bl.y}, tr);
        halfplane::addL(tr, {bl.x, tr.y});
        halfplane::addL({bl.x, tr.y}, bl);

        pair<long_point, long_point> l1, l2;
        cin >> l1.st.x >> l1.st.y >> l1.nd.x >> l1.nd.y;
        cin >> l2.st.x >> l2.st.y >> l2.nd.x >> l2.nd.y;
        cout << calc(l1, l2) << "\n";
    }
    return 0;
}