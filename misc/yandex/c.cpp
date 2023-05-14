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
  point(type x, type y) : x(x), y(y) {}

  point operator -() { return point(-x, -y); }
  point operator +(point p) { return point(x+p.x, y+p.y); }
  point operator -(point p) { return point(x-p.x, y-p.y); }

  point operator *(type k) { return point(k*x, k*y); }
  point operator /(type k) { return point(x/k, y/k); }

  type operator *(point p) { return x*p.x + y*p.y; }
  type operator %(point p) { return x*p.y - y*p.x; }

  int dir(point o, point p) {
    type x = (*this - o) % (p - o);
    return ge(x,0) - le(x,0);
  }
};

int direction(point o, point p, point q) { return p.dir(o, q); }

vector <point> c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cnt = 0;
    cin >> n;
    point a(INF,INF),b(INF,INF);
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        if(!t){
            ld r,x,y;
            cin >> r >> x >> y;
            c.pb(point(x,y));
        }
        else{
            point md;
            for(int j=1;j<=4;j++){
                point tmp;
                cin >> tmp.x >> tmp.y;
                md.x += tmp.x;
                md.y += tmp.y;
            }
            c.pb(point((md.x)/4,(md.y)/4));
        }
        if(a.x == INF) a.x = c.back().x,a.y = c.back().y ;
        if(b.x == INF and a.x != c.back().x and a.y != c.back().y) b.x = c.back().x, b.y = c.back().y ;
    }
    bool ok = true;
    if(n > 2){
        for(int i=2;i<n;i++){
            if(direction(a,b,c[i])) ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
    return 0;
}