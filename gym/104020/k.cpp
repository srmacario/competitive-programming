#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 55;

int h, w, a[N][N], vis[N][N][N*N], dist[N][N][N*N];

int calc(int i, int j, int look){
    if(vis[i][j][look] == 2) return dist[i][j][look];
    if(vis[i][j][look] == 1) return dist[i][j][look] = INF;
    if(a[i][j] == look){
        vis[i][j][look] = 2;
        return dist[i][j][look] = 0;
    }
    vis[i][j][look] = 1;
    //where should i go
    pair<pii, pii> to = {{INF, INF}, {INF, INF}};
    if(i - 1 >= 0) to = min(to, {{abs(look - a[i - 1][j]), abs(a[i][j] - a[i - 1][j])}, {i - 1, j}});
    if(i + 1 < h) to = min(to, {{abs(look - a[i + 1][j]), abs(a[i][j] - a[i + 1][j])}, {i + 1, j}});
    if(j - 1 >= 0) to = min(to, {{abs(look - a[i][j - 1]), abs(a[i][j] - a[i][j - 1])}, {i, j - 1}});
    if(j + 1 < w) to = min(to, {{abs(look - a[i][j + 1]), abs(a[i][j] - a[i][j + 1])}, {i, j + 1}});
    int next = calc(to.nd.st, to.nd.nd, look);
    if(next == INF){
        vis[i][j][look] = 1;
        dist[i][j][look] = INF;
    }                
    else{
        vis[i][j][look] = 2;
        dist[i][j][look] = next + 1;
    }
    return dist[i][j][look];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    pii ans = {INF, INF};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            bool ok = true;
            int cur_ans = 0;
            for(int k = 1; k <= h * w; k++){
                calc(i, j, k);
                // db(a[i][j] _ k _ dist[i][j][k]);
                if(dist[i][j][k] == INF){
                    ok = false;
                }
                cur_ans = max(cur_ans, dist[i][j][k]);
            }
            if(ok) ans = min(ans, make_pair(cur_ans, a[i][j]));
        }
    }
    if(ans.st == INF){
        cout << "impossible\n";
    }
    else cout << ans.nd << " " << ans.st << "\n";
    return 0;
}