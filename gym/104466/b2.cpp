#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
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

int n;

set<pll> good_pts;
pll pts[N];

void add_points(bool swapped){
    sort(pts, pts + n);
    pll l[2], r[2];
    l[0] = l[1] = pts[0];
    r[0] = r[1] = pts[n - 1];
    for(int i = 1; i < n; i++)
        if(l[0].x == pts[i].x) l[1] = pts[i];
    for(int i = n - 2; i >= 0; i--)
        if(r[1].x == pts[i].x) r[0] = pts[i];
    if(swapped){
        swap(l[0].x, l[0].y);
        swap(l[1].x, l[1].y);
        swap(r[0].x, r[0].y);
        swap(r[1].x, r[1].y);
    }
    good_pts.insert(l[0]);
    good_pts.insert(l[1]);
    good_pts.insert(r[0]);
    good_pts.insert(r[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    add_points(false);
    for(int i = 0; i < n; i++) swap(pts[i].x, pts[i].y);
    add_points(true);
    for(int i = 0; i < n; i++) swap(pts[i].x, pts[i].y);
    for(int )
    return 0;
}