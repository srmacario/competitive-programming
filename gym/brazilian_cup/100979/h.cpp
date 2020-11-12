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

  bool on_seg(point p, point q) {
    if (this->dir(p, q)) return 0;
    return ge(x, min(p.x, q.x)) and le(x, max(p.x, q.x)) and
           ge(y, min(p.y, q.y)) and le(y, max(p.y, q.y));
  }

  ld abs() { return sqrt(x*x + y*y); }
  type abs2() { return x*x + y*y; }
  ld dist(point x) { return (*this - x).abs(); }
  type dist2(point x) { return (*this - x).abs2(); }
  };

int direction(point o, point p, point q) { return p.dir(o, q); }

bool segments_intersect(point p, point q, point a, point b) {
  int d1, d2, d3, d4;
  d1 = direction(p, q, a);
  d2 = direction(p, q, b);
  d3 = direction(a, b, p);
  d4 = direction(a, b, q);
  if (d1*d2 < 0 and d3*d4 < 0) return 1;
  return p.on_seg(a, b) or q.on_seg(a, b) or
         a.on_seg(p, q) or b.on_seg(p, q);
}

int n;
point src, snk;
vector <pair<point,point>> lines;
vector <point> p;
vector <pair<int,ld>> adj[N];
ld dist[N];
int par[N];
priority_queue<pair<int,ld>> pq;

void dijkstra (int s) {
    for(int i=0;i<=2*n+1;i++) dist[i] = LINF;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ld ud = -pq.top().st;
        int u = pq.top().nd; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.st;
            ld w = x.nd;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> src.x >> src.y >> snk.x >> snk.y >> n;
    p.pb(src);
    for(int i=0;i<n;i++){
        point a,b;
        cin >> a.x >> a.y >> b.x >> b.y;
        lines.pb({a,b});
        p.pb(a), p.pb(b);
    }
    p.pb(snk);
    for(int i=0;i<p.size();i++){
        for(int j=i+1;j<p.size();j++){
            ld distance;
            bool ok = false;
            for(int k=0;k<lines.size();k++){
                if(i and j == i+1){
                    ok = true;
                    break;
                }
                if(p[i].x == lines[k].st.x and p[i].y == lines[k].st.y){
                    continue;
                }
                if(p[j].x == lines[k].st.x and p[j].y == lines[k].st.y){
                    continue;
                }
                if(p[i].x == lines[k].nd.x and p[i].y == lines[k].nd.y){
                    continue;
                }
                if(p[j].x == lines[k].nd.x and p[j].y == lines[k].nd.y){
                    continue;
                }
                if(segments_intersect(p[i],p[j],lines[k].st, lines[k].nd)){
                    ok = true;
                    break;
                }
            }
            if(ok) distance = LINF;
            else distance = p[i].dist(p[j]);
            adj[i].pb({j,distance});
            adj[j].pb({i,distance});
        }
    }
    dijkstra(0);
    cout << setprecision(2) << fixed << dist[2*n+1] << "\n";
    return 0;
}