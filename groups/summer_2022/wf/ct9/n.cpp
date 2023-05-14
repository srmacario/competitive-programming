#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

typedef long long type;

struct point {
    type x, y;
    point() : x(0), y(0){}
    point(type x, type y) : x(x), y(y){}

    point operator -(){ return point(-x, -y);}
    point operator +(point p){return point(x + p.x, y + p.y);}
    point operator -(point p){return point(x - p.x, y - p.y);}
    type operator %(point p){return x*p.y - y*p.x;}

    bool operator ==(const point &p) const {return x == p.x and y == p.y;}
    bool operator !=(const point &p) const {return x != p.x or y != p.y;}
    bool operator <(const point &p) const {return x < p.x or (x == p.x and y < p.y);}

    bool on_seg(point p, point q){
        if(this->dir(p, q)) return 0;
        return (x >= min(p.x, q.x)) and (x <= max(p.x, q.x)) and (y >= min(p.y, q.y)) and (y <= max(p.y, q.y));
    }
    type abs2(){return x*x + y*y;}
    type dist2(point q){return (*this - q).abs2();}
    int dir(point o, point p){
        type x = (*this - o) % (p - o);
        return (x >= 0) - (x <= 0);
    }
};

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

int direction(point o, point p, point q){return p.dir(o, q);}

bool SegmentSegmentIntersect(point a, point b, point c, point d){
    if(a == c || a == d ||
        b == c || b == d) return true;
    int d1, d2, d3, d4;
    d1 = direction(a, b, c);
    d2 = direction(a, b, d);
    d3 = direction(c, d, a);
    d4 = direction(c, d, b);
    if(d1 * d2 < 0 and d3 * d4 < 0) return 1;
    return a.on_seg(c, d) or b.on_seg(c, d) or
            c.on_seg(a, b) or d.on_seg(a, b);
}

void sort_lex_hull(vector<point> &hull){
    int n = hull.size();

    int pos = 0;
    for(int i = 1; i < n; i++) if(hull[i] < hull[pos]) pos = i;
    rotate(hull.begin(), hull.begin() + pos, hull.end());
}

struct lower_hull{
    point ini, fim;
    int id_ini, id_fim;
    lower_hull(point ini = point(LINF, LINF), point fim = point(-LINF, -LINF)) : ini(ini), fim(fim){
        id_ini = id_fim = -1;
    }
};

//shamos hoey

struct edge{
    point ini, fim;
    edge(point ini = point(0, 0), point fim = point(0, 0)) : ini(ini), fim(fim){}
};

bool operator < (const edge& a, const edge& b){
    if(a.ini == b.ini) return direction(a.ini, a.fim, b.fim) < 0;
    if(a.ini.x < b.ini.x) return direction(a.ini, a.fim, b.ini) < 0;
    return direction(a.ini, b.fim, b.ini) < 0;
}

int p[N];
vector<int> par_upd[N], adj[N];
set<int> paired;
vector <pair<point, piii>> eve;
vector <pair<edge, pii>> edgs[N];
set <pair<edge, pii>> sweep;
pair<point, int> end_hull[N];
lower_hull low[N];

