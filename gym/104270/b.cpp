#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define st first
#define nd second

const int N = 1e5+5;

int n, m, col[N], ordn, scc_cnt, vis[N], ord[N], scc[N], par[N], ans[N], sz[N], freq_cur[N], num_cur[N], most_cur, freq_not_cur[N], num_not_cur[N], most_not_cur, most_scc, total;
bool big[N];
vector<int> adj[N], cmp[N];
vector<pair<int, int>> new_adj[N];
pair<int, int> edge[N];
set<pair<int, int>> mult, unique_edge;

void dfs(int u){
    vis[u] = 1;
    for (auto v : adj[u])
        if (!vis[v])
            par[v] = u, dfs(v);
    ord[ordn++] = u;
}

void dfst(int u){
    scc[u] = scc_cnt, vis[u] = 0;
    cmp[scc_cnt].push_back(u);
    for (auto v : adj[u])
        if (vis[v] and u != par[v])
            dfst(v);
}

void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void kosaraju(){
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    for(int i = ordn - 1; i >= 0; i--) if(vis[ord[i]]) scc_cnt++, dfst(ord[i]);
    //unite components connected my multiple edges
    for(auto p : mult){
        int u = scc[p.st], v = scc[p.nd];
        if(p.st == p.nd or u == v) continue;
        if(cmp[u].size() < cmp[v].size()) swap(u, v);
        for(auto node : cmp[v]){
            cmp[u].push_back(node);
            scc[node] = u;
        }
    }
    for(int i = 1; i <= n; i++) par[i] = 0;
}

void add_colors(int u){
    for(auto v : cmp[u]){
        num_cur[freq_cur[col[v]]]--;
        freq_cur[col[v]]++;
        num_cur[freq_cur[col[v]]]++;
        most_cur = max(most_cur, freq_cur[col[v]]);
    }
}

void sub_colors(int u){
    for(auto v : cmp[u]){
        num_cur[freq_cur[col[v]]]--;
        freq_cur[col[v]]--;
        num_cur[freq_cur[col[v]]]++;
        most_cur = num_cur[most_cur] > 0 ? most_cur : most_cur - 1;
    }
}

void count(int u){
    vis[u] = 1;
    add_colors(u);
    // db(u _ col[u] _ most_cur);
    for (auto v : new_adj[u]){
        if (!vis[v.st]){
            par[v.st] = u;
            count(v.st);
            sz[u] += sz[v.st];
        }
    }
    sz[u]++;
}

void uncount(int u, int p){
    sub_colors(u);
    for (auto v : new_adj[u]){
        if (v.st != p){
            uncount(v.st, u);
        }
    }
}

void exchange_to_cur(int u){
    for(auto v : cmp[u]){
        num_cur[freq_cur[col[v]]]--;
        freq_cur[col[v]]++;
        num_cur[freq_cur[col[v]]]++;
        most_cur = max(most_cur, freq_cur[col[v]]);

        num_not_cur[freq_not_cur[col[v]]]--;
        freq_not_cur[col[v]]--;
        num_not_cur[freq_not_cur[col[v]]]++;
        most_not_cur = num_not_cur[most_not_cur] > 0 ? most_not_cur : most_not_cur - 1;
    }
}

void exchange_to_not_cur(int u){
    for(auto v : cmp[u]){
        num_not_cur[freq_not_cur[col[v]]]--;
        freq_not_cur[col[v]]++;
        num_not_cur[freq_not_cur[col[v]]]++;
        most_not_cur = max(most_not_cur, freq_not_cur[col[v]]);

        num_cur[freq_cur[col[v]]]--;
        freq_cur[col[v]]--;
        num_cur[freq_cur[col[v]]]++;
        most_cur = num_cur[most_cur] > 0 ? most_cur : most_cur - 1;
    }
}

void add(int u, int x){
    if(x == 1) exchange_to_not_cur(u);
    else exchange_to_cur(u);
    for(auto v : new_adj[u])
        if(v.st != par[u] and !big[v.st])
            add(v.st, x);
}

void sack(pair<int, int> u, bool keep){
    pair<int, pair<int, int>> big_child = {-1, {-1, -1}};
    
    //find big child
    for(auto v : new_adj[u.st])
        if(v.st != par[u.st])
            big_child = max(big_child, make_pair(sz[v.st], v));

    //go through small childs, but reseting the colors
    for(auto v : new_adj[u.st])
        if(v.st != par[u.st] and v.st != big_child.nd.st)
            sack(v, 0);
    
    //go through big child, keeping the color
    if(big_child.nd.st != -1)
        sack(big_child.nd, 1), big[big_child.nd.st] = true; //big_child marked to not repeat in next dfs
    
    //now our colors have everything from big_child, we need to count again from small child
    add(u.st, 1);

    //now we have all the colors on this subtree
    // db(u.nd _ most_cur _ most_not_cur _ most_scc);
    ans[u.nd] = most_cur + most_not_cur - most_scc;

    //unmark big child
    if(big_child.nd.st != -1) big[big_child.nd.st] = 0;

    //if small child, its time to reset
    if(keep == 0)
        add(u.st, -1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> col[i];
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
            edge[i] = {u, v};
            if(u > v) swap(u, v);
            if(unique_edge.count({u, v})) mult.insert({u, v});
            unique_edge.insert({u, v});
        }
        kosaraju();
        //rebuild graph
        for(int i = 1; i <= m; i++){
            int u = edge[i].first, v = edge[i].second;
            if(scc[u] != scc[v]){
                new_adj[scc[u]].push_back({scc[v], i});
                new_adj[scc[v]].push_back({scc[u], i});
            }
        }
        //get answer for each scc and sum to total
        for(int i = 1; i <= n; i++){
            int s = scc[i];
            if(!vis[s]){
                count(s);
                total += most_cur;
                most_scc = most_cur;
                sack({s, 0}, 0);
                uncount(s, 0);
                num_cur[0] = num_not_cur[0] = 0;
            }
        }
        //answer
        for(int i = 1; i <= m; i++){
            int u = edge[i].first, v = edge[i].second;
            if(scc[u] == scc[v]){
                cout << total;
            }
            else{
                cout << total + ans[i];
            }
            if(i != m) cout << " ";
        }
        cout << "\n";
        
        //clear
        for(int i = 0; i <= n; i++){
            adj[i].clear(), new_adj[i].clear();
            vis[i] = par[i] = scc[i] = sz[i] = 0;
            big[i] = false;
            cmp[i].clear();
            ord[i] = 0;
        }
        for(int i = 0; i <= m; i++){
            ans[i] = 0;
        }
        mult.clear();
        unique_edge.clear();
        ordn = scc_cnt = total = most_cur = most_not_cur = 0;
    }
    return 0;
}