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

typedef long long type;
//for big coordinates change to long long

bool ge(type x, type y) { return x >= y; }
bool le(type x, type y) { return x <= y; }
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

type compute_signed_area(const vector<point> &p) {
    type area = 0;
    for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area;
}
bool is_ccw(vector<point> &p) {
    type area = 0;
    for(int i = 2; i < p.size(); i++) {
        area += cross(p[i] - p[0], p[i - 1] - p[0]);
    }
    return area > 0;
}

ll dp[N][N];
vector<point> pts;

ll calc(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if((j - i) == 1) return dp[i][j] = 1;
    ll ans = 0;
    for(int k = i + 1; k < j; k++){
        if(direction(pts[i], pts[j], pts[k]) != 1){
            continue;
        }
        ll l = calc(i, k), r = calc(k, j);
        ans = (ans + (l * r) % MOD) % MOD;
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    pts.resize(n);
    for(int i = 0; i < n; i++) cin >> pts[i];
    //if(compute_signed_area(pts) <= 0) reverse(pts.begin(), pts.end());
    if(!is_ccw(pts)) reverse(pts.begin(), pts.end());
    cout << calc(0, n - 1) << "\n";
    return 0;
}