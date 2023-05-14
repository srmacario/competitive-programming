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

typedef long long type;

struct point{
    type x, y;
    
    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y);}
    point operator +(point p) { return point(x + p.x, y + p.y);}
    point operator -(point p) { return point(x - p.x, y - p.y);}

    point operator *(type k) { return point(k*x, k*y);}
    point operator /(type k) { return point(x/k, y/k);}

    type operator %(point p){ return x*p.y - y*p.x;}

    bool operator ==(const point &p) const { return x == p.x and y == p.y; }
    bool operator !=(const point &p) const { return x != p.x or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }

    // 0 => same direction
    // 1 => p is on the left
    //-1 => p is on the right
    int dir(point o, point p){
        type d = (*this - o) % (p - o);
        return (d >= 0) - (d <= 0);
    }

};

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

// below < above => order: [pi, 2 * pi + pi)

int n, pos_vis[2][N];
point src[2], vis[N], origin;
map<point, int> id;
vector<point> top[2], bot[2];

int above (point p){
    if (p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp (point p, point q){
    int tmp = above(q) - above(p);
    if (tmp) return tmp > 0;
    if(p.dir(origin, q) == 0) return p.y < q.y;
    return p.dir(origin, q) > 0;
}

void radial_sort(vector<point> &p, int i){
    if(p.empty()) return;

    origin = src[i];
    sort(p.begin(), p.end(), cmp);

    int cnt = 0;
    pos_vis[i][id[p[0]]] = cnt;
    for(int j = 1; j < p.size(); j++){
        if(p[j].dir(origin, p[j - 1])) ++cnt;
        pos_vis[i][id[p[j]]] = cnt;
    }
}

ll bit[N];

void add(int p, int v){
    for(p += 2; p < N; p += p & -p) bit[p] += v;
}

ll query(int p){
    ll r = 0;
    for(p += 2; p; p -= p & -p) r += bit[p];
    return r;
}

ll calc(vector<point> &o, int inv){
    if(o.empty()) return 0;
    origin = src[inv ^ 1];
    memset(bit, 0, sizeof(bit));
    ll ans = 0;
    for(int i = 0; i < o.size(); i++){
        ans += i - query(pos_vis[inv][id[o[i]]] - 1);
        if(!i or o[i].dir(origin, o[i - 1])) add(pos_vis[inv][id[o[i]]], 1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 2; i++)
        cin >> src[i].x >> src[i].y;
    cin >> n;
    if(src[1] < src[0]) swap(src[0], src[1]);
    for(int i = 0; i < n; i++){
        cin >> vis[i].x >> vis[i].y;
        id[vis[i]] = i;
        if(vis[i].dir(src[0], src[1]) > 0)
            for(int j = 0; j < 2; j++)
                bot[j].push_back(vis[i]);
        else
            for(int j = 0; j < 2; j++)
                top[j].push_back(vis[i]);
    }
    //sort radially respective to each source
    for(int i = 0; i < 2; i++){
        origin = src[i];
        radial_sort(top[i], i);
        radial_sort(bot[i], i);
    }
    ll ans = 0;
    ans += calc(top[0], 1);
    ans += calc(bot[1], 0);
    cout << ans << "\n";
    return 0;
}