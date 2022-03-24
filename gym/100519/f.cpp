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

ld xa, xb, ya, yb, xc, yc, D, V, w, ans;
int hd, md, hf, mf, hans;

ld d(ld x, ld y, ld xx, ld yy){
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

bool inl(ld x, ld y, ld xx, ld yy, ld xxx, ld yyy){
    ld cross = (xx - x) * (yyy - y) - (xxx - x) * (yy - y);
    if(!( (cross - EPS < 0) and (cross + EPS > 0) )) return false;
    return (x - EPS < max(xx, xxx) and x + EPS > min(yy, yyy)) and
           (y - EPS < max(yy, yyy) and y + EPS > min(yy, yyy));
}

int main(){
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &xa, &ya, &xb, &yb, &xc, &yc);
    scanf("%Lf %Lf", &D, &V);
    scanf("%d:%d %d:%d", &hd, &md, &hf, &mf);
    scanf("%Lf", &w);
    ans = (d(xa, ya, xc, yc) + d(xc, yc, xb, yb)) / V * 60 + D;
    hans = 0;
    if(ans > (hd - 9 + hf) * 60 + md + mf){
        ans = (hd - 9 + hf) * 60 + md + mf;
        hans = 1;
    }
    ld h = d(xa, ya, xb, yb) / w * 60;
    if(inl(xc, yc, xa, ya, xb, yb))
        h += D;
    if(ans > h)
        hans = 2;
    if(hans == 0)
        printf("Alex\n");
    else if(hans == 1)
        printf("Dmitry\n");
    else
        printf("Petr\n");
    return 0;
}