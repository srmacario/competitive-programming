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

struct point{
    type x, y;
    point() : x(0), y(0){}
    point(type x, type y) : x(x), y(y) {}
    
    point operator -() {return point(-x, -y);}
    point operator +(point p) {return point(x + p.x, y + p.y);}
    point operator -(point p) {return point(x - p.x, y - p.y);}

    point operator *(type k){return point(x * k, y * k);}
    point operator /(type k) {return point(x / k, y / k);}

    bool operator ==(const point &p) const{ return x == p.x and y == p.y;}
    bool operator !=(const point &p) const{ return (x != p.x) or (y != p.y);}
    bool operator <(const point &p) const{ return (x < p.x) or (x == p.x and y < p.y);}

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<point> pts(n);
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    monotone_hull(pts);
    n = pts.size();
    pts.resize(2 * n);
    for(int i = 0; i < n; i++) pts[i + n] = pts[i];
    ll ans = 0;
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
    cout << ans/2 << ".";
    if(ans%2) cout << "5\n";
    else cout << "0\n";
    return 0;
}