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
const int M = 105, N = 1e5+5;

int n, matchA[N], matchB[N], marcB[N], col[M][M], row[M][M];
vi adj[N];
char grid[M][M];

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
    while(scanf("%d",&n)!=EOF){
        memset(col,-1,sizeof(col));
        memset(row,-1,sizeof(row));
        for(int i=0;i<n;i++){
            scanf("%s",grid[i]);
        }
        int rcnt = 0;
        char last = 'X';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'X'){
                    if(j != n-1 and last != 'X') rcnt++;
                }
                else row[i][j] = rcnt;
                last = grid[i][j];
            }
            rcnt++;
        }
        int ccnt = 0;
        last = 'X';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i] == 'X'){
                    if(j != n-1 and last != 'X') ccnt++;
                }
                else col[j][i] = ccnt;
                last = grid[j][i];
            }
            ccnt++;
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 'X'){
                    cout << col[i][j];
                }
                else cout << 'X';
            }
            cout << "\n";
        }*/
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 'X'){
                    adj[row[i][j]].pb(col[i][j]);
                }
            }
        }
        for(int i=0; i < rcnt;i++) matchA[i] = -1;
        for(int i=0; i < ccnt;i++) matchB[i] = -1;

        bool aux = true;
        int resp = 0;
        while(aux){
            for(int j = 0; j < ccnt; j++) marcB[j] = 0;
            aux = false;
            for(int i = 0; i < rcnt; i++){
                if(matchA[i] != -1) continue;
                if(dfs(i)){
                    resp++;
                    aux = true;
                }
            }
        }
        cout << resp << "\n";
        for(int i=0;i<rcnt;i++) adj[i].clear();
    }
    return 0;
}