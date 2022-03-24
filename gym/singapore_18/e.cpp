#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

typedef long long type;

bool ge(type x, type y) { return x >= y; }
bool le(type x, type y) { return x <= y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point{
    type x, y;
    point() : x(0), y(0){}
    point(type x, type y) : x(x), y(y) {}
    
    point operator -() {return point(-x, -y);}
    point operator +(point p) {return point(x + p.x, y + p.y);}
    point operator -(point p) {return point(x - p.x, y - p.y);}

    point operator *(type k){return point(x * k, y * k);}
    point operator /(type k) {return point(x / k, y / k);}

    //inner product
    type operator *(point p) { return x*p.x + y*p.y; }
    //cross product
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y;}
    bool operator !=(const point &p) const{ return (x != p.x) or (y != p.y);}
    bool operator <(const point &p) const{ return (x < p.x) or (x == p.x and y < p.y);}

    // 0 => same direction
    // 1 => p is on the left 
    //-1 => p is on the right    
    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return ge(x, 0) - le(x, 0);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

};

type cross(point p, point q){return p.x * q.y - p.y * q.x;}
type area_2(point a, point b, point c){return cross(a, b) + cross(b, c) + cross(c, a);}

#define REMOVE_REDUNDANT
#ifdef REMOVE_REDUNDANT
bool between(const point &a, const point &b, const point &c){
    return (fabs(area_2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
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


point origin;
// bool radial(point p, point q) {
//   int dir = p.dir(origin, q);
//   return dir > 0 or (!dir and p.on_seg(origin, q));
// }

int above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(point p, point q){
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin,q) > 0;
    //Be Careful: p.dir(origin,q) == 0
}
// Graham Scan O(nlog(n))
vector<point> graham_hull(vector<point> pts) {
    vector<point> ch(pts.size());
    point mn = pts[0];

    for(point p : pts) if (p.y < mn.y or (p.y == mn.y and p.x < mn.x)) mn = p;

    origin = mn;
    sort(pts.begin(), pts.end(), cmp);

    int n = 0;

    // IF: Convex hull without collinear points
    // for(point p : pts) {
    //     while (n > 1 and ch[n-1].dir(ch[n-2], p) < 1) n--;
    //     ch[n++] = p;
    // }

    //ELSE IF: Convex hull with collinear points
    for(point p : pts) {
    while (n > 1 and ch[n-1].dir(ch[n-2], p) < 0) n--;
    ch[n++] = p;
    }

    /*this part not safe
    for(int i=pts.size()-1; i >=1; --i)
    if (n > 1 and pts[i] != ch[n-1] and !pts[i].dir(pts[0], ch[n-1]))
        ch[n++] = pts[i];*/
    // END IF

    ch.resize(n);
    return ch;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<point> pts(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    // monotone_hull(pts);
    vector<point> tmp = graham_hull(pts);
    pts = tmp;
    n = pts.size();
    ll ans = 0;
    if(n > 2){
        pts.resize(2 * n);
        for(int i = 0; i < n; i++) pts[i + n] = pts[i];
        for(int l = 0; l < n; l++){
            for(int r = l + 1, k = r + 1; (r < l + n) and (k < l + n); r++){
                ll tmp = fabs(area_2(pts[l], pts[r], pts[k]));
                while((k + 1 < l + n) and fabs(area_2(pts[l], pts[r], pts[k])) <= fabs(area_2(pts[l], pts[r], pts[k + 1]))){
                    k = (k + 1);
                    tmp = fabs(area_2(pts[l], pts[r], pts[k + 1]));
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans/2 << ".";
    if(ans%2) cout << "5\n";
    else cout << "0\n";
    return 0;
}