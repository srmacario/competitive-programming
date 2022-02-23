#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

const int N = 1e5 + 5;

int par[N], sz[N];

int find(int a){ return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k = 0;
    cin >> t;
    while(t--){
        ++k;
        int s, l;
        cin >> s >> l;
        for(int i = 1; i <= s; i++) par[i] = i, sz[i] = 1;
        int cost = 0;
        vector<pair<int, pair<int, int>>> edges;
        priority_queue<int> pq;
        for(int i = 0; i < l; i++){
            int u, v, w;
            cin >> u >> v >> w;
            cost += w;
            edges.push_back({-w, {u, v}});
        }
        sort(edges.begin(), edges.end());
        for(auto e : edges){
            if(find(e.nd.st) != find(e.nd.nd)){
                unite(e.nd.st, e.nd.nd), cost += e.st;
            }
            else{
                pq.push(-e.st);
            }
        }
        pq.push(0);
        cout << "Case #" << k << ": ";
        cout << cost << " " << pq.top() << "\n";
    }

    return 0;
}