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
const int N = 2e6+5;

struct point{
    int x, y;
    point() : x(0), y(0) {}
    point(int xx, int yy) : x(xx), y(yy) {}
};

struct cmp_by_x{
    bool operator() (const point& lhs, const point& rhs) const{
        if(lhs.x == rhs.x) return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    }
};

struct cmp_by_y{
    bool operator() (const point& lhs, const point& rhs) const{
        if(lhs.y == rhs.y) return lhs.x < rhs.x;
        return lhs.y < rhs.y;
    }
};

bool greater_x(point a, point b){
    if(a.x == b.x) return a.y < b.y;
    return a.x > b.x;
}

bool greater_y(point a, point b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

int n, a, b;
point pts[N];
int bit[N];

void add (int p, int v) {
    for (p+=2; p<N; p += p&-p) bit[p] += v;
}

int query (int p) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r += bit[p];
    return r;
}

int rangesum (int a, int b) {
    return query(b)-(a ? query(a-1) : 0);
}

bool calc(int L){
    //sweep right to left
        memset(bit, 0, sizeof(bit));
        //y, x, v
        vector<piii> upd_query;
        set<point, cmp_by_y> cur;
        queue<point> rem;
        //insert dummy points to represent borders
        cur.insert({a, 0}), cur.insert({a, b});
        //sort points by greater x
        sort(pts, pts + n, greater_x);
        vector<point> ins;
        for(int i = 0; i < n; i++){
            if(i and pts[i].x != pts[i - 1].x){
                while(ins.size()){
                    rem.push(ins.back());
                    cur.insert(ins.back());
                    ins.pop_back();
                }
            }
            //erase points far than L
            while(!rem.empty() and (rem.front().x - pts[i].x) >= L) cur.erase(rem.front()), rem.pop();
            //pick point from below and above
            auto below = cur.lower_bound(pts[i]);
            if(below -> y == pts[i].y or (a - pts[i].x) < L){
                ins.push_back(pts[i]);
                continue;
            }
            below--;
            auto above = cur.upper_bound(pts[i]);
            if(above -> y - below -> y >= 2 * L){
                //do something to mark
                upd_query.push_back({below -> y - 1, {pts[i].x, -1}});
                upd_query.push_back({above -> y - 2 * L, {pts[i].x, 1}});
                // db(L _ pts[i].x _ above -> y _ below -> y);
                // return true;
            }
            ins.push_back(pts[i]);
        }
        //process border left
        while(ins.size()){
            rem.push(ins.back());
            cur.insert(ins.back());
            ins.pop_back();
        }
        while(!rem.empty() and (rem.front().x - 0) >= L) cur.erase(rem.front()), rem.pop();
        while(cur.size() > 1){
            auto above = cur.begin();
            auto below = above++;
            if(above -> y - below -> y >= 2 * L){
                //do something to mark
                upd_query.push_back({below -> y - 1, {0, -1}});
                upd_query.push_back({above -> y - 2 * L, {0, 1}});
            }
            cur.erase(below);
        }
    ins.clear();
    sort(upd_query.begin(), upd_query.end());
    //sweep top to bottom
        set<point, cmp_by_x> cur_2;
        queue<point> rem_2;
        //insert dummy points to represent borders
        cur_2.insert({0, b}), cur_2.insert({a, b});
        //sort points by greater y
        sort(pts, pts + n, greater_y);
        for(int i = 0; i < n; i++){
            //erase points far than L
            if(i and pts[i].y != pts[i - 1].y){
                while(ins.size()){
                    rem_2.push(ins.back());
                    cur_2.insert(ins.back());
                    ins.pop_back();
                }
            }
            while(!rem_2.empty() and (rem_2.front().y - pts[i].y) >= L) cur_2.erase(rem_2.front()), rem_2.pop();
            //pick point from above and below
            auto below = cur_2.lower_bound(pts[i]);
            if(below -> x == pts[i].x and (b - pts[i].y) < L){
                ins.push_back(pts[i]);
                continue;
            }
            below--;
            auto above = cur_2.upper_bound(pts[i]);
            if(above -> x - below -> x >= 2 * L){
                //do something to check
                while(upd_query.size() and upd_query.back().st >= pts[i].y){
                    int pos = upd_query.back().nd.st;
                    int v = upd_query.back().nd.nd;
                    add(pos, v);
                    upd_query.pop_back();
                }
                if(rangesum(below -> x, above -> x - 2 * L)) return true;
            }
            ins.push_back(pts[i]);
        }
        //process bottom border
        while(ins.size()){
            rem_2.push(ins.back());
            cur_2.insert(ins.back());
            ins.pop_back();
        }
        while(!rem_2.empty() and (rem_2.front().y - 0) >= L) cur_2.erase(rem_2.front()), rem_2.pop();
        while(cur_2.size() > 1){
            auto above = cur_2.begin();
            auto below = above++;
            if(above -> x - below -> x >= 2 * L){
                //do something to check
                while(upd_query.size() and upd_query.back().st >= 0){
                    int pos = upd_query.back().nd.st;
                    int v = upd_query.back().nd.nd;
                    add(pos, v);
                    upd_query.pop_back();
                }
                if(rangesum(below -> x, above -> x - 2 * L)) return true;
            }
            cur_2.erase(below);
        }
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        cin >> n >> a >> b;
        if(!n and !a and !b) return 0;
        for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
        for(int i = 0; i < n; i++) pts[i].x *= 2, pts[i].y *= 2;
        a *= 2, b *= 2;
        
        //binary search answer
        int l = 0, r = max(a, b);
        while(l < r){
            int m = (l + r + 1)/2;
            if(calc(m)) l = m;
            else r = m - 1;
        }
        // db(calc(4));
        ll ans = 1ll * l * l;
        if(ans % 4 == 0){
            cout << 3 * (ans / 4) << ".";
            cout << "00\n";
        }
        if(ans % 4 == 1){
            cout << 3 * (ans / 4) << ".";
            cout << "75\n";
        }
        if(ans % 4 == 2){
            cout << 3 * (ans / 4) + 1 << ".";
            cout << "50\n";
        }
        if(ans % 4 == 3){
            cout << 3 * (ans / 4) + 2 << ".";
            cout << "25\n";
        }
    }
    return 0;
}