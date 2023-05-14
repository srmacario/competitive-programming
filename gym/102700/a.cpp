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

const ld EPS = 1e-7, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e6, M = 200;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

struct point{
    ld x, y;
    point() : x(0), y(0){}
    point(ld x, ld y) : x(x), y(y){}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x+p.x, y+p.y); }
    point operator -(point p) { return point(x-p.x, y-p.y); }

    point operator *(ld k) { return point(k*x, k*y); }
    point operator /(ld k) { return point(x/k, y/k); }

    ld operator *(point p) { return x*p.x + y*p.y; }
    ld operator %(point p) { return x*p.y - y*p.x; }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    if((b-a)*(b-a) - (d-c)*(d-c) > EPS){
        swap(a,c), swap(d,b);
    }
    point u = (b - a) / sqrt((b-a)*(b-a));
    point v = (d - c) / sqrt((d-c)*(d-c));
    ld t1, t2, dist1 = (a-c)*(a-c), dist2;
    if((v-u)*(v-u) > EPS){
        t1 = -((c-a)*(v-u)) / ((v-u)*(v-u));
        if(t1 < 0) t1 = 0;
        if(t1*t1 > (b-a)*(b-a)) t1 = sqrt((b-a)*(b-a));
        dist1 = (c-a + (v-u)*t1)*(c-a + (v-u)*t1);
    }
    ld tfinal2 = (b-a)*(b-a);
    c = c + v*(sqrt(tfinal2));
    t2 = (b-c)*v/(v*v);
    if(t2 < 0) t2 = 0;
    if(t2*t2 > (d-c)*(d-c)) t2 = sqrt((d-c)*(d-c));
    dist2 = (b-c - (v)*t2)*(b-c - (v)*t2);
    cout << fixed << setprecision(10) << sqrt(min((dist1),(dist2))) << "\n";
    return 0;
}