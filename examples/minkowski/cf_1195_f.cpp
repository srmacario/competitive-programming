//ITA MINKOWSKI
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

/*
 * Point 2D
 */

struct point {
	ll x, y;
	point() { x = y = 0; }
	point(ll _x, ll _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if (abs(x - other.x) > 0) return x < other.x;
		else return y < other.y;
	}
	point operator +(point other) const {
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const {
		return point(x - other.x, y - other.y);
	}
	point operator *(ll k) const {
		return point(x*k, y*k);
	}
};

ll dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

ll inner(point p1, point p2) {
	return p1.x*p2.x + p1.y*p2.y;
}

ll cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

bool collinear(point p, point q, point r) {
	return abs(cross(p-q, r-p)) == 0;
}
ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

/*
 * Polygon 2D
 */

typedef vector<point> polygon;

ll signedArea2(polygon & P) {
	ll result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		result += cross(P[i], P[(i+1)%n]);
	}
	return result;
}

int leftmostIndex(vector<point> & P) {
	int ans = 0;
	for(int i=1; i<(int)P.size(); i++) {
		if (P[i] < P[ans]) ans = i;
	}
	return ans;
}

polygon make_polygon(vector<point> P) {
	if (signedArea2(P) < 0) reverse(P.begin(), P.end());
	int li = leftmostIndex(P);
	reverse(P.begin(), P.begin()+li);
	reverse(P.begin()+li, P.end());
	reverse(P.begin(), P.end());
	return P;
}

/*
 * Minkowski sum
 */

// polygon minkowski(polygon & A, polygon & B) {
// 	polygon P; point v1, v2;
// 	int n1 = A.size(), n2 = B.size();
// 	P.push_back(A[0]+B[0]);
// 	for(int i = 0, j = 0; i < n1 || j < n2;) {
// 		v1 = A[(i+1)%n1]-A[i%n1];
// 		v2 = B[(j+1)%n2]-B[j%n2];
// 		if (j == n2 || cross(v1, v2) > EPS) {
// 			P.push_back(P.back() + v1); i++;
// 		}
// 		else if (i == n1 || cross(v1, v2) < -EPS) {
// 			P.push_back(P.back() + v2); j++;
// 		}
// 		else {
// 			P.push_back(P.back() + (v1+v2));
// 			i++; j++;
// 		}
// 	}
// 	P.pop_back();
// 	return P;
// }

void reorder_polygon(vector<point> & P){
    size_t pos = 0;
    for(size_t i = 1; i < P.size(); i++){
        if(P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
            pos = i;
    }
    rotate(P.begin(), P.begin() + pos, P.end());
}

vector<point> minkowski(vector<point> P, vector<point> Q){
    // the first vertex must be the lowest
    reorder_polygon(P);
    reorder_polygon(Q);
    // we must ensure cyclic indexing
    P.push_back(P[0]);
    P.push_back(P[1]);
    Q.push_back(Q[0]);
    Q.push_back(Q[1]);
    // main part
    vector<point> result;
    size_t i = 0, j = 0;
    while(i < P.size() - 2 || j < Q.size() - 2){
        result.push_back(P[i] + Q[j]);
        auto crossx = cross((P[i + 1] - P[i]), (Q[j + 1] - Q[j]));
        if(crossx >= 0)
            ++i;
        if(crossx <= 0)
            ++j;
    }
    return result;
}
vector<polygon> poly; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    poly.resize(n);
    for(int i = 0; i < n; i++){
        int sz;
        cin >> sz;
        poly[i].resize(sz);
        for(int j = 0; j < sz; j++) cin >> poly[i][j].x >> poly[i][j].y;
        reorder_polygon(poly[i]);
        for(auto p : poly[i]) cout << p << " ";
        cout << "\n";
    }
    polygon cur = minkowski(poly[0], poly[1]);
    reorder_polygon(cur);
    for(auto p: cur) cout << p << " ";
    cout << "\n";

    polygon cur1 = minkowski(poly[1], poly[2]);
    reorder_polygon(cur1);
    for(auto p: cur1) cout << p << " ";
    cout << "\n";

    polygon cur2 = minkowski(cur, poly[2]);
    reorder_polygon(cur2);
    for(auto p: cur2) cout << p << " ";
    cout << "\n";

    polygon tmp;
    for(auto p : cur) tmp.push_back(p * -1);
    reorder_polygon(tmp);
    for(auto p : tmp) cout << p << " ";
    cout << "\n";

    polygon cur3 = minkowski(tmp, cur2);
    reorder_polygon(cur3);
    for(auto p: cur3) cout << p << " ";
    cout << "\n";

    cur3 = minkowski(cur3, poly[1]);
    reorder_polygon(cur3);
    for(auto p: cur3) cout << p << " ";
    cout << "\n";
    return 0;
}