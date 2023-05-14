#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-6, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

typedef long long type;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }

struct point {
    type x, y;
    point(): x(0), y(0) {}
    point(type _x, type _y): x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(x * k, y * k); }
    point operator /(type k) { return point(x / k, y / k); }

    type operator %(point p) { return x * p.y - y * p.x; }

    bool operator ==(const point& p) const { return x == p.x and y == p.y; }
    bool operator !=(const point& p) const { return x != p.x or y != p.y; }
    bool operator <(const point& p) const { return (x < p.x) or (x == p.x and y < p.y); }

    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return (x >= 0) - (x <= 0);
    }
};

point rotate_cw90(point p) { return point(p.y, -p.x); }

ostream& operator<<(ostream& os, const point& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

point origin;

int above(point p) {
    if (p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(pair<point, point> a, pair<point, point> b) {
    point p = rotate_cw90(a.nd - a.st);
    point q = rotate_cw90(b.nd - b.st);

    int tmp = above(q) - above(p);
    if (tmp) return tmp > 0;
    if (p.dir(origin, q) == 0) {
        if (a.nd.dir(a.st, b.st) == 0) {
            if (a.st == b.st) return a.nd < b.nd;
            return a.st < b.st;
        }
        return a.nd.dir(a.st, b.st) > 0;
    }
    return p.dir(origin, q) > 0;
}

ld compute_area(vector<pair<ld, ld>>& p) {
    ld area = 0;
    for (int i = 0; i < p.size(); i++) {
        int j = (i + 1) % p.size();
        area += p[i].st * p[j].nd - p[j].st * p[i].nd;
    }
    return fabs(area / 2);
}

int n;
ll sz;
map<point, int> id;

ld calc_area(point p1, point p2) {
    pair<ld, ld> a, b;
    if (p1.x == p2.x) {
        return (ld)sz * (sz - p1.x);
    }
    else if (p1.y == p2.y) {
        return (ld)p1.y * sz;
    }
    else {
        vector<pair<ld, ld>> p;
        ld m_coef = (ld)(p2.y - p1.y) / (ld)(p2.x - p1.x);
        ld n_coef = (p1.y - m_coef * p1.x);
        a = { 0, n_coef }, b = { sz, sz * m_coef + n_coef };
        if (le(m_coef, 0)) {
            p.push_back({ 0, 0 });

            //y = mx + n
            //top left
            if (ge(n_coef, sz)) p.push_back({ 0, sz }), p.push_back({ (sz - n_coef) / m_coef, sz });
            else p.push_back({ 0, n_coef });

            //bottom right
            if (ge(-n_coef / m_coef, sz)) p.push_back({ sz, m_coef * sz + n_coef }), p.push_back({ sz, 0 });
            else p.push_back({ -n_coef / m_coef, 0 });
        }
        else {
            //y = mx + n
            //bottom left
            if (ge(n_coef, 0)) p.push_back({ 0, 0 }), p.push_back({ 0, n_coef });
            else p.push_back({ -n_coef / m_coef, 0 });

            //top right
            if (ge(m_coef * sz + n_coef, sz))  p.push_back({ (sz - n_coef) / m_coef, sz }), p.push_back({ sz, sz });
            else p.push_back({ sz, m_coef * sz + n_coef });

            p.push_back({ sz, 0 });
        }
        return compute_area(p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> sz >> n;
    vector<point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    if(n == 1) {
        ld area = min({calc_area(pts[0], {0, sz}), calc_area(pts[0], {sz, 0})});
        area = min({area, calc_area(pts[0], {0, 0}), calc_area(pts[0], {sz, sz})});
        area = min({area, sz * sz - calc_area(pts[0], {0, 0}), sz * sz - calc_area(pts[0], {sz, sz})});
        area = min({area, sz * sz - calc_area(pts[0], {0, sz}), sz * sz - calc_area(pts[0], {sz, 0})});
        area = min(area, (ld)sz * (sz - pts[0].x));
        area = min(area, (ld)sz * pts[0].x);
        area = min(area, (ld)sz * (sz - pts[0].y));
        area = min(area, (ld)sz * pts[0].y);
        cout << setprecision(20) << fixed << (1.0 - area / (sz * sz));
        return 0;
    }
    //sort points
    sort(pts.begin(), pts.end());
    for (int i = 0; i < n; i++) {
        point p = pts[i];
        id[p] = i;
    }
    //create edges and sort perpendicular radially
    vector<pair<point, point>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({ pts[i], pts[j] });
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    ld ans = -LINF;
    //radial sweep
    for (auto e : edges) {
        int l = id[e.st], r = id[e.nd];
        if(r < l or (r - l > 1)) assert(1 != 1);
        //process
        int l_cookie = r + 1, r_cookie = n - l;
        //db(l_cookie _ r_cookie _ l _ r);
        ld below_area = calc_area(e.st, e.nd);
        //below calc
        ld tmp = (ld)(l_cookie) / ((ld)n) - (below_area / (sz * sz));
        ans = max(ans, tmp);
        //upper calc
        tmp = (ld)(r_cookie) / ((ld)n) - ((sz * sz - below_area) / (sz * sz));
        ans = max(ans, tmp);
        swap(pts[l], pts[r]);
        swap(id[e.nd], id[e.st]);
    }
    cout << setprecision(20) << fixed << ans << "\n";
    return 0;
}