#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int dist[505][505], id[105][N];
vector<int> floors[105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, f, m;
        cin >> n >> f >> m;
        int cnt = n;
        memset(dist, 63, sizeof(dist));
        memset(id, 0, sizeof(id));
        for(int i = 1; i <= n; i++){
            floors[i].clear();
            id[i][1] = i;
            floors[i].push_back(1);
            //connect right
            int j = i + 1;
            if(j > n) j = 1;
            dist[i][j] = 1;
            dist[j][i] = 1;

            //connect left
            j = i - 1;
            if(j < 1) j = n;
            dist[i][j] = 1;
            dist[j][i] = 1;
        }
        for(int i = 0; i < m; i++){
            int bi, fi, bj, fj, t;
            cin >> bi >> fi >> bj >> fj >> t;
            if(!id[bi][fi]) id[bi][fi] = ++cnt, floors[bi].push_back(fi);
            if(!id[bj][fj]) id[bj][fj] = ++cnt, floors[bj].push_back(fj);
            dist[id[bi][fi]][id[bj][fj]] = min(dist[id[bi][fi]][id[bj][fj]], t);
            dist[id[bj][fj]][id[bi][fi]] = min(dist[id[bj][fj]][id[bi][fi]], t);
        }
        for(int i = 1; i <= n; i++){
            sort(floors[i].begin(), floors[i].end());
            for(int j = 1; j < floors[i].size(); j++){
                dist[id[i][floors[i][j]]][id[i][floors[i][j - 1]]] = floors[i][j] - floors[i][j - 1];
                dist[id[i][floors[i][j - 1]]][id[i][floors[i][j]]] = floors[i][j] - floors[i][j - 1];
            }
        }
        for(int k = 1; k <= cnt; k++)
            for(int i = 1; i <= cnt; i++)
                for(int j = 1; j <= cnt; j++){
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
        int q;
        cin >> q;
        for(int i = 0; i < q; i++){
            int bi, fi, bj, fj;
            cin >> bi >> fi >> bj >> fj;
            int p[2], q[2];
            p[0] = p[1] = q[0] = q[1] = 1e9;
            for(int j = 0; j < floors[bi].size(); j++){
                if(floors[bi][j] <= fi) p[0] = floors[bi][j];
                else{
                    p[1] = floors[bi][j];
                    break;
                }
            }
            for(int j = 0; j < floors[bj].size(); j++){
                if(floors[bj][j] <= fj) q[0] = floors[bj][j];
                else{
                    q[1] = floors[bj][j];
                    break;
                }
            }
            int ans = 1e9;
            if(bi == bj){
                ans = abs(fi - fj);
            }
            for(int j = 0; j < 2; j++){
                if(p[j] == 1e9) continue;
                for(int k = 0; k < 2; k++){
                    if(q[k] == 1e9) continue;
                    int cur = dist[id[bi][p[j]]][id[bj][q[k]]] + abs(p[j] - fi) + abs(q[k] - fj);
                    ans = min(cur, ans);
                }
            }
            cout << ans << "\n";
        }
        
    }
    return 0;
}
