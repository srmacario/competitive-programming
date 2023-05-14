#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef double ld;
typedef pair<short int, short int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5, M = 2e2 + 5;

typedef double type;

struct point {
    type x, y;

    point() : x(0), y(0) {}

    point(type x, type y) : x(x), y(y) {}

    point operator -() { return point(-x, -y);}
    point operator +(point p) {return point (x + p.x, y + p.y);}
    point operator -(point p) {return point (x - p.x, y - p.y);}
    
    point operator *(type k) {return point (k*x, k*y);}
    point operator /(type k) {return point (x/k, y/k);}

    type operator *(point p) {return x * p.x + y * p.y;}
    type operator %(point p) {return x * p.y - y * p.x;}

    bool operator == (const point& p) const{ return x == p.x and y == p.y;}
    bool operator != (const point& p) const{ return x != p.x or y != p.y;}
    bool operator <(const point &p) const{ return (x < p.x) or (x == p.x and y < p.y);}

    int dir(point o, point p){
        type x = (*this - o) % (p - o);
        return (x >= 0) - (x <= 0);
    }

    ld abs() {return sqrt( x*x + y*y);}
    type abs2(){ return x * x + y * y;}
    ld dist(point q){ return (*this - q).abs();}
    type dist2(point q){ return (*this - q).abs2();}

};

type dot(point p, point q) {return p.x*q.x + p.y*q.y;}
type cross(point p, point q) {return p.x*q.y - p.y*q.x;}

int angle_less(const point& a1, const point& b1, const point& a2, const point& b2){
    //angle between (a1 and b1) vs angle between(a2 and b2)
    //1 : bigger
    //-1 : smaller
    //0 : equal

    point p1(dot(   a1, b1), abs(cross( a1, b1)));
    point p2(dot(   a2, b2), abs(cross( a2, b2)));
    if(cross(p1, p2) < 0) return 1;
    if(cross(p1, p2) > 0) return -1;
    return 0;
}

bool le_angle(pair<point, point> a, pair<point, point> b){
    return angle_less(a.st, a.nd, b.st, b.nd) >= 0;
}

ostream &operator <<(ostream &os, const point &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

point pts[M];
vector<pair<pii, int>> edge;
vector<int> out_adj[M], in_adj[M];

int J, R;
ll D;
ld dist[M][M];

bool cmp(pair<pii, short int> p, pair<pii, short int> q){
    pair<point, point> a = {pts[p.st.st] - pts[p.nd], pts[p.st.nd] - pts[p.nd]};
    pair<point, point> b = {pts[q.st.st] - pts[q.nd], pts[q.st.nd] - pts[q.nd]};
    return (angle_less(a.st, a.nd, b.st, b.nd) == -1);
}

bool dijkstra(pair<point, point> comp_angle){
    for(int i = 0; i < M; i++) for(int j = 0; j < M; j++) dist[i][j] = LINF;
    for(int i = 0; i < M; i++) dist[i][i] = 0;
    priority_queue<pair<ld, pii>> pq;
    pq.push({0, {0, 1}});

    while(pq.size()){
        pair<ld, pii> u = pq.top();
        pq.pop();
        u.st = -u.st;
        if(u.st > dist[u.nd.st][u.nd.nd]) continue;

        for(auto v : out_adj[u.nd.nd]){
            ld w = pts[u.nd.nd].dist(pts[v]);
            if(u.nd.st == 0){
                dist[u.nd.nd][v] = w;
                pq.push({-dist[u.nd.nd][v], {u.nd.nd, v}});
            }
            else{
                pair<point, point> cur_angle = {pts[u.nd.st] - pts[u.nd.nd], pts[v] - pts[u.nd.nd]};
                if(le_angle(cur_angle, comp_angle) and dist[u.nd.st][u.nd.nd] + w < dist[u.nd.nd][v]){
                    dist[u.nd.nd][v] = dist[u.nd.st][u.nd.nd] + w;
                    pq.push({-dist[u.nd.nd][v], {u.nd.nd, v}});
                }
            }
        }
    }
    ld ans = LINF;
    for(int i = 1; i < J; i++){
        if(dist[i][J] <= D) ans = min(ans, dist[i][J]);
    }
    if(ans <= D) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> J >> R >> D;
    for(int i = 1; i <= J; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    for(int i = 0; i < R; i++){
        int u, v;
        cin >> u >> v;
        out_adj[u].push_back(v);
        in_adj[v].push_back(u);
    }
    for(int u = 1; u <= J; u++){
        for(int j = 0; j < in_adj[u].size(); j++){
            point a = pts[in_adj[u][j]];
            for(int k = 0; k < out_adj[u].size(); k++){
                point b = pts[out_adj[u][k]];
                if(a == b) continue;
                edge.push_back({{in_adj[u][j], out_adj[u][k]}, u});
            }
        }
    }
    pts[J + 1] = {1, 0};
    edge.push_back({{J + 1, J + 1}, 0});
    sort(edge.begin(), edge.end(), cmp);
    //bin search
    int l = 0, r = (int) edge.size() - 1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        pair<point, point> comp_angle = {pts[edge[mid].st.st] - pts[edge[mid].nd], pts[edge[mid].st.nd] - pts[edge[mid].nd]};
        if(dijkstra(comp_angle)) l = mid;
        else r = mid - 1;
    }
    pair<point, point> comp_angle = {pts[edge[l].st.st] - pts[edge[l].nd], pts[edge[l].st.nd] - pts[edge[l].nd]};
    if(!dijkstra(comp_angle)){
        cout << "Impossible\n";
        return 0;
    }
    point p = pts[edge[l].st.st] - pts[edge[l].nd], q = pts[edge[l].st.nd] - pts[edge[l].nd];
    ld angle = acos( (ld) dot(p, q) / (p.abs() * q.abs()));
    if(l == 0) angle = PI;
    cout << setprecision(15) << fixed << ((PI - angle) * (180 / PI)) << "\n";
    return 0;
}