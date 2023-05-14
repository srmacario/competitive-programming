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
const int N = 1e5+5, M = 3e5+5;

typedef long long type;

struct point{
    type x, y;
    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(x*k, y*k); }
    point operator /(type k) { return point(x/k, y/k); }

    type operator *(point p) { return x*p.x + y*p.y; }
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x or y != p.y; }
    bool operator <(const point &p) const{ return x < p.x or (x == p.x and y < p.y); }

    int dir(point o, point p){
        type d = (*this - o) % (p - o);
        return (d >= 0) - (d <= 0);
    }

    bool on_seg(point p, point q){
        if(this->dir(p, q)) return 0;
        return (x >= min(p.x, q.x)) and (x <= max(p.x, q.x)) and (y >= min(p.y, q.y)) and (y <= max(p.y, q.y));
    }
};

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

type dot(point p, point q) { return p.x * q.x + p.y * q.y;}
type cross(point p, point q) { return p.x * q.y - p.y * q.x;}

int n, sz[N], p[M], last[M], root[M];
point origin;
vector<point> pts[N];
map<int, vector<int>> m;

int above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(point p, point q){
    int tmp = above(q) - above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin,q) > 0;
    //Be Careful: p.dir(origin,q) == 0
}

struct edge{
    point l, r;
    edge(point _l = point(), point _r = point()) : l(_l), r(_r) {}

    bool operator <(const edge& p) const{
        point u = p.r, v = r;
        return cmp(v - l, u - p.l);
    }
    //actually this operator is checking >= not ==
    bool operator ==(const edge& p) const{
        point u = p.r, v = r;
        return cmp(v - l, u - p.l) == 0;
    }
};
vector<edge> edges;
map<edge, int> id;

vector<int> e, d, sum;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

int update(int pos, int ini, int fim, int id, int val){
    int novo = create();
    
    sum[novo] = sum[pos];
    e[novo] = e[pos];
    d[novo] = d[pos];
    pos = novo;

    if(ini == fim){
        sum[pos] = val;
        return novo;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        int aux = update(e[pos], ini, m, id, val);
        e[pos] = aux;
    }
    else{
        int aux = update(d[pos], m + 1, fim, id, val);
        d[pos] = aux;
    }

    sum[pos] = sum[e[pos]] + sum[d[pos]];
    return pos;
}

int query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return 0;

    if(pos == 0) return 0;

    if(p <= ini and fim <= q) return sum[pos];
    
    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, p, q) + query(d[pos], m + 1, fim, p, q);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        pts[i].resize(k);
        sz[i] = sz[i - 1] + k;
        for(int j = 0; j < k; j++) cin >> pts[i][j].x >> pts[i][j].y;
        for(int j = 0; j < k; j++) edges.push_back({pts[i][j], pts[i][(j + 1) % k]});
    }
    sort(edges.begin(), edges.end());
    edges.resize(unique(edges.begin(), edges.end()) - edges.begin());
    for(int i = 0; i < edges.size(); i++) id[edges[i]] = i + 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < pts[i].size(); j++){
            int idp = id[{pts[i][j], pts[i][(j + 1) % pts[i].size()]}];
            p[sz[i - 1] + j + 1] = last[idp];
            last[idp] = sz[i - 1] + j + 1;
            m[p[sz[i - 1] + j + 1]].push_back(sz[i - 1] + j + 1);
        }
    }
    create();
    int r = 0;
    for(int i = 0; i < M; i++){
        if(m.count(i)){
            for(auto pos : m[i]){
                r = update(r, 1, M, pos, 1);
            }
        }
        root[i] = r;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << query(root[sz[l - 1]], 1, M, sz[l - 1] + 1, sz[r]) << "\n";
    }
    return 0;
}