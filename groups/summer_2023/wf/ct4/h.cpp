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

struct point {
    type x, y;
    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y);}
    point operator +(point p) { return point(x + p.x, y + p.y);}
    point operator -(point p) { return point(x - p.x, y - p.y);}

    point operator *(type k){ return point(k*x, k*y); }
    point operator /(type k){ return point(x/k, y/k); }

    type operator *(point p){ return x * p.x + y * p.y; }
    type operator %(point p){ return x * p.y - y * p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y;}
    bool operator !=(const point &p) const{ return x != p.x or y != p.y;}
    bool operator <(const point &p) const{ return x < p.x or (x == p.x and y > p.y);}
};

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

type cross(point p, point q) { return p.x * q.y - p.y * q.x;}

type area_2(point a, point b, point c){ return cross(a, b) + cross(b, c) + cross(c, a);}

void create_upper_hull(set<point> &pts){
    if(pts.empty()) return;

    set<point> up;
    ll max_x = 0, max_y = 0;
    for(auto p : pts) max_x = max(max_x, p.x), max_y = max(max_y, p.y);
    pts.insert({max_x, 0}), pts.insert({0, max_y});
    for(auto p : pts){
        
        auto pt = up.rbegin();
        point last, semilast;
        if(up.size() > 1) last = *pt, semilast = *(++pt);
        while(up.size() > 1 && area_2(semilast, last, p) >= 0){
            up.erase(*up.rbegin());
            pt = up.rbegin();
            if(up.size() > 1) last = *pt, semilast = *(++pt);
        }
        up.insert(p);
    }
    pts = up;
}

bool check(int t, point p, set<point>& pts){
    if(pts.empty()) return false;
    ll x = p.x / t, y = (p.y - 1)/t + 1;
    auto lb = pts.upper_bound({x, y});
    if(lb == pts.end()) return false;
    auto ub = (lb--);
    return (cross(*lb, p) + cross(p, *ub) + t * cross(*ub, *lb)) >= 0;
}

void ins(point p, set<point>& pts){
    if(pts.count(p)) return;
    if(pts.empty()){
        pts.insert(p);
        pts.insert({0, p.y});
        pts.insert({p.x, 0});
        return;
    }
    auto lb = pts.upper_bound(p);
    if(lb == pts.end()) return;
    auto ub = (lb--);
    if((cross(*lb, p) + cross(p, *ub) + cross(*ub, *lb)) >= 0) return;
    //left
    while(lb != pts.begin()){
        auto last_lb = lb;
        last_lb--;
        if(area_2(*last_lb, *ub, p) >= area_2(*lb, *ub, p)){
            pts.erase(*lb);
        }
        lb = last_lb;
    }
    if(lb == pts.begin()){
        pts.erase(*lb);
        pts.insert({0, p.y});
        lb = pts.begin();
    }
    //right
    while(*ub != *pts.rbegin()){
        auto next_ub = ub;
        next_ub++;
        if(area_2(*lb, *next_ub, p) >= area_2(*lb, *ub, p)){
            pts.erase(*ub);
        }
        ub = next_ub;
    }
    if(*ub == *pts.rbegin()){
        pts.erase(*ub);
        pts.insert({p.x, 0});
    }
    pts.insert(p);
}

int n, e, del[N];
vector<point> all_pts;
set<point> pts;
vector<pair<pii, point>> qry;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    all_pts.resize(n);
    for(int i = 0; i < n; i++) cin >> all_pts[i].x >> all_pts[i].y;

    cin >> e;
    for(int i = 0; i < e; i++){
        char ch;
        cin >> ch;
        if(ch == 'c'){
            int t;
            point p;
            cin >> t >> p.x >> p.y;
            qry.push_back({{0, t}, p});
        }
        else{
            int q;
            cin >> q;
            qry.push_back({{1, q}, all_pts[q - 1]});
            del[q - 1] = 1;
        }
    }

    for(int i = 0; i < n; i++) if(!del[i]) pts.insert(all_pts[i]);

    create_upper_hull(pts);

    vector<string> ans;
    while(qry.size()){
        if(qry.back().st.st){
            ins(qry.back().nd, pts);
        }
        else{
            ans.push_back(check(qry.back().st.nd, qry.back().nd, pts) ? "no\n" : "yes\n");
        }
        qry.pop_back();
    }
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a;
    return 0;
}