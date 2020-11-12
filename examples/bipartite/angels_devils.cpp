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
const int M = 305, N = 1e5+5;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        int x,y;
        memset(col,-1,sizeof(col));
        memset(row,-1,sizeof(row));
        cin >> x >> y;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                cin >> grid[i][j];
            }
        }
        int rcnt = 0;
        char last = 'A';
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j] == 'A') {
                    if(j != y-1 and last != 'A') rcnt++;
                }
                if(grid[i][j] == 'H') row[i][j] = rcnt;
                last = grid[i][j];
            }
            rcnt++;
        }
        int ccnt = 0;
        last = 'A';
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                if(grid[j][i] == 'A') {
                    if(j != x-1 and last != 'A') ccnt++;
                }
                if(grid[j][i] == 'H') col[j][i] = ccnt;
                last = grid[j][i];
            }
            ccnt++;
        }
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                if(grid[i][j] == 'H'){
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