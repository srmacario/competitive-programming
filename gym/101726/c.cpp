#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

typedef long long type;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

struct point {
    type x, y, z;
    point() : x(0), y(0), z(0) {}
    point(type x, type y, type z) : x(x), y(y), z(z){}

    point operator -(point p) { return point(x-p.x, y-p.y, z-p.z);}
    
    point operator %(point p){ return point(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);}
    type operator *(point p){return x*p.x + y*p.y + z*p.z;}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        type x,y,z;
        point vert[4], norm[4];
        for(int i=0;i<4;i++){
            cin >> x >> y >> z;
            vert[i] = point(x,y,z);
        }
        point p;
        cin >> x >> y >> z;
        p = point(x,y,z);
        norm[0] = (vert[3] - vert[1])%(vert[2] - vert[1]);
        norm[1] = (vert[3] - vert[0])%(vert[2] - vert[0]);
        norm[2] = (vert[3] - vert[0])%(vert[1] - vert[0]);
        norm[3] = (vert[2] - vert[0])%(vert[1] - vert[0]);
        for(int i=0;i<4;i++){
            point pivo;
            if(i) pivo = vert[0];
            else pivo = vert[1];
            type v1 = norm[i]*(vert[i]-pivo);
            type v2 = norm[i]*(p-pivo);
            if(v1*v2 >= 0) cout << "N";
            else cout << "Y";
        }
        cout << "\n";
    }
    return 0;
}