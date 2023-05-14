#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

typedef long long type;

struct point{
    type x, y;
    point() : x(0), y(0) {}
    point(type _x, type _y) : x(_x), y(_y) {}

    point operator -(){ return point(-x, -y); }
    point operator +(point p) { return point(x + p.x, y + p.y); }
    point operator -(point p) { return point(x - p.x, y - p.y); }

    point operator *(type k){ return point(k*x, k*y); }
    point operator /(type k){ return point(x/k, y/k); }

    type operator *(point p){ return x*p.x + y*p.y; }
    type operator %(point p){ return x*p.y - y*p.x; }

    bool operator ==(const point &p) const { return (x == p.x and y == p.y); }
    bool operator !=(const point &p) const { return (x != p.x or y != p.y); }
    bool operator <(const point &p) const { return (x < p.x) or (x == p.x and y < p.y) ; }

    int dir(point o, point p){
        type d = (*this - o) % (p - o);
        return (d >= 0) - (d <= 0);
    }
};

point rotate_cw90(point p) { return point(p.y, -p.x); }

ostream &operator<<(ostream &os, const point &p){
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

point origin;

int is_above(point p){
    if(p.y == origin.y) return p.x > origin.x;
    return p.y > origin.y;
}

bool cmp(pair<point, pii> a, pair<point, pii> b){
    point p = a.st, q = b.st;
    int tmp = is_above(q) - is_above(p);
    if(tmp) return tmp > 0;
    return p.dir(origin, q) > 0;
}

int n, m;
point c[N], s[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string sx, sy;
        cin >> sx >> sy;
        while(sx.size() < 8) sx.push_back('0');
        while(sy.size() < 8) sy.push_back('0');
        c[i].x = stoi(sx.substr(2, 6));
        c[i].y = stoi(sy.substr(2, 6));
    }
    for(int i = 0; i < m; i++){
        string sx, sy;
        cin >> sx >> sy;
        while(sx.size() < 8) sx.push_back('0');
        while(sy.size() < 8) sy.push_back('0');
        s[i].x = stoi(sx.substr(2, 6));
        s[i].y = stoi(sy.substr(2, 6));
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        origin = s[i];
        int above[2] = {0}, below[2] = {0};
        vector<pair<point, pii>> pts;
        for(int j = 0; j < m; j++) if(i != j) pts.push_back({s[j], {0, 1}}), below[0]++;
        for(int j = 0; j < n; j++) pts.push_back({c[j], {1, 1}}), below[1]++;
        for(auto& p : pts){
            if(is_above(p.st)){
                above[p.nd.st]++, below[p.nd.st]--;
                p.st = rotate_cw90(rotate_cw90(p.st - origin)) + origin;
                p.nd.nd = -1;
            }
        }
        sort(pts.begin(), pts.end(), cmp);
        if(!below[0]) ans = max(ans, below[1]);
        if(!above[0]) ans = max(ans, above[1]);

        for(int j = 0; j < (int) pts.size(); j++){
            above[pts[j].nd.st] += pts[j].nd.nd;
            below[pts[j].nd.st] -= pts[j].nd.nd;

            while(j + 1 < (int) pts.size() and !pts[j + 1].st.dir(origin, pts[j].st)){
                j++;
                above[pts[j].nd.st] += pts[j].nd.nd;
                below[pts[j].nd.st] -= pts[j].nd.nd;
            }
                        
            if(!below[0]) ans = max(ans, below[1]);
            if(!above[0]) ans = max(ans, above[1]);
        }
    }
    cout << ans << "\n";
    return 0;
}