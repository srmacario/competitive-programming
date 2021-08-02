#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.), EPS2 = 1e-6;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

typedef long double type;
bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	point operator +(point other) const{
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const{
		return point(x - other.x, y - other.y);
	}
	point operator *(double k) const{
		return point(x*k, y*k);
	}
};

ostream &operator<<(ostream &os, const point &p) {
  os << "(" << p.x << "," << p.y << ")"; 
  return os;
}

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double inner(point p1, point p2) {
	return p1.x*p2.x + p1.y*p2.y;
}

double cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

point rotate(point p, double rad) {
	return point(p.x * cos(rad) - p.y * sin(rad),
	p.x * sin(rad) + p.y * cos(rad));
}

point closestToLineSegment(point p, point a, point b) {
	double u = inner(p-a, b-a) / inner(b-a, b-a);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return a + ((b-a)*u);
}

double distToLineSegment(point p, point a, point b) {
	return dist(p, closestToLineSegment(p, a, b));
}

/*
 * Circle 2D
 */

struct circle {
	point c;
	double r;
	circle() { c = point(); r = 0; }
	circle(point _c, double _r) : c(_c), r(_r) {}
	double area() { return acos(-1.0)*r*r; }
	double chord(double rad) { return  2*r*sin(rad/2.0); }
	double sector(double rad) { return 0.5*rad*area()/acos(-1.0); }
	bool intersects(circle other) {
		return dist(c, other.c) < r + other.r;
	}
	bool contains(point p) { return dist(c, p) <= r + EPS; }
	pair<point, point> getTangentPoint(point p) {
		double d1 = dist(p, c), theta = asin(r/d1);
		point p1 = rotate(c-p,-theta);
		point p2 = rotate(c-p,theta);
		p1 = p1*(sqrt(d1*d1-r*r)/d1)+p;
		p2 = p2*(sqrt(d1*d1-r*r)/d1)+p;
		return make_pair(p1,p2);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(10) << fixed;
    point p[2];
    circle crc;
    ld ans = INF;
    for(int i=0;i<2;i++) cin >> p[i].x >> p[i].y;
    cin >> crc.c.x >> crc.c.y >> crc.r;
    if(distToLineSegment(crc.c,p[0],p[1]) < crc.r){
      point tg[2][2];
      for(int i=0;i<2;i++){
        tg[i][0] = crc.getTangentPoint(p[i]).st, tg[i][1] = crc.getTangentPoint(p[i]).nd;
      }
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          ld partans = dist(p[0],tg[0][i]) + dist(p[1],tg[1][j]);
          ld angle = inner(tg[0][i]-crc.c,tg[1][j]-crc.c)/(sqrt(inner(tg[0][i]-crc.c,tg[0][i]-crc.c)) * sqrt(inner(tg[1][j]-crc.c,tg[1][j]-crc.c)));
          ld arc = acos(angle)*crc.r;
          partans += arc;
          ans = min(ans,partans);
        }
      }
    }
	else{
      ans = dist(p[0],p[1]);
    }
    cout << ans << "\n";
    return 0;
}