bool is_simple_polygon(const vector<vector<point>> &pts){
    int n = (int)pts.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            point l = min(pts[i][j], pts[i][(j + 1)%3]);
            point r = max(pts[i][j], pts[i][(j + 1)%3]);
            eve.pb({l, {0, {i, j}}});
            eve.pb({r, {1, {i, j}}});
            edgs[i].pb(make_pair(edge(l, r), make_pair(i, j)));
        }
    }
    sort(eve.begin(), eve.end());
    for(auto e : eve){
        if(!e.nd.st){
            auto cur = sweep.lower_bound(edgs[e.nd.nd.st][e.nd.nd.nd]);
            pair<edge, pii> above, below;
            above = *cur;
            if(cur != sweep.end()){
                above = *cur;
                if((above.nd.st != e.nd.nd.st) and SegmentSegmentIntersect(pts[above.nd.st][above.nd.nd], pts[above.nd.st][(above.nd.nd + 1)%3], pts[e.nd.nd.st][e.nd.nd.nd], pts[e.nd.nd.st][(e.nd.nd.nd + 1)%3]))
                    return false;
            }
            if(cur != sweep.begin()){
                below = *(--cur);
                if((below.nd.st != e.nd.nd.st) and SegmentSegmentIntersect(pts[below.nd.st][below.nd.nd], pts[below.nd.st][(below.nd.nd + 1)%3], pts[e.nd.nd.st][e.nd.nd.nd], pts[e.nd.nd.st][(e.nd.nd.nd + 1)%3]))
                    return false;
            }
            sweep.insert(edgs[e.nd.nd.st][e.nd.nd.nd]);
        }
        else{
            auto above = sweep.upper_bound(edgs[e.nd.nd.st][e.nd.nd.nd]);
            auto cur = above, below = --cur;
            if(above != sweep.end() and below != sweep.begin()){
                --below;
                if((above->nd.st != below->nd.st) and SegmentSegmentIntersect(pts[above->nd.st][above->nd.nd], pts[above->nd.st][(above->nd.nd + 1)%3], pts[below->nd.st][below->nd.nd], pts[below->nd.st][(below->nd.nd + 1)%3]))
                    return false;
            }
            below = cur;
            if(below != sweep.begin() and end_hull[e.nd.nd.st].nd == e.nd.nd.nd){
                --below;
                //0 -> low_id_fim
                //o pai desse triangulo é o pai do triangulo de cima
                if(below->nd.nd < low[below->nd.st].id_fim){
                    par_upd[below->nd.st].pb(e.nd.nd.st);
                }
                //esse triangulo, é pai do debaixo, pois ele esta dentro do upper hull
                else{
                    p[e.nd.nd.st] = below->nd.st;
                    paired.insert(e.nd.nd.st);
                }
            }
            sweep.erase(cur);
        }
    }
    return true;
}

int dist[N];

void bfs(int s){
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    while(true){
        int n;
        cin >> n;
        cnt++;
        if(n == -1) return 0;
        vector<vector<point>> pts(n);
        //memset(low, 0, sizeof(low));
        eve.clear();
        sweep.clear();
        paired.clear();
        adj[n].clear();
        for(int i = 0; i < n; i++){
            p[i] = -1;
            par_upd[i].clear();
            edgs[i].clear();
            pts[i].resize(3);
            adj[i].clear();
            for(int j = 0; j < 3; j++){
                cin >> pts[i][j].x >> pts[i][j].y;
            }
            sort_lex_hull(pts[i]);
            if(pts[i][1].dir(pts[i][0], pts[i][2]) == -1) swap(pts[i][1], pts[i][2]);
            low[i].ini = low[i].fim = pts[i][0];
            low[i].id_ini = low[i].id_fim = 0;
            end_hull[i] = {point(-LINF, -LINF), -1};
            for(int j = 0; j < 3; j++){
                point u = pts[i][j];
                if((u.x > low[i].fim.x) or (u.x == low[i].fim.x and u.y < low[i].fim.y)) low[i].fim = u, low[i].id_fim = j;
                end_hull[i] = max(end_hull[i], {u, j});
            }
        }
        if(!is_simple_polygon(pts)){
            cout << "Case " << cnt << ": ERROR\n";
            continue;
        }
        while(!paired.empty()){
            auto cur = paired.begin();
            for(auto v : par_upd[*cur]){
                p[v] = p[*cur];
                paired.insert(v);
            }
            par_upd[*cur].clear();
            paired.erase(cur);
        }
        for(int i = 0; i < n; i++){
            dist[i] = INF;
            if(p[i] != -1){
                adj[p[i]].pb(i);
            }
            else{
                adj[n].pb(i);
            }
        }
        dist[n] = 0;
        bfs(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dist[i] != INF){
                ans = max(dist[i], ans);
            }
        }
        cout << "Case " << cnt << ": " << ans + 1 << " shades\n";
    }
    return 0;
}