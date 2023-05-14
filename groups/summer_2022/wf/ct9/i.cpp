#include <bits/stdc++.h>

using namespace std;

#define st firs
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 305, M = 1005;

vi adj[N];
int vis[N];
ld x[N], y[N], m[N][N];

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}

ld C[N][M];
int row, col;

bool elim(){
    for(int i = 0; i < row; ++i){
        int p = i;
        for(int j = i; j < row; ++j) if(abs(C[j][i]) > abs(C[p][i])) p = j;
        for(int j = i; j < col; ++j) swap(C[i][j], C[p][j]);
        if(!C[i][i]) return 0;

        ld c = 1/C[i][i];
        for(int j = 0; j < col; ++j) C[i][j] *= c;

        for(int k = i + 1; k < col; ++k){
            ld c = -C[k][i];
            for(int j = 0; j < col; ++j) C[k][j] += c * C[i][j];
        }
    }

    for(int i = row - 1; i >= 0; --i) for(int j = i - 1; j >= 0;--j){
        ld c = -C[j][i];
        for(int k = i; k < col; ++k) C[j][k] += c * C[i][k];
    }
    return 1;
}

// a*y = x
bool linear_system(int n){
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) C[i][j] = m[i][j];
    for(int j = 0; j < n; j++) C[j][n] = x[j];
    
    row = n, col = n + 1;
    bool ok = elim();

    for(int j = 0; j < n; ++j) y[j] = C[j][n];
    return ok;
}

int main(){
    while(true){
        int s;
        scanf("%d", &s);
        if(!s) return 0;
        memset(vis, 0, sizeof(vis));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(m, 0, sizeof(m));
        for(int i = 0; i < N; i++) adj[i].clear();
        for(int i = 0; i < s; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(300);
        for(int i = 0; i <= 300; i++){
            m[i][i] = 1;
            if(vis[i]){
                if(i == 300) x[i] = 1;
                else if(i <= 290){
                    for(auto v : adj[i]){
                        m[i][v] = (- 1.0 / adj[i].size());
                    }
                }
            }
        }
        linear_system(301);
        printf("%.3lf\n", y[0]);
    }
    return 0;
}