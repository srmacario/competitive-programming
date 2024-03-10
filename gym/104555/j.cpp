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

typedef long double type;

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

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
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

    type dist_2(point p){ return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y); }
    ld dist(point p){ return sqrt(this->dist_2(p)); }
};

int direction(point o, point p, point q) { return p.dir(o, q); }
type dot(point p, point q)     { return p.x*q.x + p.y*q.y; }
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

type area_2(point a, point b, point c) { return cross((b - a), (c - b)); }

bool ccw(point a, point b, point c){ return area_2(a, b, c) > 0; }

typedef struct QuadEdge* Q;
struct QuadEdge {
	int id;
	point o;
	Q rot, nxt;
	bool used;

	QuadEdge(int id_ = -1, point o_ = point(INF, INF)) :
		id(id_), o(o_), rot(nullptr), nxt(nullptr), used(false) {}

	Q rev() const { return rot->rot; }
	Q next() const { return nxt; }
	Q prev() const { return rot->next()->rot; }
	point dest() const { return rev()->o; }
};

Q edge(point from, point to, int id_from, int id_to) {
	Q e1 = new QuadEdge(id_from, from);
	Q e2 = new QuadEdge(id_to, to);
	Q e3 = new QuadEdge;
	Q e4 = new QuadEdge;
	tie(e1->rot, e2->rot, e3->rot, e4->rot) = {e3, e4, e2, e1};
	tie(e1->nxt, e2->nxt, e3->nxt, e4->nxt) = {e1, e2, e4, e3};
	return e1;
}

void splice(Q a, Q b) {
	swap(a->nxt->rot->nxt, b->nxt->rot->nxt);
	swap(a->nxt, b->nxt);
}

void del_edge(Q& e, Q ne) { // delete e and assign e <- ne
	splice(e, e->prev());
	splice(e->rev(), e->rev()->prev());
	delete e->rev()->rot, delete e->rev();
	delete e->rot; delete e;
	e = ne;
}

Q conn(Q a, Q b) {
	Q e = edge(a->dest(), b->o, a->rev()->id, b->id);
	splice(e, a->rev()->prev());
	splice(e->rev(), b);
	return e;
}

bool in_c(point a, point b, point c, point p) { // p ta na circunf. (a, b, c) ?
	type p2 = p*p, A = a*a - p2, B = b*b - p2, C = c*c - p2;
	return area_2(p, a, b) * C + area_2(p, b, c) * A + area_2(p, c, a) * B > 0;
}

pair<Q, Q> build_tr(vector<point>& p, int l, int r) {
	if (r-l+1 <= 3) {
		Q a = edge(p[l], p[l+1], l, l+1), b = edge(p[l+1], p[r], l+1, r);
		if (r-l+1 == 2) return {a, a->rev()};
		splice(a->rev(), b);
		type ar = area_2(p[l], p[l+1], p[r]);
		Q c = ar ? conn(b, a) : 0;
		if (ar >= 0) return {a, b->rev()};
		return {c->rev(), c};
	}
	int m = (l+r)/2;
	auto [la, ra] = build_tr(p, l, m);
	auto [lb, rb] = build_tr(p, m+1, r);
	while (true) {
		if (ccw(lb->o, ra->o, ra->dest())) ra = ra->rev()->prev();
		else if (ccw(lb->o, ra->o, lb->dest())) lb = lb->rev()->next();
		else break;
	}
	Q b = conn(lb->rev(), ra);
	auto valid = [&](Q e) { return ccw(e->dest(), b->dest(), b->o); };
	if (ra->o == la->o) la = b->rev();
	if (lb->o == rb->o) rb = b;
	while (true) {
		Q L = b->rev()->next();
		if (valid(L)) while (in_c(b->dest(), b->o, L->dest(), L->next()->dest()))
			del_edge(L, L->next());
		Q R = b->prev();
		if (valid(R)) while (in_c(b->dest(), b->o, R->dest(), R->prev()->dest()))
			del_edge(R, R->prev());
		if (!valid(L) and !valid(R)) break;
		if (!valid(L) or (valid(R) and in_c(L->dest(), L->o, R->o, R->dest())))
			b = conn(R, b->rev());
		else b = conn(b->rev(), L->rev());
	}
	return {la, rb};
}

