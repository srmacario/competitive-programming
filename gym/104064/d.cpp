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
typedef pair<int,int> point;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n;

point pts[N], u[2], d[2], l[2], r[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y;
        if(!i){
            u[0] = u[1] = d[0] = d[1] = l[0] = l[1] = r[0] = r[1] = pts[i];
        }
        //upd u
        if(pts[i].y == u[0].y){
            u[0] = min(pts[i], u[0]);
            u[1] = max(pts[i], u[1]);
        }
        else{
            u[0] = max(pts[i], u[0]);
            u[1] = max(pts[i], u[1]);
        }
        //upd d
        if(pts[i].y == d[0].y){
            d[0] = min(pts[i], d[0]);
            d[1] = max(pts[i], d[1]);
        }
        else{
            d[0] = min(pts[i], d[0]);
            d[1] = min(pts[i], d[1]);
        }
        //upd l
        if(pts[i].x == l[0].x){
            l[0] = min(pts[i], l[0]);
            l[1] = max(pts[i], l[1]);
        }
        else{
            l[0] = min(pts[i], l[0]);
            l[1] = min(pts[i], l[1]);
        }
        //upd r
        if(pts[i].x == u[0].x){
            r[0] = min(pts[i], r[0]);
            r[1] = max(pts[i], r[1]);
        }
        else{
            r[0] = max(pts[i], r[0]);
            r[1] = max(pts[i], r[1]);
        }
    }

    return 0;
}