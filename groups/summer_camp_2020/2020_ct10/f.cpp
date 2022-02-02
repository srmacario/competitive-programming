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

typedef long long type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
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

//for reading purposes avoid using * and % operators, use the functions above:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
type area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

int angleLess(const point& a1, const point& b1, const point& a2, const point& b2) {
    //angle between (a1 and b1) vs angle between (a2 and b2)
    //1  : bigger
    //-1 : smaller
    //0  : equal
    point p1(dot(   a1, b1), abs(cross(   a1, b1)));
    point p2(dot(   a2, b2), abs(cross(   a2, b2)));
    if(cross(p1, p2) < 0) return 1;
    if(cross(p1, p2) > 0) return -1;
    return 0;
}

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

//Shamos - Hoey for test polygon simple in O(nlog(n))
struct edge{
    point ini, fim;
    edge(point ini = point(0,0), point fim = point(0,0)) : ini(ini), fim(fim) {}
};

bool operator < (const edge& a, const edge& b) {
    if (a.ini == b.ini) return direction(a.ini, a.fim, b.fim) < 0;
    if (a.ini.x < b.ini.x) return direction(a.ini, a.fim, b.ini) < 0;
    return direction(a.ini, b.fim, b.ini) < 0;
}

bool cmp(pair<point, pii> a, pair<point, pii> b){
    if(a.st.x == b.st.x){
        if(a.nd.st == b.nd.st){
            return a.st.y > b.st.y;
        }
        return a.nd.st < b.nd.st;
    }
    return a.st.x < b.st.x;
}

void left_sweep(const vector<edge> &pts, vector<set<int>> &par, vector<vector<int>> &son, vector<ll> &water){
    vector <pair<point, pii>> eve;
    vector <pair<edge, int>> edgs;
    set <pair<edge, int>> sweep;
    int n = (int)pts.size();
    for(int i = 0; i < n; i++){
        edgs.pb(make_pair(pts[i], i));
        eve.pb({pts[i].ini, {0, i}});
        eve.pb({pts[i].fim, {1, i}});
    }
    sort(eve.begin(), eve.end(), cmp);
    int last = -INF;
    for(auto e : eve){
        if(!e.nd.st){
            if(!sweep.size()) last = e.st.x;
            else{
                auto cur = sweep.lower_bound(edgs[e.nd.nd]);
                if(cur == sweep.begin()){
                    water[cur -> nd] += (e.st.x - last);
                    last = e.st.x;
                }
            }
            sweep.insert(edgs[e.nd.nd]);
        }
        else{
            auto below = sweep.upper_bound(edgs[e.nd.nd]);
            auto cur = below, above = --cur;
            if(cur == sweep.begin()){
                water[cur -> nd] += (e.st.x - last);
                last = e.st.x;
            }
            if(edgs[e.nd.nd].st.ini.y > edgs[e.nd.nd].st.fim.y){
                if(below != sweep.end()){
                    son[e.nd.nd].pb(below->nd);
                    par[below->nd].insert(e.nd.nd);
                }
            }
            sweep.erase(cur);
        }
    }
}

void right_sweep(const vector<edge> &pts, vector<set<int>> &par, vector<vector<int>> &son, vector<ll> &water){
    vector <pair<point, pii>> eve;
    vector <pair<edge, int>> edgs;
    set <pair<edge, int>> sweep;
    int n = (int)pts.size();
    for(int i = 0; i < n; i++){
        edgs.pb(make_pair(pts[i], i));
        eve.pb({pts[i].ini, {0, i}});
        //eve[eve.size() - 1].st.y = -eve[eve.size() - 1].st.y;
        eve.pb({pts[i].fim, {1, i}});
        //eve[eve.size() - 1].st.y = -eve[eve.size() - 1].st.y;
    }
    sort(eve.begin(), eve.end(), cmp);
    for(auto e : eve){
        //db(e.st _ e.nd.nd);
        if(!e.nd.st){
            sweep.insert(edgs[e.nd.nd]);
        }
        else{
            auto below = sweep.upper_bound(edgs[e.nd.nd]);
            auto cur = below, above = --cur;
            if(edgs[e.nd.nd].st.ini.y > edgs[e.nd.nd].st.fim.y){
                if(below != sweep.end()){
                    son[e.nd.nd].pb(below->nd);
                    par[below->nd].insert(e.nd.nd);
                }
            }
            sweep.erase(cur);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<edge> pts(n);
        vector<vector<int>> son(n);
        vector<set<int>> par(n);
        vector<ll> water(n);
        for(int i = 0; i < n; i++){
            cin >> pts[i].ini.x >> pts[i].ini.y;
            cin >> pts[i].fim.x >> pts[i].fim.y;
        }
        left_sweep(pts, par, son, water);
        for(int i = 0; i < n; i++){
            swap(pts[i].ini, pts[i].fim);
            pts[i].ini.x = -pts[i].ini.x;
            pts[i].fim.x = -pts[i].fim.x;
        }
        right_sweep(pts, par, son, water);
        vector<int> upd;
        for(int i = 0; i < n; i++) if(par[i].empty()) upd.pb(i);

        while(!upd.empty()){
            int i = upd.back();
            upd.pop_back();
            for(auto x : son[i]){
                water[x] += water[i];
                par[x].erase(i);
                if(par[i].empty()) upd.pb(x);
            }
        }
        for(int i = 0; i < n; i++) cout << water[i] << "\n";
    }
    return 0;
}