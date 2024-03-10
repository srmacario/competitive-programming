#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
#define int long long
#define endl '\n'
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int INF = 1e18;
 
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};
 
point operator+(const point& p1, const point& p2) {
    return point(p1.x + p2.x, p1.y + p2.y);
}
 
point operator/(const point& p1, double p2) {
    return point(p1.x / p2, p1.y / p2);
}
 
point operator*(const point& p1, double p2) {
    return point(p1.x * p2, p1.y * p2);
}
 
double get_polygon_area(vector<point>& pts) {
    double area = 0;
    int n = pts.size();
    for(int i = 0; i < n; i++) {
        area += (pts[i].x * pts[(i + 1) % n].y - pts[i].y * pts[(i + 1) % n].x);
    }
    return abs(area) / 2;
}
 
point project_point(point p, double r) {
    point dir = point(p.x, p.y);
    double dist = sqrt(dir.x * dir.x + dir.y * dir.y);
    dir.x /= dist;
    dir.y /= dist;
 
    double p_dist = sqrt(p.x * p.x + p.y * p.y);
    double mylen = r * r / p_dist;
    return point(dir.x * mylen, dir.y * mylen);
}
 
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    point origin = point(0, 0);
    cin >> origin.x >> origin.y;
    double r;
    cin >> r;
    vector<point> pts;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        point p;
        cin >> p.x >> p.y;
        p.x -= origin.x;
        p.y -= origin.y;
        pts.push_back(p);
    }
    origin.x = origin.y = 0;
    point x = project_point(point(1, 0), r);
    vector<point> pts2;
    for(int i = 0; i < n; i++) {
        point direction = point(pts[(i + 1) % n].x - pts[i].x, pts[(i + 1) % n].y - pts[i].y);
        for(int j = 0; j < 200000; j++) {
            point p = project_point(pts[i] + (direction * j / 200000), r);
            pts2.push_back(p);
        }
    }
    double ans = get_polygon_area(pts2);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}