
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
const int N = 5e5+5;

typedef long long type;
//for big coordinates change to long long

bool ge(type x, type y) { return x >= y; }
bool le(type x, type y) { return x <= y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

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

    // 0 => same direction
    // 1 => p is on the left 
    //-1 => p is on the right    
    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
    ld dist(point q) { return (*this - q).abs(); }
    type dist2(point q) { return (*this - q).abs2(); }

    ld arg() { return atan2l(y, x); }

    // Project point on vector y
    point project(point y) { return y * ((*this * y) / (y * y)); }

    // Project point on line generated by points x and y
    point project(point x, point y) { return x + (*this - x).project(y-x); }

    ld dist_line(point x, point y) { return dist(project(x, y)); }

    ld dist_seg(point x, point y) {
        return project(x, y).on_seg(x, y) ? dist_line(x, y) :  min(dist(x), dist(y));
    }

    point rotate(ld sin, ld cos) { return point(cos*x - sin*y, sin*x + cos*y); }
    point rotate(ld a) { return rotate(sin(a), cos(a)); }

    // rotate around the argument of vector p
    point rotate(point p) { return rotate(p.x / p.abs(), p.y / p.abs()); }

};

int direction(point o, point p, point q) { return p.dir(o, q); }

point RotateCCW90(point p)   { return point(-p.y,p.x); }
point RotateCW90(point p)    { return point(p.y,-p.x); }

//for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
type area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

bool LinesParallel(point a, point b, point c, point d) {
    return abs(cross(b - a, d - c)) == 0; 
}

bool LinesCollinear(point a, point b, point c, point d) {
    // Degenerate case
    //if((a == c and b == d) || (a == d and b == c)) return true;
  return LinesParallel(a, b, c, d)
      && abs(cross(a - b, a - c)) == 0
      && abs(cross(c - d, c - a)) == 0; 
}

bool upward_edge(point a, point b, point c, point d){
    //Line: a - b
    //Edge: c - d
    //Edge who comes from bottom to top (or from right to left), but does not consider the final endpoint
    return (direction(a, b, c) < 1 and direction(a, b, d) == 1);
    // db(direction(a, b, c) _ direction(a, b, d));
    // return (direction(a, b, c) * direction(a, b, d) <= 0);
}

bool downward_edge(point a, point b, point c, point d){
    //Line: a - b
    //Edge: c - d
    //Edge who comes from top to bottom (or from left to right), but does not consider the initial endpoint
    return (direction(a, b, c) == 1 and direction(a, b, d) < 1);
    // return (direction(a, b, c) * direction(a, b, d) <= 0);
}

type st[4*N][2], lazy[4*N][2];

void push (int p, int id, int l, int r) {
    if (lazy[p][id] != -1) {
        st[p][id] = 1ll * (r - l + 1) * lazy[p][id];
        if (l != r) {
            lazy[2*p][id] = lazy[p][id];
            lazy[2*p + 1][id] = lazy[p][id];
        }
        lazy[p][id] = -1;
    }
}

type query (int p, int id, int l, int r, int i, int j) {
    push(p, id, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p][id];
    type x = query(2*p, id, l, (l+r)/2, i, j);
    type y = query(2*p + 1, id, (l+r)/2 + 1, r, i, j);
    return x + y;
}

void update (int p, int id, int l, int r, int i, int j, int k) {
    push(p, id, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p][id] = k;
        push(p, id, l, r);
        return;
    }
    update(2*p, id, l, (l+r)/2, i, j, k);
    update(2*p + 1, id, (l+r)/2 + 1, r, i, j, k);
    if (l != r) st[p][id] = st[2*p][id] + st[2*p + 1][id];
}

ll n, w, h;
vector <point> pts;
vector<pii> last, cur;

type busca_upper(pair<point, point> p, type y){
    type l = 0, r = w;
    while(l < r){
        type m = (l + r)/2;
        point mp = {m, y};
        if(p.nd.dir(p.st, mp) <= 0) r = m;
        else l = m + 1;
    }
    return l;
}

