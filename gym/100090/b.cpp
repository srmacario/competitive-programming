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
const int N = 1e5+5;

typedef long long type;

struct point{
    type x, y;
    point() : x(0), y(0) {}
    point(type x, type y) : x(x), y(y){}

    point operator -(){return point(-x, -y);}
    point operator +(point p){return point(x + p.x, y + p.y);}
    point operator -(point p){return point(x - p.x, y - p.y);}

    type operator *(point p){return x*p.x + y*p.y;}
    type operator /(point p){return x*p.x - y*p.y;}
};

type ComputeSignedArea(const vector<point> &p, int l, int r){
    type area = 0;
    for(int i = l; i <= r; i++){
        int j = (i+1);
        if(i == r) j = l;
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return area;
}

int n;
vector<point> hull;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        hull.pb(point(x, y));
    }
    type tot = ComputeSignedArea(hull, 0, hull.size() - 1);
    
    int i = 0, j = 2;
    type area1 = ComputeSignedArea(hull, i, j);
    pair<type, pii> ans = {LINF, {INF, INF}};
    type last = LINF;
    while(j != n){
        if(j - i < 2){
            area1 -= hull[j].x * hull[i].y - hull[i].x * hull[j].y;
            j++;
            area1 += hull[j%n].x * hull[i].y - hull[i].x * hull[j%n].y;
            area1 += hull[j-1].x * hull[j%n].y - hull[j%n].x * hull[j-1].y;
            continue;
        }
        if(n - j + i < 2){
            area1 -= hull[i].x * hull[i+1].y - hull[i+1].x * hull[i].y;
            area1 -= hull[j].x * hull[i].y - hull[i].x * hull[j].y;
            i++;
            area1 += hull[j].x * hull[i].y - hull[i].x * hull[j].y;
            continue;
        }
        
        type area2 = tot - area1;
        
        type dif = abs(area2 - area1);
        
        ans = min(ans, {dif, {i, j}});
        if(area1 < area2){
            last = dif;
            area1 -= hull[j].x * hull[i].y - hull[i].x * hull[j].y;
            j++;
            //se j == n, j = 0
            area1 += hull[j%n].x * hull[i].y - hull[i].x * hull[j%n].y;
            area1 += hull[j-1].x * hull[j%n].y - hull[j%n].x * hull[j-1].y;
        }
        else{
            area1 -= hull[i].x * hull[i+1].y - hull[i+1].x * hull[i].y;
            area1 -= hull[j].x * hull[i].y - hull[i].x * hull[j].y;
            i++;
            area1 += hull[j].x * hull[i].y - hull[i].x * hull[j].y;
        }
    }

    printf("%d %d\n", ans.nd.st + 1, ans.nd.nd + 1);
    return 0;
}