#include<bits/stdc++.h>
using namespace std;

int n,m,x,u,v;
long long w,hadj[30],hhadj[30];
vector<pair<int,long long> > adj[30];

int main(){
	scanf("%d %d %d", &n, &m, &x);
	for(int i=0;i<m;i++){
		scanf("%d %d %lld", &u, &v, &w);
		adj[u].push_back({v,w});
		if(u!=v) adj[v].push_back({u,w});
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		scanf("%d %d", &u, &v);
        if(u == v){
            printf("0\n");
            continue;
        }
		for(int j=0;j<30;j++) hadj[j]=0;
		for(int j=0;j<adj[u].size();j++) hadj[adj[u][j].first]+=adj[u][j].second;
		long long r=hadj[v];
		for(int j=1;j<x;j++){
			for(int k=0;k<30;k++) hhadj[k]=hadj[k];
			for(int k=0;k<30;k++) hadj[k]=0;
			for(int k=0;k<30;k++) for(int l=0;l<adj[k].size();l++) hadj[adj[k][l].first]+=hhadj[k]*adj[k][l].second;
			r+=hadj[v];
		}
		printf("%lld\n", r);
	}
	return 0;
}
