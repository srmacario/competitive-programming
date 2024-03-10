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

int n;

bool between(const point &a, const point &b, const point &c){
    return (abs(area_2(a, b, c)) <= 0 and (a.x - b.x) * (c.x - b.x)
}

void monotone_hull(vector<point> &pts){
    sort(pts.begin(), pts.end());
    vector<point> up, dn;
    for(int i = 0; i < pts.size(); i++){
        while(up.size() > 1 and area_2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while(dn.size() > 1 and area_2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for(int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}