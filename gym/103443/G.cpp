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
const int N = 50, MMC = 840;

int grid[N][N], dist[N][N][MMC], cant[N][N][MMC];
int n, m, g;
int x[N][N], y[N][N], k[N];
pii delta[5] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {0, 0}};

int bfs(){
    //initialize
    piii ini = {0, {x[0][0], y[0][0]}};
    dist[x[0][0]][y[0][0]][0] = 0;
    queue<piii> q;
    q.push(ini);
    int ans = INF;
    while(!q.empty()){
        piii cur = q.front(); q.pop();
        if(!grid[cur.nd.st][cur.nd.nd] and (cur.nd.st != x[0][0] or cur.nd.nd != y[0][0])) ans = min(ans, dist[cur.nd.st][cur.nd.nd][cur.st]);
        for(int i = 0; i < 5; i++){
            if(cur.nd.st + delta[i].st < 0 or cur.nd.st + delta[i].st >= n) break;
            if(cur.nd.nd + delta[i].nd < 0 or cur.nd.nd + delta[i].nd >= m) break;
            if( dist[cur.nd.st + delta[i].st][cur.nd.nd + delta[i].nd][(cur.st + 1)%MMC] > dist[cur.nd.st][cur.nd.nd][cur.st] + 1 and
                grid[cur.nd.st + delta[i].st][cur.nd.nd + delta[i].nd] <= grid[cur.nd.st][cur.nd.nd] and
                !cant[cur.nd.st + delta[i].st][cur.nd.nd + delta[i].nd][(cur.st + 1)%MMC] and
                !cant[cur.nd.st + delta[i].st][cur.nd.nd + delta[i].nd][(cur.st + 2)%MMC]){
                
                dist[cur.nd.st + delta[i].st][cur.nd.nd + delta[i].nd][(cur.st + 1)%MMC] = dist[cur.nd.st][cur.nd.nd][cur.st] + 1;
                q.push({(cur.st + 1)%MMC, {cur.nd.st + delta[i].st, cur.nd.nd + delta[i].nd}});
            }
            // else db(cur.nd.st + delta[i].st _ cur.nd.nd + delta[i].nd _ (cur.st + 1)%MMC);
        }
    }
    if(ans == INF) ans = -1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        
        //reset
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                for(int k = 0; k < MMC; k++){
                    dist[i][j][k] = INF;
                    cant[i][j][k] = 0;
                }
            }
        }

        //read grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[j][i];
            }
        }
        //initial pos
        cin >> x[0][0] >> y[0][0];

        //guards
        cin >> g;
        for(int i = 1; i <= g; i++){
            cin >> k[i];
            for(int j = 0; j < k[i]; j++){
                cin >> x[i][j] >> y[i][j];
            }

            //map cant positions
            int curx, cury;
            for(int j = 0; j < MMC; j++){
                curx = x[i][j % k[i]];
                cury = y[i][j % k[i]];
                cant[curx][cury][j] = 1;
                // db(curx _ cury _ j);
            }
        }
        cout << bfs() << "\n";
    }
    return 0;
}