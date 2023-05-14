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
const int N = 3e5+5, M = 505;

int n, m, grid[M][M], dist[M][M];
pii dx[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void bfs(){
    cl(dist, 63);
    queue <pii> q;
    q.push({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        pii u = q.front();
        int w = grid[u.st][u.nd];
        q.pop();
        for(int i = 0; i < 4; i++){
            pii pos = {u.st + dx[i].st*(w), u.nd + dx[i].nd*(w)};
            // db(pos.st _ pos.nd _ w);
            if(pos.st < n and pos.st >= 0 and pos.nd < m and pos.nd >= 0){
                if(dist[pos.st][pos.nd] > dist[u.st][u.nd] + 1){
                    dist[pos.st][pos.nd] = dist[u.st][u.nd] + 1;
                    q.push(pos);
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) grid[i][j] = s[j] - '0'; 
    }
    bfs();
    if(dist[n-1][m-1] == INF) cout << "-1\n";
    else cout << dist[n-1][m-1] << "\n";  
    return 0;
}