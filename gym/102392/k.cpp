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
const int N = 505;

int m, n, p;
//p x n x m
string grid[N][N];
//
//xi, yi, r, s:
//0, 1: min, max 
//0, 1, 2: p, n, m
int lit[N][N][2][3], dist[N][N][2][3], vis[N][N][2][3];

struct block{
    //i, j, k
    int x, y, z, side, axis;
    block(int inix = 0, int iniy = 0, int iniz = 0, int iniside = 0, int iniaxis = 0) : x(inix), y(iniy), z(iniz), side(iniside), axis(iniaxis){}
};

queue<block> q;
block ini, tp;

bool comp(int zf, int z0, int side){
    if(zf == INF) return false;
    if(side == 0) return zf >= z0;
    return zf <= z0;
}

int bfs(){
    int ans = INF;
    while(!q.empty()){
        block u = q.front();
        vis[u.x][u.y][u.side][u.axis] = 1;
        q.pop();
        if(u.axis == 0 and u.x == tp.x and u.y == tp.y and u.z == tp.z) ans = min(ans, dist[u.x][u.y][u.side][u.axis]);
        if(u.axis == 1 and u.x == tp.z and u.y == tp.y and u.z == tp.x) ans = min(ans, dist[u.x][u.y][u.side][u.axis]);
        if(u.axis == 2 and u.x == tp.z and u.y == tp.x and u.z == tp.y) ans = min(ans, dist[u.x][u.y][u.side][u.axis]);
        if(comp(lit[u.x - 1][u.y][u.side][u.axis], u.z, u.side)){
            block cur = block(u.x - 1, u.y, lit[u.x - 1][u.y][u.side][u.axis], u.side, u.axis);
            if(dist[u.x][u.y][u.side][u.axis] + 1 < dist[u.x - 1][u.y][u.side][u.axis]){
                dist[u.x - 1][u.y][u.side][u.axis] = dist[u.x][u.y][u.side][u.axis] + 1;
                q.push(cur);
            }
        }
        if(comp(lit[u.x + 1][u.y][u.side][u.axis], u.z, u.side)){
            block cur = block(u.x + 1, u.y, lit[u.x + 1][u.y][u.side][u.axis], u.side, u.axis);
            if(dist[u.x][u.y][u.side][u.axis] + 1 < dist[u.x + 1][u.y][u.side][u.axis]){
                dist[u.x + 1][u.y][u.side][u.axis] = dist[u.x][u.y][u.side][u.axis] + 1;
                q.push(cur);
            }
        }
        if(comp(lit[u.x][u.y - 1][u.side][u.axis], u.z, u.side)){
            block cur = block(u.x, u.y - 1, lit[u.x][u.y - 1][u.side][u.axis], u.side, u.axis);
            if(dist[u.x][u.y][u.side][u.axis] + 1 < dist[u.x][u.y - 1][u.side][u.axis]){
                dist[u.x][u.y - 1][u.side][u.axis] = dist[u.x][u.y][u.side][u.axis] + 1;
                q.push(cur);
            }
        }
        if(comp(lit[u.x][u.y + 1][u.side][u.axis], u.z, u.side)){
            block cur = block(u.x, u.y + 1, lit[u.x][u.y + 1][u.side][u.axis], u.side, u.axis);
            if(dist[u.x][u.y][u.side][u.axis] + 1 < dist[u.x][u.y + 1][u.side][u.axis]){
                dist[u.x][u.y + 1][u.side][u.axis] = dist[u.x][u.y][u.side][u.axis] + 1;
                q.push(cur);
            }
        }

        //rotate
        if(u.axis == 0){
            if(dist[u.z][u.y][0][1] > dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][0][1] != u.x) and !vis[u.z][u.y][0][1] and comp(lit[u.z][u.y][0][1], u.x, 0)){
                block cur1 = block(u.z, u.y, lit[u.z][u.y][0][1], 0, 1);
                dist[u.z][u.y][0][1] = dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][0][1] != u.x);
                q.push(cur1);
            }
            if(dist[u.z][u.y][1][1] > dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][1][1] != u.x) and !vis[u.z][u.y][1][1] and comp(lit[u.z][u.y][1][1], u.x, 1)){
                block cur1 = block(u.z, u.y, lit[u.z][u.y][1][1], 1, 1);
                dist[u.z][u.y][1][1] = dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][1][1] != u.x);
                q.push(cur1);
            }
            if(dist[u.z][u.x][0][2] > dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][0][2] != u.y) and !vis[u.z][u.x][0][2] and comp(lit[u.z][u.x][0][2], u.y, 0)){
                block cur2 = block(u.z, u.x, lit[u.z][u.x][0][2], 0, 2);
                dist[u.z][u.x][0][2] = dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][0][2] != u.y);
                q.push(cur2);
            }
            if(dist[u.z][u.x][1][2] > dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][1][2] != u.x) and !vis[u.z][u.x][1][2] and comp(lit[u.z][u.x][1][2], u.y, 1)){
                block cur2 = block(u.z, u.x, lit[u.z][u.x][1][2], 1, 2);
                dist[u.z][u.x][1][2] = dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][1][2] != u.y);
                q.push(cur2);
            }
        }
        if(u.axis == 1){
            //z, y, x
            // db(lit[u.z][u.y][0][0] _ u.x);
            if(dist[u.z][u.y][0][0] > dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][0][0] != u.x) and !vis[u.z][u.y][0][0] and comp(lit[u.z][u.y][0][0], u.x, 0)){
                block cur0 = block(u.z, u.y, lit[u.z][u.y][0][0], 0, 0);
                dist[u.z][u.y][0][0] = dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][0][0] != u.x);
                q.push(cur0);
            }
            if(dist[u.z][u.y][1][0] > dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][1][0] != u.x) and !vis[u.z][u.y][1][0] and comp(lit[u.z][u.y][1][0], u.x, 1)){
                block cur0 = block(u.z, u.y, lit[u.z][u.y][1][0], 1, 0);
                dist[u.z][u.y][1][0] = dist[u.x][u.y][u.side][u.axis] + (lit[u.z][u.y][1][0] != u.x);
                q.push(cur0);
            }
            if(dist[u.z][u.y][0][2] > dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][0][2] != u.y) and !vis[u.x][u.z][0][2] and comp(lit[u.x][u.z][0][2], u.y, 0)){
                block cur2 = block(u.x, u.z, lit[u.x][u.z][0][2], 0, 2);
                dist[u.x][u.z][0][2] = dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][0][2] != u.y);
                q.push(cur2);
            }
            if(dist[u.x][u.z][1][2] > dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][1][2] != u.y) and !vis[u.x][u.z][1][2] and comp(lit[u.x][u.z][1][2], u.y, 1)){
                block cur2 = block(u.x, u.z, lit[u.x][u.z][1][2], 1, 2);
                dist[u.x][u.z][1][2] = dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][1][2] != u.y);
                q.push(cur2);
            }
        }
        if(u.axis == 2){
            //z, x, y
            if(dist[u.z][u.y][0][0] > dist[u.x][u.y][u.side][u.axis] + (lit[u.y][u.z][0][0] != u.x) and !vis[u.y][u.z][0][0] and comp(lit[u.y][u.z][0][0], u.x, 0)){
            block cur0 = block(u.y, u.z, lit[u.y][u.z][0][0], 0, 0);
                dist[u.y][u.z][0][0] = dist[u.x][u.y][u.side][u.axis] + (lit[u.y][u.z][0][0] != u.x);
                q.push(cur0);
            }
            if(dist[u.z][u.y][1][0] > dist[u.x][u.y][u.side][u.axis] + (lit[u.y][u.z][1][0] != u.x) and !vis[u.y][u.z][1][0] and comp(lit[u.y][u.z][1][0], u.x, 1)){
                block cur0 = block(u.y, u.z, lit[u.y][u.z][1][0], 1, 0);
                dist[u.y][u.z][1][0] = dist[u.x][u.y][u.side][u.axis] + (lit[u.y][u.z][1][0] != u.x);
                q.push(cur0);
            }

            if(dist[u.z][u.y][0][1] > dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][0][1] != u.y) and !vis[u.x][u.z][0][1] and comp(lit[u.x][u.z][0][1], u.y, 0)){
                block cur1 = block(u.x, u.z, lit[u.x][u.z][0][1], 0, 1);
                dist[u.x][u.z][0][1] = dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][0][1] != u.y);
                q.push(cur1);
            }
            if(dist[u.z][u.y][1][1] > dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][1][1] != u.y) and !vis[u.x][u.z][1][1] and comp(lit[u.x][u.z][1][1], u.y, 1)){
                block cur1 = block(u.x, u.z, lit[u.x][u.z][1][1], 1, 1);
                dist[u.x][u.z][1][1] = dist[u.x][u.y][u.side][u.axis] + (lit[u.x][u.z][1][1] != u.y);
                q.push(cur1);
            }
        }
    }
    if(ans == INF) return -1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> p;
    memset(lit, 63, sizeof(lit));
    memset(dist, 63, sizeof(dist));
    for(int i = 1; i <= p; i++){
        for(int j = 1; j <= n; j++){
            string s;
            cin >> s;
            grid[i][j] = "#" + s;
        }

        //find min and max in direction m
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                if(grid[i][j][k] == '*'){
                    if(lit[i][j][0][2] == INF) lit[i][j][0][2] = k - 1;
                    lit[i][j][1][2] = k + 1;
                }
                if(grid[i][j][k] == 'R') ini = {j, k, i};
                if(grid[i][j][k] == 'T') tp = {j, k, i};
            }
        }

        //find min and max in direction n
        for(int k = 1; k <= m; k++){
            for(int j = 1; j <= n; j++){
                if(grid[i][j][k] == '*'){
                    if(lit[i][k][0][1] == INF) lit[i][k][0][1] = j - 1;
                    lit[i][k][1][1] = j + 1;
                }
            }
        }
        
        //find min and max in direction p
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                if(grid[i][j][k] == '*'){
                    if(lit[j][k][0][0] == INF) lit[j][k][0][0]= i - 1;
                    lit[j][k][1][0] = i + 1;
                }
            }
        }
    }
    if(comp(lit[ini.x][ini.y][0][0], ini.z, 0)){
        dist[ini.x][ini.y][0][0] = (lit[ini.x][ini.y][0][0] != ini.z);
        q.push({ini.x, ini.y, lit[ini.x][ini.y][0][0], 0, 0});
    }
    if(comp(lit[ini.x][ini.y][1][0], ini.z, 1)){
        dist[ini.x][ini.y][1][0] = (lit[ini.x][ini.y][1][0] != ini.z);
        q.push({ini.x, ini.y, lit[ini.x][ini.y][1][0], 1, 0});
    }

    if(comp(lit[ini.z][ini.y][0][1], ini.x, 0)){
        dist[ini.z][ini.y][0][1] = (lit[ini.z][ini.y][0][1] != ini.x);
        q.push({ini.z, ini.y, lit[ini.z][ini.y][0][1], 0, 1});
    }
    if(comp(lit[ini.z][ini.y][1][1], ini.x, 1)){
        dist[ini.z][ini.y][1][1] = (lit[ini.z][ini.y][1][1] != ini.x);
        q.push({ini.z, ini.y, lit[ini.z][ini.y][1][1], 1, 1});
    }
    if(comp(lit[ini.z][ini.x][0][2], ini.y, 0)){
        dist[ini.z][ini.x][0][2] = (lit[ini.z][ini.x][0][2] != ini.y);
        q.push({ini.z, ini.x, lit[ini.z][ini.x][0][2], 0, 2});
    }
    if(comp(lit[ini.z][ini.x][1][2], ini.y, 1)){
        dist[ini.z][ini.x][1][2] = (lit[ini.z][ini.x][1][2] != ini.y);
        q.push({ini.z, ini.x, lit[ini.z][ini.x][1][2], 1, 2});
    }
    cout << bfs() << "\n";
    return 0;
}