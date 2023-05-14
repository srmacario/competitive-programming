#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int,int>
#define piii <int,pii>
#define vi vector<int>
#define pb push_back
#define nd second
#define st first
const ld EPS = 1e-7;
const int N = 50005;

int n,vis[N],ps[N];
pii par[N];
vector <pii> adj[N];
vi ans;

void dfs(int s){
    vis[s] = 1;
    pii carry = {0,0};
    for(auto v : adj[s]) if(!vis[v.nd]){
        if(par[s].st == v.st) ps[v.nd]++, ps[1]++, ps[s]--;
        if(carry.st == v.st) ps[v.nd]++, ps[carry.nd]++;
        carry = v;
        par[v.nd] = {v.st,s};
        dfs(v.nd);
    }
}

void sumdfs(int s){
    vis[s] = 1;
    if(!ps[s]) ans.pb(s);
    for(auto v : adj[s]) if(!vis[v.nd]){
        ps[v.nd] += ps[s];
        sumdfs(v.nd);
    }
}

void print(){
    cout << ans.size() << "\n";
    if(!ans.size()) return;
    for(int i=0;i<ans.size();i++) cout << ans[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({c,b});
        adj[b].pb({c,a});
    }
    int root = 1;
    for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
    dfs(root);
    memset(vis,0,sizeof(vis));
    sumdfs(root);
    sort(ans.begin(),ans.end());
    print();
    return 0;
}