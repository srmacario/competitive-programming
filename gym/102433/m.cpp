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
const int N = 3e3 + 100, M = 2e6;

int r, c, cnt = 1, vis[N][N];
bool visa[M];
int dx[4] = {-2, 2, 0, 0};
int dy[4] = {0, 0, -2, 2};
string grid[N];
bool shifted_grid[N][N], valid[N][N];
char char_grid[N][N];
set<int> adj[M];

bool check(int i, int j){
    if(i < 0 or i >= N) return false;
    if(j < 0 or j >= N) return false;
    return true;
}

void bfs(int _i, int _j){
    queue<pii> q;
    q.push({_i, _j});
    vis[_i][_j] = cnt;
    while(!q.empty()){
        pii p = q.front();
        int i = p.st, j = p.nd;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nxt_i = i + dx[k], nxt_j = j + dy[k];
            int wall_i = i + dx[k]/2, wall_j = j + dy[k]/2;
            if(!check(nxt_i, nxt_j)) continue;
            if(!shifted_grid[wall_i][wall_j] and !vis[nxt_i][nxt_j]){
                vis[nxt_i][nxt_j] = cnt;
                q.push({nxt_i, nxt_j});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    bool sh = false;
    for(int i = 0; i < r; i++){
        cin >> grid[i];
        for(int j = 0; j < c; j++){
            if(grid[i][j] == '/' and ((i + j) & 1)) sh = true;
            else if(grid[i][j] == '\\' and !((i + j) & 1)) sh = true;
        }
        grid[i].push_back('.');
    }
    if(sh){
        ++c;
        for(int i = r - 1; i >= 0; i--){
            for(int j = c; j > 0; j--){
                grid[i][j] = grid[i][j - 1];
            }
            grid[i][0] = '.';
        }
    }
    int shift = max(r, c) + 5;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == '/'){
                shifted_grid[(i + j) + shift][(j - i) + shift] = 1;
                char_grid[(i + j) + shift][(j - i) + shift] = '-';
            }
            else if(grid[i][j] == '\\'){
                shifted_grid[(i + j) + shift][(j - i) + shift] = 1;
                char_grid[(i + j) + shift][(j - i) + shift] = '|';
            }
        }
    }
    for(int i = 0; i <= r + 2 * shift; i++){
        for(int j = 0; j <= c + 2 * shift; j++){
            cout << shifted_grid[i][j] << " ";
            if(((i+shift) & 1) or (!((j+shift) & 1))) continue;
            if(vis[i][j]) continue;
            ++cnt;
            bfs(i, j);
        }
        cout << "\n";
    }

    for(int i = 0; i <= r + 2 * shift; i++){
        for(int j = 0; j <= c + 2 * shift; j++){
            if(((i+shift) & 1) or (!((j+shift) & 1))) continue;
            for(int k = 0; k < 4; k++){
                int nxt_i = i + dx[k], nxt_j = j + dy[k];
                if(!check(nxt_i, nxt_j)) continue;
                if(vis[i][j] != vis[nxt_i][nxt_j] and !adj[vis[i][j]].count(vis[nxt_i][nxt_j])){
                    adj[vis[i][j]].insert(vis[nxt_i][nxt_j]);
                    adj[vis[nxt_i][nxt_j]].insert(vis[i][j]);
                }
            }
            cout << vis[i][j] << " ";
        }
        if((i & 1)) continue;
            cout << "\n";
    }
    priority_queue<pii> pq;
    pq.push({0, 2});
    int ans = 0;
    while(!pq.empty()){
        int u = pq.top().nd;
        pq.pop();
        if(visa[u]) continue;
        visa[u] = 1;
        ans++;
        for(auto v : adj[u]){
            if(!visa[v]){
                pq.push({-1, v});
            }
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}