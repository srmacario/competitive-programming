#include <bits/stdc++.h>
#include <chrono>
#include <random>

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

const ld EPS = 1e-13, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

struct PT {
	typedef long double T;
	T x, y;
	PT(T _x = 0, T _y = 0) : x(_x), y(_y){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(T c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	T operator !()        const { return x*x+y*y;   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
	bool operator < (const PT &p) const { return x != p.x ? x < p.x : y < p.y; }
	bool operator == (const PT &p)const { return x == p.x && y == p.y; }

	friend std::ostream& operator << (std::ostream &os, const PT &p) {
		return os << p.x << ' ' << p.y;
	}
	friend std::istream& operator >> (std::istream &is, PT &p) {
		return is >> p.x >> p.y;
	}
};

struct Segment {
	typedef long double T;
	PT p1, p2;
	T a, b, c;

	Segment() {}

	Segment(PT st, PT en) {
		p1 = st, p2 = en;
		a = -(st.y - en.y);
		b = st.x - en.x;
		c = a * en.x + b * en.y;
	}

	T plug(T x, T y) {
		// plug >= 0 is to the right
		return a * x + b * y - c;
	}

	T plug(PT p) {
		return plug(p.x, p.y);
	}

	bool inLine(PT p) { return (p - p1) % (p2 - p1) == 0; }
	bool inSegment(PT p) {
		return inLine(p) && (p1 - p2) * (p - p2) >= 0 && (p2 - p1) * (p - p1) >= 0;
	}

	PT lineIntersection(Segment s) {
		long double A = a, B = b, C = c;
		long double D = s.a, E = s.b, F = s.c;
		long double x = (long double) C * E - (long double) B * F;
		long double y = (long double) A * F - (long double) C * D;
		long double tmp = (long double) A * E - (long double) B * D;
		x /= tmp;
		y /= tmp;
		return PT(x, y);
	}
	
	bool polygonIntersection(const std::vector<PT> &poly) {
		long double l = -1e18, r = 1e18;
		for(auto p : poly) {
			long double z = plug(p);
			l = std::max(l, z);
			r = std::min(r, z);
		}
		return l - r > EPS;
	}
};

std::vector<PT> cutPolygon(std::vector<PT> poly, Segment seg) {
	int n = (int) poly.size();
	std::vector<PT> ans;
	for(int i = 0; i < n; i++) {
		ld z = seg.plug(poly[i]);
		if(z > -EPS) {
			ans.push_back(poly[i]);
		}
		ld z2 = seg.plug(poly[(i + 1) % n]);
		if((z > EPS && z2 < -EPS) || (z < -EPS && z2 > EPS)) {
			ans.push_back(seg.lineIntersection(Segment(poly[i], poly[(i + 1) % n])));
		}
	}
	return ans;
}

Segment getBisector(PT a, PT b) {
	Segment ans(a, b);
	std::swap(ans.a, ans.b);
	ans.b *= -1;
	ans.c = ans.a * (a.x + b.x) * 0.5 + ans.b * (a.y + b.y) * 0.5;
	return ans;
}

int r;
// O(N^2) expected time
std::vector<std::vector<PT>> getVoronoi(std::vector<PT> pts) {
	// assert(pts.size() > 0);
	int n = (int) pts.size();
	std::vector<int> p(n, 0);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	shuffle(p.begin(), p.end(), rng);
	std::vector<std::vector<PT>> ans(n);
	ans[0].emplace_back(-r, -r);
	ans[0].emplace_back(r, -r);
	ans[0].emplace_back(r, r);
	ans[0].emplace_back(-r, r);
	for(int i = 1; i < n; i++) {
		ans[i] = ans[0];
	}
	for(auto i : p) {
		for(auto j : p) {
			if(j == i) break;
			auto bi = getBisector(pts[j], pts[i]);
			if(!bi.polygonIntersection(ans[j])) continue;
			ans[j] = cutPolygon(ans[j], getBisector(pts[j], pts[i]));
			ans[i] = cutPolygon(ans[i], getBisector(pts[i], pts[j]));
		}
	}
	return ans;
}

bool is_in_voronoi(int j, PT p, vector<PT> pts){
    ld d = !(p - pts[j]);
    for(int i = 0; i < pts.size(); i++){
        if(i == j) continue;
        if(ge(!(p - pts[i]), d)) continue;
        return false;
    }
    return true;
}

// compute intersection of line through PTs a and b with
// circle centered at c with radius r > 0
vector<PT> circle_line_intersection(PT a, PT b, ld r) {
    vector<PT> ret;
    b = b - a;
    a = a;
    ld A = b * b;
    ld B = a * b;
    ld C = a * a - r * r;
    ld D = B*B - A*C;
    if (!ge(D, 0)) return ret;
    ret.push_back(a + b*((sqrt(D) - B)/A));
    return ret;
}

struct point {
    ll x, y;

    point() : x(0), y(0) {}
    point(ll _x, ll _y) : x(_x), y(_y) {}

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x  or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n >> r;
    vector<PT> pts(n);
    vector<point> tmp(n);
    for(int i = 0; i < n; i++){
        cin >> tmp[i].x >> tmp[i].y;
    }
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    n = tmp.size();
    for(int i = 0; i < n; i++) pts[i].x = tmp[i].x, pts[i].y = tmp[i].y;
    vector<vector<PT>> voronoi = getVoronoi(pts);
    ld ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < voronoi[i].size(); j++){
            PT p = voronoi[i][j];
			//distance between voronoi point and cell point
            if(le((!p), r * r) and le(ans, (!(p - pts[i])))) ans = !(p);
            //distance from pts[i] and intersection between voronoi edge and circle
			if(le((!voronoi[i][j]), r * r) and le((!voronoi[i][(j + 1) % voronoi[i].size()]), r * r))
				continue;
			else if((!le((!voronoi[i][j]), r * r)) and le((!voronoi[i][(j + 1) % voronoi[i].size()]), r * r)){
            	vector<PT> inters = circle_line_intersection(voronoi[i][(j + 1) % voronoi[i].size()], voronoi[i][j], r);
				for(auto intr : inters){
					// db(intr);
					if(le(ans, (!(intr - pts[i])))) ans = !(intr - pts[i]);
				}
				continue;
			}
			else if((le((!voronoi[i][j]), r * r)) and !le((!voronoi[i][(j + 1) % voronoi[i].size()]), r * r)){
            	vector<PT> inters = circle_line_intersection(voronoi[i][j], voronoi[i][(j + 1) % voronoi[i].size()], r);
				for(auto intr : inters){
					// db(intr);
					if(le(ans, (!(intr - pts[i])))) ans = !(intr - pts[i]);
				}
				continue;
			}
        }
        PT u1 = (pts[i] / sqrt(!pts[i])) * r, u2 = (pts[i] / sqrt(!pts[i])) * -r;
        if(tmp[i] == point(0, 0)){
            u1 = PT(r, 0), u2 = PT(-r, 0);
            if(is_in_voronoi(i, u1, pts) and le(ans, !(u1 - pts[i]))) ans = !(u1 - pts[i]);
            if(is_in_voronoi(i, u2, pts) and le(ans, !(u2 - pts[i]))) ans = !(u2 - pts[i]);

            u1 = PT(0, r), u2 = PT(0, -r);
            if(is_in_voronoi(i, u1, pts) and le(ans, !(u1 - pts[i]))) ans = !(u1 - pts[i]);
            if(is_in_voronoi(i, u2, pts) and le(ans, !(u2 - pts[i]))) ans = !(u2 - pts[i]);

        }
        else{
            if(is_in_voronoi(i, u1, pts) and le(ans, !(u1 - pts[i]))) ans = !(u1 - pts[i]);
            if(is_in_voronoi(i, u2, pts) and le(ans, !(u2 - pts[i]))) ans = !(u2 - pts[i]);            
        }
    }
    cout << setprecision(20) << fixed << sqrt(ans) << "\n";
    return 0;
}