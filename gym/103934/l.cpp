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
const int N = 262144;

typedef long long type;

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(k*x, k*y); }
    point operator /(type k) { return point(x/k, y/k); }

    //inner product
    type operator *(point p) { return x*p.x + y*p.y; }
    //cross product
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x  or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }
};

type cross(point p, point q)   { return p.x*q.y - p.y*q.x; }

//double area
type area_2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

//Monotone chain O(nlog(n))
#define REMOVE_REDUNDANT
#ifdef REMOVE_REDUNDANT
bool between(const point &a, const point &b, const point &c) {
    return (fabs(area_2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

//new change: <= 0 / >= 0 became < 0 / > 0 (yet to be tested)

void monotone_hull(vector<point>& pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if(pts.size() <= 2) return;
    vector<point> up, dn;
    for (int i = 0; i < (int)pts.size(); i++) {
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
    for (int i = 2; i < (int)pts.size(); i++) {
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

ll maximize_scalar_product(vector<point> &hull, point vec) {
	// this code assumes that there are no 3 colinear points
	int ans = 0;
	int n = (int)hull.size();
	if(n < 20) {
        if(!n) return 0;
		for(int i = 0; i < n; i++) {
			if(hull[i] * vec > hull[ans] * vec) {
				ans = i;
			}
		}
	} else {
		if(hull[1] * vec > hull[ans] * vec) {
			ans = 1;
		}
		for(int rep = 0; rep < 2; rep++) {
			int l = 2, r = n - 1;
			while(l != r) {
				int mid = (l + r + 1) / 2;
				bool flag = hull[mid] * vec >= hull[mid-1] * vec;
				if(rep == 0) { flag = flag && hull[mid] * vec >= hull[0] * vec; }
				else { flag = flag || hull[mid-1] * vec < hull[0] * vec; }
				if(flag) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			if(hull[ans] * vec < hull[l] * vec) {
				ans = l;
			}
		}
	}
	return hull[ans] * vec;
}

vector<point> st[4*N];
point v[N];

void build (int p, int l, int r) {
    if (l == r) {
        st[p].push_back(v[l]);
        return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    for(int i = 0; i < st[2*p].size(); i++) st[p].push_back(st[2*p][i]);
    for(int i = 0; i < st[2*p + 1].size(); i++) st[p].push_back(st[2*p + 1][i]);
    monotone_hull(st[p]);
}

ll query (int p, int l, int r, int i, int j, point vec) {
    if (r < i or j < l) return -LINF;
    if (i <= l and r <= j) return maximize_scalar_product(st[p], vec);
    ll x = query(2*p, l, (l+r)/2, i, j, vec);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j, vec);
    return max(x, y);
}

int n, q, d[N], r[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1; i <= n; i++) v[i] = {d[i], r[i]};
    build(1, 1, n);
    for(int i = 0; i < q; i++){
        int s, e, D, R;
        cin >> s >> e >> D >> R;
        cout << query(1, 1, n, s, e, {D, R}) << "\n";
    }
    return 0;
}