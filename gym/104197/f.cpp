#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 4e5 + 5;

int n, m;
vector<int> go[N], lk[N];
int w[N], deg[N], pos[N], id[N];

bool circle4(){
    for(int i = 1; i <= n; i++) w[i] = 0;
    int ans = 0;
    for(int x = 1; x <= n; x++){
        for(int y : go[x]){
            for(int z : lk[y]){
                if(pos[z] > pos[x]){
                    ans = (ans + w[z]);
                    w[z]++;
                    if(ans) return true;
                }
            }
        }
        for(int y : go[x]){
            for(int z : lk[y]){
                w[z] = 0;
            }
        }
    }
    return false;
}

bool cmp(int x, int y) {
    return deg[x] < deg[y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    n *= 2;
    for(int i = 1; i <= n; i++){
        deg[i] = 0, go[i].clear(), lk[i].clear();
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
        go[u].push_back(v);
        go[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) id[i] = i;
    sort(id + 1, id + 1 + n, cmp);
    for(int i = 1; i <= n; i++) pos[id[i]] = i;
    for(int x = 1; x <= n; x++){
        for(int y : go[x]){
            if(pos[y] > pos[x])
                lk[x].push_back(y);
        }
    }
    if(circle4()){
        cout << "2\n";
    }
    else cout << "3\n";
    return 0;
}