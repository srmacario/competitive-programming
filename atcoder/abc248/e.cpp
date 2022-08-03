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

int n, k;
pair<int, int> pts[N];
map<pair<pair<ll, ll>, pair<ll, ll>>, set<int>> lines;
map<int, set<int>> hoz, ver;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    if(k == 1){
        cout << "Infinity\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ll dy = (pts[j].y - pts[i].y);
            ll dx = (pts[j].x - pts[i].x);
            //corner cases
            if(!dx){
                ver[pts[j].x].insert(i);
                ver[pts[j].x].insert(j);
            }
            else if(!dy){
                hoz[pts[j].y].insert(i);
                hoz[pts[j].y].insert(j);
            }
            //normal cases
            else{
                //treat signal
                if(dy * dx < 0) dx = abs(dx), dy = -abs(dy);
                else dx = abs(dx), dy = abs(dy);

                //minimize fraction
                ll mdc = __gcd(abs(dy), abs(dx));
                dy /= mdc;
                dx /= mdc;

                //y0*dx - dy*x0 = dx*n
                ll A = pts[j].y*dx - dy*pts[j].x;
                ll B = dx;
                if(A * B < 0) B = abs(B), A = -abs(A);
                else B = abs(B), A = abs(A);
                mdc = __gcd(abs(A), abs(B));
                A /= mdc;
                B /= mdc;

                lines[{{dy, dx}, {A, B}}].insert(i);
                lines[{{dy, dx}, {A, B}}].insert(j);
            }
        }
    }
    int cnt = 0;
    for(auto it: lines){
        if(it.y.size() >= k){
            cnt++;
        }
    }
    for(auto it : hoz){
        if(it.y.size() >= k){
            cnt++;
        }
    }
    
    for(auto it : ver){
        if(it.y.size() >= k){
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}