vector<vector<int>> delaunay(vector<point> v) {
	int n = v.size();
	auto tmp = v;
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return v[l] < v[r]; });
	for (int i = 0; i < n; i++) v[i] = tmp[idx[i]];
	assert(unique(v.begin(), v.end()) == v.end());
	vector<vector<int>> g(n);
	bool col = true;
	for (int i = 2; i < n; i++) if (area_2(v[i], v[i-1], v[i-2])) col = false;
	if (col) {
		for (int i = 1; i < n; i++)
			g[idx[i-1]].push_back(idx[i]), g[idx[i]].push_back(idx[i-1]);
		return g;
	}
	Q e = build_tr(v, 0, n-1).first;
	vector<Q> edg = {e};
	for (int i = 0; i < edg.size(); e = edg[i++]) {
		for (Q at = e; !at->used; at = at->next()) {
			at->used = true;
			g[idx[at->id]].push_back(idx[at->rev()->id]);
			edg.push_back(at->rev());
		}
	}
	return g;
}

void convex_hull(vector<point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area_2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
        while (dn.size() > 1 && area_2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

struct circle {
    point c;
    ld r;
    circle() { c = point(); r = 0; }
    circle(point _c, ld _r) : c(_c), r(_r) {}
};

circle circumcircle(point a, point b, point c) {
    circle ans;
    point u = point((b - a).y, -(b - a).x);
    point v = point((c - a).y, -(c - a).x);
    point n = (c - b)*0.5;
    ld t = cross(u, n) / cross(v, u);
    ans.c = ((a + c)*0.5) + (v * t);
    ans.r = ans.c.dist(a);
    return ans;
}

//be careful: test line_line_intersection before using this function
point compute_line_intersection(point a, point b, point c, point d) {
    b = b - a; d = c - d; c = c - a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

bool segment_segment_intersect(point a, point b, point c, point d) {
    if (a.dist_2(c) < EPS || a.dist_2(d) < EPS ||
        b.dist_2(c) < EPS || b.dist_2(d) < EPS) return true;
    int d1, d2, d3, d4;
    d1 = direction(a, b, c);
    d2 = direction(a, b, d);
    d3 = direction(c, d, a);
    d4 = direction(c, d, b);
    if (d1*d2 < 0 and d3*d4 < 0) return 1;
    return a.on_seg(c, d) or b.on_seg(c, d) or
            c.on_seg(a, b) or d.on_seg(a, b);
}

vector<point> box;

bool is_in_box(point p){
    ld mnx, mxx, mny, mxy;
    mnx = min({box[0].x, box[1].x, box[2].x, box[3].x});
    mxx = max({box[0].x, box[1].x, box[2].x, box[3].x});
    mny = min({box[0].y, box[1].y, box[2].y, box[3].y});
    mxy = max({box[0].y, box[1].y, box[2].y, box[3].y});
    if(p.x >= mnx and p.x <= mxx and p.y >= mny and p.y <= mxy) return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    box.resize(4);
    for(int i = 0; i < 4; i++) cin >> box[i].x >> box[i].y;
    convex_hull(box);

    int n;
    cin >> n;
    vector<point> pts(n);
    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    pts.push_back({-INF, -INF});
    pts.push_back({INF, -INF});
    pts.push_back({0, INF});
    vector<vector<int>> del = delaunay(pts);
    //rebuild voronoi from delaunay with circumcircles
    //each triangle circumcicle is a point belonging to each triangle point voronoi cell
    vector<vector<point>> voronoi(n);
    for(int i = 0; i < n; i++){
        for(int d = 0; d < del[i].size(); d++){
            int j = del[i][d], k = del[i][(d + 1) % del[i].size()];
            circle c = circumcircle(pts[i], pts[j], pts[k]);
            if(i < n) voronoi[i].push_back(c.c);
            if(j < n) voronoi[j].push_back(c.c);
            if(k < n) voronoi[k].push_back(c.c);
        }
    }
    //check if the border is inside some voronoi, if this occurs update answer
    ld ans = 0;
    for(int k = 0; k < 4; k++){
        pair<ld, int> mn = {LINF, INF};
        for(int i = 0; i < n + 3; i++){
            mn = min(mn, make_pair(box[k].dist(pts[i]), i));
        }
        if(mn.nd < n) ans = max(ans, box[k].dist(pts[mn.nd]));
    }
    for(int i = 0; i < n; i++){
        convex_hull(voronoi[i]);
        for(int j = 0; j < voronoi[i].size(); j++){
            //if voronoi is inside the border update the answer
            if(is_in_box(voronoi[i][j])) ans = max(ans, pts[i].dist(voronoi[i][j]));
            //if edge beginning in position i intercepts some border, this should be tested to
            for(int k = 0; k < 4; k++){
                if(segment_segment_intersect(voronoi[i][j], voronoi[i][(j + 1) % voronoi[i].size()], box[k], box[(k + 1)%4])){
                    point inter = compute_line_intersection(voronoi[i][j], voronoi[i][(j + 1) % voronoi[i].size()], box[k], box[(k + 1)%4]);
                    ans = max(ans, pts[i].dist(inter));
                }
            }
        }
    }
    cout << setprecision(20) << fixed << ans << "\n";
    return 0;
}