#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;

int n,u,v,q,p[50010][20],c[50010],rimpar[50010],rpar[50010],h[50010];
vector<int> adj[50010];

int get_p(int pn, int hf){
 if(h[pn]==hf) return pn;
 for(int i=1;i<20;i++) if(h[p[pn][i]]<hf) return get_p(p[pn][i-1],hf);
    return 0;
}

void make_tree(int f, int pn){
 p[pn][0]=f;
 h[pn]=h[f]+1;
 rpar[pn]=c[pn];
 for(int i=0;i<adj[pn].size();i++){
  if(f==adj[pn][i]) continue;
  make_tree(pn,adj[pn][i]);
  rpar[pn]^=rimpar[adj[pn][i]];
  rimpar[pn]^=rpar[adj[pn][i]];
 }
}

int main(){
 scanf("%d", &n);
 for(int i=1;i<=n;i++) scanf("%d", &c[i]);
 for(int i=1;i<n;i++){
  scanf("%d %d", &u, &v);
  adj[u].push_back(v);
  adj[v].push_back(u);
 }
 make_tree(1,1);
 for(int i=1;i<20;i++) for(int j=1;j<=n;j++) p[j][i]=p[p[j][i-1]][i-1];
 scanf("%d", &q);
 while(q--){
  scanf("%d %d", &u, &v);
  if(h[u]>=h[v] || get_p(v,h[u])!=u){
   int hh=h[u],r=rimpar[1];
   if(h[u]&1) r^=rimpar[u];
   else r^=rpar[u];
   if(!(h[v]&1)) hh++;
   if(hh&1) r^=rimpar[u];
   else r^=rpar[u];
   if(r) printf("YES\n");
   else printf("NO\n");
  }
  else printf("INVALID\n");
 }
 return 0;
}