#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n;
vector<int> adj[N];

void dfs(int p, int s){
    for(int i : adj[p]){
        for(int j = 0; j < adj[i].size(); j++)
            if(adj[i][j] == p){
                swap(adj[i][j], adj[i].back());
                adj[i].pop_back();
                break;
            }
    }
    for(int i = 0; i < (adj[p].size() + s) / 2; i++)
        dfs(adj[p][i], 1);
    printf("%d ", p);
    for(int i = (adj[p].size() + s) / 2; i < adj[p].size(); i++)
        dfs(adj[p][i], 0);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    return 0;
}