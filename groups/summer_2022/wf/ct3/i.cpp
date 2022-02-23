#include <bits/stdc++.h>

using namespace std;

void walk_left(){

}

void walk_right(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    //freopen("in.txt", "r", stdin);
    //while(cin >> n >> m){
    cin >> n >> m;
        set<int> lft;
        vector<int> par(n + 5);
        vector<vector<int>> r(n + 5);
        int ans = 0;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            r[v].push_back(u);
            par[u]++;
        }
        priority_queue<int> max_pq, min_pq;
        for(int i = 1; i <= n; i++){
            lft.insert(i);
            if(!par[i]) min_pq.push(-i), max_pq.push(i);
        }
        int cur = 0;
        while(!lft.empty()){
            walk_right();
            if(lft.empty()){
                break;
            }
            walk_left();
        }
        ans += abs(n + 1 - cur);
        cout << ans << "\n";
    //}
    return 0;
}