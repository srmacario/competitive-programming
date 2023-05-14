#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-9, PI = acos(-1.);

typedef long double type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(k*x, k*y); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }
   
    int dir(point o, point p) {
        type x = (*this - o) % (p - o);
        return ge(x,0) - le(x,0);
    }

    bool on_seg(point p, point q) {
        if (this->dir(p, q)) return 0;
        return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
    }

};
type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }
//double area
type area_2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

point origin;

bool radial(point p, point q) {
    int dir = p.dir(origin, q);
    return dir > 0 or (!dir and p.on_seg(origin, q));
}
//Monotone chain O(nlog(n))
#define REMOVE_REDUNDANT
#ifdef REMOVE_REDUNDANT
bool between(const point &a, const point &b, const point &c) {
    return (fabs(area_2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void monotone_hull(vector<point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area_2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area_2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

    #ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
    #endif
}

type area(point a, point b, point c){
	return abs(a.x * b.y + b.x * c.y + c.x * b.y
		- a.y * b.x - b.y * c.x - c.y * a.x) / 2;
}

int main(){
	int n;
	type ans = 0;
	scanf("%d", &n);
	vector<point> v(n);
	for(int i = 0; i < n; i++)
		scanf("%Lf %Lf", &v[i].x, &v[i].y);
	monotone_hull(v);
	n = v.size();
	for(int i = 0; i < n; i++){
		int p = (i + 2) % n;
		for(int j = (i + 1) % n; j != i; j = (j + 1) % n){
			while(area(v[i], v[j], v[p]) <= area(v[i], v[j], v[(p + 1) % n]) && p != i)
				p = (p + 1) % n;
			ans = max(ans, area(v[i], v[j], v[p]));
		}
	}
	printf("%Lf\n", ans);
	return 0;
}