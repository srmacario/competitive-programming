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

const ld EPS = 1e-3, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 205;

typedef long double type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }
int sign(type x) { return ge(x, 0) - le(x, 0); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(x*k, y*k); }
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
        type d = (*this - o) % (p - o);
        return sign(d);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    ld abs() { return sqrt(x*x + y*y); }
    type abs2() { return x*x + y*y; }
    ld dist(point q) { return (*this - q).abs(); }
    type dist2(point q) { return (*this - q).abs2(); }
};

// 0 => same direction
// 1 => q is on the left compared to p
//-1 => q is on the right compared to p
int direction(point o, point p, point q) { return p.dir(o, q); }

//for reading purposes avoid using * and % operators, use the functions below:
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

istream &operator>>(istream &is, point &p) {
    is >> p.x >> p.y; 
    return is;
}

//-1: can
//0: cant
//1: edge
ll dp[N][N];
int can[N][N];

ll calc(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(!can[i][j]){
        return dp[i][j] = 0;
    } 
    if(can[i][j] == 1){
        return dp[i][j] = 1;
    }
    ll ans = 0;
    for(int k = i + 1; k < j; k++){
        ll l = calc(i, k), r = calc(k, j);
        ans = (ans + (l * r) % MOD) % MOD;
    }
    dp[i][j] = ans;
    return dp[i][j];
}

bool segment_segment_intersect(point a, point b, point c, point d) {
    if (a.dist2(c) < EPS || a.dist2(d) < EPS ||
        b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    int d1, d2, d3, d4;
    d1 = direction(a, b, c);
    d2 = direction(a, b, d);
    d3 = direction(c, d, a);
    d4 = direction(c, d, b);
    if (d1*d2 < 0 and d3*d4 < 0) return 1;
    return a.on_seg(c, d) or b.on_seg(c, d) or
            c.on_seg(a, b) or d.on_seg(a, b);
}

bool upward_edge(point a, point b, point c, point d){
    //Line: a - b
    //Edge: c - d
    //Edge who comes from bottom to top (or from right to left), but does not consider the final endpoint
    return (direction(a, b, c) < 1 and direction(a, b, d) == 1);
}

bool downward_edge(point a, point b, point c, point d){
    //Line: a - b
    //Edge: c - d
    //Edge who comes from top to bottom (or from left to right), but does not consider the initial endpoint
    return (direction(a, b, c) == 1 and direction(a, b, d) < 1);
}


point lines_intersect(point p, point q, point a, point b) {
    point r = q - p, s = b - a, c(p%q, a%b);
    if (eq(r%s,0)) return point(LINF, LINF);
    return point(point(r.x, s.x) % c, point(r.y, s.y) % c) / (r%s);
}

bool lines_parallel(point a, point b, point c, point d) { 
    return fabs(cross(b - a, d - c)) < EPS; 
}

bool lines_collinear(point a, point b, point c, point d) {
  return lines_parallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

bool line_line_intersect(point a, point b, point c, point d) {
    if(!lines_parallel(a, b, c, d)) return true;
    if(lines_collinear(a, b, c, d)) return true; 
    return false;
}


//ray in direction c -> d
bool segment_ray_intersect(point a, point b, point c, point d){
    if (a.dist2(c) < EPS || a.dist2(d) < EPS ||
        b.dist2(c) < EPS || b.dist2(d) < EPS) return true;
    if (lines_collinear(a, b, c, d)) {
        if(c.on_seg(a, b)) return true;
        if(ge(dot(d - c, a - c), 0)) return true;
        return false;
    }
    if(!line_line_intersect(a, b, c, d)) return false;
    point inters = lines_intersect(a, b, c, d);
    if(!inters.on_seg(a, b)) return false;
    if(ge(dot(inters - c, d - c), 0)) return true;
    return false; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<point> pts(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> pts[i];
    
    //check if it is valid edge
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(j == i + 1){
                can[i][j] = 1;
                continue;
            }
            bool cross = false;
            for(int k = 0; k < n; k++){
                if(k == i or k == j){
                    cross |= (pts[(k + 1) % n].on_seg(pts[i], pts[j]));
                    continue;
                }
                if((k + 1)%n == i or (k + 1)%n == j){
                    cross |= (pts[k].on_seg(pts[i], pts[j]));
                    continue;
                }
                cross |= segment_segment_intersect(pts[i], pts[j], pts[k % n], pts[(k + 1) % n]);
            }
            
            int wn = 0;
            for(int k = 0; k < n; k++){
                if(k % n == i or (k + 1)%n == i) continue;
                if(upward_edge(pts[i], pts[j], pts[k % n], pts[(k + 1) % n]) or downward_edge(pts[i], pts[j], pts[k % n], pts[(k + 1) % n])){
                    if(segment_ray_intersect(pts[k % n], pts[(k + 1) % n], pts[i], pts[j])){
                        wn++;
                    }
                }
            }
            wn %= 2;
            can[i][j] = (!wn or cross) ? 0 : -1;
        }
    }
    can[0][n - 1] = -1;
    cout << calc(0, n - 1) << "\n";
    return 0;
}