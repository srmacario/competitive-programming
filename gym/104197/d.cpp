#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int INF = 0x3f3f3f3f;
const int N = 505;

int adj[N][N], grid[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < n; j++){
                adj[i][j] = s[j] - '0';
                grid[i][j] = adj[i][j];
                if(!adj[i][j] and i != j) adj[i][j] = INF;
                cnt += grid[i][j];
            }
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] == INF) ok = false;
                if(grid[i][j] != (adj[i][j] % 2)) ok = false;
            }
        }
        
        if(ok){
            cout << "YES\n";
            cout << cnt/2 << "\n";
            for(int i = 0; i < n; i++)
                for(int j = i + 1; j < n; j++)
                    if(grid[i][j]) cout << i + 1 << " " << j + 1 << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}