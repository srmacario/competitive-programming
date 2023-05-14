#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+5;
int x, marcB[N], matchB[N], matchA[N], ans, n, m, p;
vector<int> adj[N];

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

int idb[505][505], idw[505][505];
string grid[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> grid[i];
        //identify
        int cntW = 0, cntB = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'W'){
                    idw[i][j] = ++cntW;
                }
                if(grid[i][j] == 'B'){
                    idb[i][j] = ++cntB;
                }
            }
        }
        //connect
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'W'){
                    if(i > 0 and grid[i - 1][j] == 'B'){
                        adj[idw[i][j]].push_back(idb[i - 1][j]);
                    }
                    if(i < n - 1 and grid[i + 1][j] == 'B'){
                        adj[idw[i][j]].push_back(idb[i + 1][j]);
                    }
                    
                    if(j > 0 and grid[i][j - 1] == 'B'){
                        adj[idw[i][j]].push_back(idb[i][j - 1] + cntB);
                    }
                    if(j < m - 1 and grid[i][j + 1] == 'B'){
                        adj[idw[i][j]].push_back(idb[i][j + 1] + cntB);
                    }
                }
                // cout << "\n";
            }
        }
        // cout << "cntb " << cntB << "\n";
        //kuhn
        for(int i = 0; i <= cntW; i++) matchA[i] = -1;
        for(int j = 0; j <= 2*cntB; j++) matchB[j] = -1;

        bool aux = true;
        while(aux){
            for(int j = 1; j <= 2*cntB; j++) marcB[j] = 0;
            aux = false;
            for(int i = 1; i <= cntW; i++){
                if(matchA[i] != -1) continue;
                if(dfs(i)){
                    ans++;
                    aux = true;
                }
            }
        }
        for(int i = 0; i <= cntW; i++) adj[i].clear();
        for(int i = 0; i <= cntW; i++) matchA[i] = -1;
        for(int j = 0; j <= 2*cntB; j++) matchB[j] = -1;

        if(ans == cntW and ans == 2*cntB) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}