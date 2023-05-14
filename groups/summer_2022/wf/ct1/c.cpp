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

//const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1048576, K = 3e5 + 5;

int a, b, C = ~(1<<31), M = (1<<16)-1;
int r() {
  a = 36969 * (a & M) + (a >> 16);
  b = 18000 * (b & M) + (b >> 16);
  return (C & ((a << 16) + b)) % 1000000;
}

struct pt{
    int x, y, z;
    pt(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z){}
    bool operator < (const pt &p) const{
        return  x < p.x or
                (x == p.x and y < p.y) or
                (x == p.x and y == p.y and z < p.z);
    }
};

pt pts[K];

//segtree in y with map in z mapping max chain
map<int, int> st[2 * N];
int ans[K];

int query(int p, int l, int r, int y_i, int y_j, int z){
    if(y_j <= l or y_i >= r or st[p].empty()) return -INF;
    if(l >= y_i and r <= y_j){
        auto it = st[p].lower_bound(z);
        if(it != st[p].begin()){
            return (--it) -> second;
        }
        return -INF;
    }
    int mid = (l + r)/2;
    int x = query(2 * p, l, mid, y_i, y_j, z);
    int y = query(2 * p + 1, mid, r, y_i, y_j, z);
    return max(x, y);
}

void update(int p, int l, int r, int y_pos, int z_pos, int v){
    //look for z's bigger than the z_pos that have lesser value and erase then
    map<int, int> :: iterator it_low, it_hi;
    it_low = it_hi = st[p].upper_bound(z_pos);
    while(it_hi != st[p].end() and it_hi -> second <= v) it_hi++;
    st[p].erase(it_low, it_hi);

    //look for update
    it_low = st[p].upper_bound(z_pos);
    if(it_low == st[p].begin() or (--it_low) -> second < v) st[p][z_pos] = v;

    //propagate
    int mid = (l + r)/2;
    if(r - l == 1) return;
    if(y_pos < mid) update(2 * p, l, mid, y_pos, z_pos, v);
    else update(2 * p + 1, mid, r, y_pos, z_pos, v);
}

int main(){
    while(true){
        int m, n, mx = 0;
        scanf("%d%d%d%d", &m, &n, &a, &b);
        if(!m and !n and !a and !b) return 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &pts[i].x , &pts[i].y, &pts[i].z);
            mx = max(mx, pts[i].y + 1);
            ans[i] = 0;
        }
        for(int i = 0; i < n; i++){
            pts[i + m].x = r();
            pts[i + m].y = r();
            mx = max(mx, pts[i + m].y + 1);
            pts[i + m].z = r();
            ans[i + m] = 0;
        }
        n = (m + n);
        for(int i = 0; i < 2 * N; i++) st[i].clear();
        //ordered by x
        sort(pts, pts + n);
        int i = 0, j = 0;
        do{
            //query for segment with same x
            for(j = i; j < n and (pts[i].x == pts[j].x); j++){
                ans[j] = max(1, 1 + query(1, 0, mx, 0, pts[j].y, pts[j].z));
            }
            //update for segment with same x;
            for(; i < j; i++) update(1, 0 , mx, pts[i].y, pts[i].z, ans[i]);
        } while(i < n);
        printf("%d\n", query(1, 0, mx, 0, N - 1, N - 1));
    }
    return 0;
}