#include <bits/stdc++.h>
 
using namespace std;

#define LINF 0x3f3f3f3f3f3f3f3f
 
typedef long long ll;

const int N=1e5+5;
 
ll dist[N];
ll ant[N];

vector<pair<int,ll>> adj[N];
priority_queue<pair<ll,ll>> pq;

vector<ll> recover(int s){
    vector<ll> ans;
    ans.push_back(s);
    while(ant[s]!=s){
        s = ant[s];
        ans.push_back(s);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin>>n>>m;
 
    for(int i=0;i<m;i++){
        ll a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    
    for(int i = 0; i < N; i++) dist[i] = LINF;
    ant[1]=1;
    dist[1]=0;
    pq.push({0,1});

    while (!pq.empty()) {
        ll ud = -pq.top().first;
        ll u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            ll v = x.first;
            ll w = x.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                ant[v]=u;
                pq.push({-dist[v], v});
            }
        }
    }

    if(dist[n]<LINF){
        vector<ll> path = recover(n); 
        for(int i = path.size()-1 ; i >= 0 ; i--) cout<<path[i]<<" ";   
    }
    else cout<<"-1";

    return 0;
}