type busca_lower(pair<point, point> p, type y){
    type l = 0, r = w;
    while(l < r){
        type m = (l + r + 1)/2;
        point mp = {m, y};
        if(p.nd.dir(p.st, mp) >= 0) l = m;
        else r = m - 1;
    }
    return l;
}

type calc(int i){
    //cur == 1, last == 0
    //declare
    // db(i);
    long long ans = 0;
    vector<pair<point, point>> inters;
    vector<pair<pair<point, point>, int>> sweep;
    vector<pii> add, novo;

    //build current line from last line
    for(auto s : last) cur.push_back(s);

    //See for each edge if it intercepts:

    pair<point, point> line = {{-1, i}, {N - 1, i}};
    for(int j = 0; j < n; j++){
        //Check upward and downward for info
        //upward and downward disconsider "horizontal" edges
        if(upward_edge(line.st, line.nd, pts[j], pts[(j + 1)%n]) || downward_edge(line.st, line.nd, pts[j], pts[(j + 1)%n])){
            point a = pts[j];
            point b = pts[(j + 1) % n];
            // db(line.st _ line.nd _ a _ b);
            if(b < a) swap(a, b);
            inters.push_back({a, b});
        }
        // if not upward or downward check if it is a collinear edge
        else if(LinesCollinear(line.st, line.nd, pts[j], pts[(j + 1)%n])){
            type a = pts[j].x;
            type b = pts[(j + 1)%n].x;
            if(b < a) swap(a, b);
            b--;
            if(b >= a) add.push_back({a, b});
        }
    }

    //Add interceptions to the sweep:
    //even: line enters the polygon
    //odd:  line leaves the polygon
    sort(inters.begin(), inters.end());
    int mult = -1;
    for(int j = 0; j < inters.size(); j++){
        sweep.push_back({inters[j], mult});
        mult *= -1;
    }
    // cout << "\n";
    sort(sweep.begin(), sweep.end());

    int open = 0;
    type ini;
    for(int j = 0; j < sweep.size(); j++){
        pair <pair<point, point>, int> p = sweep[j];
        if(p.st.nd.y < p.st.st.y) swap(p.st.nd, p.st.st);
        db(p.st.st _ p.st.nd);
        //-1: enters the polygon
        if(p.nd == -1){
            open++;
            //first interception
            if(open == 1){
                ini = busca_lower(p.st, i);
                db(ini);
            }
        }
        //1: leaves the polygon
        if(p.nd == 1) open--;
        if(open == 0) {
            //last interception, compute interval inside the polygon
            type a = ini;
            type b = busca_upper(p.st, i);
            b--;
                db(b);
            if(b >= a){
                db(i _ a _ b);
                novo.push_back({a, b});
                cur.push_back({a, b});
            }
        }
    }
    //clear last
    for(auto p : last) update(1, 0, 0, w, p.st, p.nd, 0);
    //build new last
    last = novo;
    for(auto p : add)  last.push_back(p);
    // db(last.size());
    for(auto p : last) db(p.st _ p.nd), update(1, 0, 0, w, p.st, p.nd, 1);

    //return answer
    if(i == h){
        for(auto p : cur) update(1, 1, 0, w, p.st, p.nd, 0);
        cur.clear();
        return 0;
    }
    for(auto p : cur) update(1, 1, 0, w, p.st, p.nd, 1);
    ans = query(1, 1, 0, w, 0, w);
    for(auto p : cur) update(1, 1, 0, w, p.st, p.nd, 0);
    cur.clear();
    return ans;
}

int main(){
    memset(lazy, -1, sizeof(lazy));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w >> h;
    pts.resize(n);
    type mn_y = INF;
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
        mn_y = min(mn_y, pts[i].y);
    }

    //REMOVE COLLINEAR POINTS: not necessary.
    // for(int i = 0; i < pts.size(); i++){
    //     if(direction(pts[i], pts[(i - 1 + (int)pts.size())%pts.size()], pts[(i + 1)%pts.size()]) == 0) pts.erase(pts.begin() + i), i--;
    // }

    long long ans = 0;
    for(int i = h; i >= mn_y; i--){
        ans += calc(i);
    }
    cout << ans << "\n";
    return 0;
}