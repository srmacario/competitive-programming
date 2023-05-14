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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int M = 1005, N = 1e5+5;

int n, r, c, matchA[M], matchB[M], marcB[M], row[M], col[M], numrow[M], numcol[M];
vi adj[M];
int grid[M][M];

bool dfs(int v){
    for(int i = 0; i < adj[v].size(); i++){
        int viz = adj[v][i];
        if(marcB[viz] == 1) continue;
        marcB[viz] = 1;

        if((matchB[viz] == -1) || dfs(matchB[viz])){
            matchB[viz] = v;
            matchA[v] = viz;
            return true;
        }
    }
    return false;
}

int main(){
    while(true){
        scanf("%d%d%d",&r, &c, &n);
        if(r == 0 and c == 0 and n == 0) return 0;
        for(int i=0;i<n;i++){
            int x,y;
            cin >> x >> y;
            grid[x][y] = 1;
            numrow[x]++;
            numcol[y]++;
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(grid[i][j] == 1){
                    adj[i].pb(j);
                }
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        for(int i=1; i <= r;i++) matchA[i] = -1;
        for(int i=1; i <= c;i++) matchB[i] = -1;
        vector <pii> point;
        bool aux = true;
        int resp = 0;
        while(aux){
            for(int j = 1; j <= c; j++) marcB[j] = 0;
            aux = false;
            for(int i = 1; i <= r; i++){
                if(matchA[i] != -1) continue;
                if(dfs(i)){
                    resp++;
                    aux = true;
                    point.pb({i,matchA[i]});
                }
            }
        }
        cout << resp << " ";
        bool ok = true;
        while(ok){
            for(int i=0;i<resp;i++){
                if(numrow[point[i].st] > numcol[point[i].nd]){
                    cout << "r" << point[i].st << " ";
                    for(int j=1;j<=c;j++){
                        if(grid[point[i].st][j]) numcol[j]--;
                    }
                }
                else if{
                    cout << "c" << point[i].nd << " ";
                    for(int j=1;j<=c;j++){
                        if(grid[j][point[i].nd]) numrow[j]--;
                    }
                }
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                grid[i][j] = 0;
                numcol[j] = 0;
            }
            numrow[i] = 0;            
            adj[i].clear();
        }
        cout << "\n";
    }
    return 0;
}