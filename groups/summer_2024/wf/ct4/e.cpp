//Слава Україні, Героям слава

#include <bits/stdc++.h>

using namespace std;

using type = long long;
 
const int N = 1e5+5;
struct point {
    type x, y;
    point(type x_ = 0, type y_ = 0) : x(x_), y(y_) {}
    bool operator == (const point &p) const {
        return x == p.x and y == p.y;
    }
    bool operator < (const point &p) const {
        return (x < p.x) or (x == p.x and y < p.y);
    }
    point operator -(point p) { return point(x - p.x, y - p.y); }
};

type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q) {
    return p.x * q.y - p.y * q.x;
}

//angle between (a1 and b1) vs angle between (a2 and b2)
//1  : bigger
//-1 : smaller
//0  : equal
int angle_less(const point& a1, const point& b1, const point& a2, const point& b2) {
    point p1(dot(   a1, b1), abs(cross(   a1, b1)));
    point p2(dot(   a2, b2), abs(cross(   a2, b2)));
    if(cross(p1, p2) < 0) return 1;
    if(cross(p1, p2) > 0) return -1;
    return 0;
}
 
 
type area_2(point a, point b, point c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

bool between(const point &a, const point &b, const point &c) {
    return abs(area_2(a, b, c)) == 0 and (a.x - b.x) * (c.x - b.x) <= 0 and (a.y - b.y) * (c.y - b.y) <= 0;
}
 
void monotone_hull(vector<point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> up, dn;
    for(int i = 0; i < pts.size(); i++) {
        while(up.size() > 1 and area_2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while(dn.size() > 1 and area_2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        dn.push_back(pts[i]);
        up.push_back(pts[i]);
    }
    pts = dn;
    for(int i = (int)up.size() - 2; i >= 1; i--) {
        pts.push_back(up[i]);
    }
    if(pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for(int i = 2; i < (int)pts.size(); i++) {
        if(between(dn[(int)dn.size() - 2], dn[(int)dn.size() - 1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if((int)dn.size() >= 3 and between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
}

struct polygon_edge{
    point o, next, last;
    polygon_edge(point _o = {0, 0}, point _next = {0, 0}, point _last = {0, 0}) : o(_o), next(_next), last(_last) {}
    
    type dist() { return (next.x - o.x) * (next.x - o.x) + (next.y - o.y) * (next.y - o.y); }
};

bool cmp_edge(polygon_edge p, polygon_edge q){
    return (q.dist() == p.dist()) and !angle_less(q.next - q.o, q.last - q.o, p.next - p.o, p.last - p.o);
}

int n, m;
int kmppre[2 * N]; // n = strlen(s), m = strlen(p);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<point> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y; 
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y;
    }
    monotone_hull(a);
    monotone_hull(b);
    if(a.size() != b.size()) {
        cout << "NO\n";
        return 0;
    }
    n = a.size();
    if(n == 2){
        polygon_edge pa, pb;
        pa.next = a[1], pa.o = a[0];
        pb.next = b[1], pb.o = b[0];

        if(pa.dist() == pb.dist()){
            cout << "YES\n";
        }
        else cout << "NO\n";

        return 0;
    }
    m = 2 * n;
    vector<polygon_edge> a_edge(m), b_edge(n);
    for(int i = 0; i < n; i++){
        a_edge[i] = polygon_edge(a[i], a[(i - 1 + n) % n],  a[(i - 2 + n) % n]);
        b_edge[i] = polygon_edge(b[i], b[(i - 1 + n) % n],  b[(i - 2 + n) % n]);
    }
    for(int i = n; i < 2 * n; i++) a_edge[i] = a_edge[i - n];
    //kmppre
    kmppre[0] = -1;
    for (int i = 0, j = -1; i < n; kmppre[++i] = ++j)
        while (j >= 0 and !cmp_edge(b_edge[i], b_edge[j]))
            j = kmppre[j];

    //kmp
    for (int i = 0, j = 0; i < m;) {
        while (j >= 0 and !cmp_edge(a_edge[i], b_edge[j])) j = kmppre[j];
        i++, j++;
        if (j == n) {
            // match position i-j
            cout << "YES\n";
            j = kmppre[j];
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
