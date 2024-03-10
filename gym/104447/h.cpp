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
const int N = 1e6+5, MX = 1e6+5;

typedef int type;
//for big coordinates change to long long

bool ge(type x, type y) { return x + EPS > y; }
bool le(type x, type y) { return x - EPS < y; }
bool eq(type x, type y) { return ge(x, y) and le(x, y); }
int sign(type x) { return ge(x, 0) - le(x, 0); }

struct point {
    type x, y;

    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -() { return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k) { return point(x*k, y*k); }
    point operator /(type k) { return point(x/k, y/k); }

    //inner product
    type operator *(point p) { return x*p.x + y*p.y; }
    //cross product
    type operator %(point p) { return x*p.y - y*p.x; }

    bool operator ==(const point &p) const{ return x == p.x and y == p.y; }
    bool operator !=(const point &p) const{ return x != p.x  or y != p.y; }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y); }
};

ostream &operator<<(ostream &os, const point &p) {
    os << "(" << p.x << "," << p.y << ")"; 
    return os;
}

int st[4*N], lazy[4*N];

void push(int p, int l, int r){
    if(lazy[p] != -1){
        st[p] = (r - l + 1) * lazy[p];
        if(l != r){
            lazy[2 * p] = lazy[p];
            lazy[2 * p + 1] = lazy[p];
        }
        lazy[p] = -1;
    }
}

void update(int p, int l, int r, int i, int j, int k){
    if(l > r) return;
    push(p, l, r);
    if(l > j or r < i) return;
    if(l >= i and r <= j){
        lazy[p] = k;
        push(p, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(2 * p, l, m, i, j, k);
    update(2 * p + 1, m + 1, r, i, j, k);
    st[p] = st[2 * p] + st[2 * p + 1];
}

int query(int p, int l, int r, int i, int j){
    push(p, l, r);
    if(l > j or r < i) return 0;
    if(l >= i and r <= j) return st[p];
    int m = (l + r) >> 1;
    int x = query(2 * p, l, m, i, j);
    int y = query(2 * p + 1, m + 1, r, i, j);
    return x + y;
}

int n, q, ans[N];
vector<point> pts, old_pts, queries;
map<point, point> hoz;
//{x, {type, id}}
vector<pair<int, pii>> sweep;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(lazy, -1, sizeof(lazy));
    cin >> n;
    old_pts.resize(n);
    for(int i = 0; i < n; i++){
        cin >> old_pts[i].x >> old_pts[i].y;
    }
    int curva = 0;
    for(int i = 0; i < n; i++){
        if( (old_pts[i].x != old_pts[(i - 1 + n) % n].x or old_pts[i].x != old_pts[(i + 1) % n].x) and 
            (old_pts[i].y != old_pts[(i - 1 + n) % n].y or old_pts[i].y != old_pts[(i + 1) % n].y)){
            curva = (i + 1) % n;
            break;
        }
    }
    rotate(old_pts.begin(), old_pts.begin() + curva, old_pts.end());
    pts.push_back(old_pts[0]), pts.push_back(old_pts[1]);

    for(int i = 2; i < n; i++){
        int pos1 = (int)pts.size() - 1, pos2 = (int)pts.size() - 2;
        if( (old_pts[i].x == pts[pos1].x and old_pts[i].x == pts[pos2].x) or
            (old_pts[i].y == pts[pos1].y and old_pts[i].y == pts[pos2].y)){
            pts[pos1] = old_pts[i];
        }
        else pts.push_back(old_pts[i]);
    }
    n = pts.size();

    for(int i = 0; i < n; i++){
        if(pts[i].x == pts[(i + 1) % n].x) sweep.push_back({pts[i].x, {-1, i}});
        if(pts[i].x < pts[(i + 1) % n].x) hoz[pts[i]] = pts[(i + 1) % n];
        if(pts[i].x > pts[(i + 1) % n].x) hoz[pts[(i + 1) % n]] = pts[i];
    }
    sort(sweep.begin(), sweep.end());
    for(int i = 0; i < (int)sweep.size(); i++){
        pair<int, pii> s = sweep[i];
        int l = pts[s.nd.nd].y, r = pts[(s.nd.nd + 1) % n].y;
        point pl = pts[s.nd.nd], pr = pts[(s.nd.nd + 1) % n];
        if(l > r) swap(l, r), swap(pl, pr);
        if(query(1, 0, MX, l, r) == (r - l + 1)) sweep[i].nd.st = 1;
        if(sweep[i].nd.st == -1){
            update(1, 0, MX, l, r, 1);
        }
        else{
            if(hoz.count(pl)) l++;
            if(hoz.count(pr)) r--;
            update(1, 0, MX, l, r, 0);
        }
    }
    cin >> q;
    queries.resize(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].x >> queries[i].y;
        sweep.push_back({queries[i].x, {0, i}});
    }
    sort(sweep.begin(), sweep.end());
    for(auto s : sweep){
        if(s.nd.st){
            int l = pts[s.nd.nd].y, r = pts[(s.nd.nd + 1) % n].y;
            point pl = pts[s.nd.nd], pr = pts[(s.nd.nd + 1) % n];
            if(l > r) swap(l, r), swap(pl, pr);
            if(s.nd.st == -1){
                update(1, 0, MX, l, r, 1);
            }
            else{
                if(hoz.count(pl)) l++;
                if(hoz.count(pr)) r--;
                update(1, 0, MX, l, r, 0);
            }
            continue;
        }
        ans[s.nd.nd] = query(1, 0, MX, queries[s.nd.nd].y, queries[s.nd.nd].y);
    }
    for(int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << "\n";
}