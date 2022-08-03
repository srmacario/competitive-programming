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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int W, H, w, h;
        cin >> W >> H;
        int x[2], y[2];
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> w >> h;
        int dist = INF;
        //put horizontal
        if(w + (x[1] - x[0]) <= W){
            //put left
            dist = min(dist, max(0, w - x[0]));
            //put right
            dist = min(dist, max(0, w - (W - x[1])));
        }
        //put vertical
        if(h + (y[1] - y[0]) <= H){
            //put bottom
            dist = min(dist, max(0, h - y[0]));
            //put top
            dist = min(dist, max(0, h - (H - y[1])));
        }
        if(dist == INF) cout << -1 << "\n";
        else cout << setprecision(15) << fixed << (ld) dist << "\n";
    }
    return 0;
}