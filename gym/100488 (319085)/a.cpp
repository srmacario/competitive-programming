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

int main(){
    ld p[3], r;
    scanf("%Lf%Lf%Lf%Lf", &p[0], &p[1], &p[2], &r);
    ld per = (p[0] + p[1] + p[2])/2, dif = 0;
    ld area = per;
    for(int i = 0; i < 3; i++){
        area *= (per - p[i]);
        ld c = (p[(i+1)%3]*p[(i+1)%3] + p[(i+2)%3]*p[(i+2)%3] - p[i]*p[i])/(2*p[(i+1)%3]*p[(i+2)%3]);
        ld ang = acos(c);
        // db(c _ ang);
        dif = dif +(r*r)/tan(ang/2) - ((PI - ang)/2)*r*r;
        // db(dif);
    }
    area = sqrt(area);
    // db(dif _ area);
        printf("%.20Lf\n", 1 - dif/area);
    return 0;
}