#include<bits/stdc++.h>
using namespace std;

#define ll long long
const long long MOD=1e9+7;

ll n,u,v,c;
long long resp,dpg[100010][6];
vector<pair<ll,ll>> adj[100010];
vector<vector<ll>> fat[6];
vector<ll> h_fat;
bool vis[100010][6];

void make_h_fat(ll t){
 if(h_fat.size()==t){
  fat[t].push_back(h_fat);
  return;
 }
 for(ll i=1;i<=5;i++){
  bool h=false;
  for(ll j=0;j<h_fat.size();j++) if(h_fat[j]==i) h=true;
  if(h) continue;
  h_fat.push_back(i);
  make_h_fat(t);
  h_fat.pop_back();
 }
}

void make_fat(ll t){
 for(ll i=1;i<=5;i++){
  h_fat.clear();
  h_fat.push_back(i);
  make_h_fat(t);
 }
}

long long dfs(ll u, ll father, ll col){
 if(vis[u][col]) return dpg[u][col];
 long long h=0;
 if(adj[u].size()==1) return 1;
 long long dp[6][6];
 for(ll i=0;i<6;i++) for(ll j=0;j<6;j++) dp[i][j]=0;
 for(ll i=0;i<adj[u].size();i++){
  if(adj[u][i].first==father) continue;
  for(ll j=1;j<=5;j++){
   if(j==col) continue;
   if(adj[u][i].second>0 && adj[u][i].second!=j) continue;
   dp[i][j]=dfs(adj[u][i].first,u,j)%MOD;
  }
 }
 for(ll i=0;i<fat[adj[u].size()-1].size();i++){
  long long aux=1;
  bool wat=false;
  for(ll j=0;j<adj[u].size();j++){
   if(adj[u][j].first==father){
    wat=true;
    continue;
   }
   else if(wat) aux=(aux*dp[j][fat[adj[u].size()-1][i][j-1]])%MOD;
   else aux=(aux*dp[j][fat[adj[u].size()-1][i][j]])%MOD;
  }
  h=(h+aux)%MOD;
 }
 dpg[u][col]=h;
 vis[u][col]=true;
 return h;
}

int main(){
 for(ll t=1;t<=5;t++) make_fat(t);
 scanf("%lld", &n);
 for(ll i=0;i<n-1;i++){
  scanf("%lld %lld %lld", &u, &v, &c);
  adj[v].push_back({u,c});
  adj[u].push_back({v,c});
 }
 for(ll i=1;i<=n;i++){
  if(adj[i].size()>5){
   printf("0\n");
   return 0;
  }
  for(ll j=1;j<=5;j++){
   ll h=0;
   for(ll k=0;k<adj[i].size();k++){
    if(adj[i][k].second==j) h++;
   }
   if(h>1){
    printf("0\n");
    return 0;
   }
  }
 }

 for(ll i=0;i<6;i++) for(ll j=0;j<6;j++) dp[i][j]=0;
 for(ll i=0;i<adj[1].size();i++){
  for(ll j=1;j<=5;j++){
   if(adj[1][i].second>0 && adj[1][i].second!=j) continue;
   dp[i][j]=dfs(adj[1][i].first,1,j)%MOD;
  }
 }
 for(ll i=0;i<fat[adj[1].size()].size();i++){
  long long aux=1;
  for(ll j=0;j<adj[1].size();j++) aux=(aux*dp[j][fat[adj[1].size()][i][j]])%MOD;
  resp=(resp+aux)%MOD;
 }
 printf("%lld\n", resp);
 return 0;
}