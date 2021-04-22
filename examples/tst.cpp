#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int vis[N], aux[N];
char genero[N];
vector<int> adj[N];
queue<int>q;
main()
{
	int quantidade,v;
	long long x,n,a,b,i;
	scanf("%d",&quantidade);
	for(int k=0;k<quantidade;k++)
	{
		
		aux[k] = 0;
		scanf("%lld %lld",&n,&x);
		for(int j=0;j<x;j=j+1)
		{
			scanf("%lld %lld",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int contador;
		for(i=1;i<=n;i=i+1)
			{
				genero[i]='K';
				vis[i]=0;
			}
		
		for(i=1;i<=n;i=i+1){
            if(vis[i]==0)
                {
                    vis[i]=1;
                    genero[i]='M';
                    q.push(i);
                    while(!q.empty())
                        {
                            
                            int u = q.front();
                            
                            q.pop();
                            if(genero[u]=='F')
                            {
                                contador = 0;
                            }
                            else 
                            {
                                contador = 1;
                            }
                            for(int j=0;j<adj[u].size();j++)
                                {
                                    
                                    v=adj[u][j];
                                    if(vis[v]==0)
                                        {
                                            vis[v]=1;
                                            q.push(v);
                                        }
                                    if(contador==1)
                                        {
                                            if(genero[v]=='M')
                                                {
                                                
                                                        
                                                    aux[k]=1;
                                                        
                
                                                }
                                            else
                                                {
                                                    genero[v]='F';
                                                }
                                        }
                                    else
                                    {
                                        if(genero[v]=='F')
                                        {
                                        
                                            
                                            aux[k]=1;
                                            
                                            
                                        }
                                        else
                                        {
                                            genero[v]='M';
                                        }
                                    }
                                }
                                
                        }
                }

		}
			for(i=1;i<=n;i++)
		{
			adj[i].clear();
		}

	}
	for(i=0;i<quantidade;i++)
	{
        printf("Scenario #%lld:\n", i+1);
		if(aux[i]==0)
		{
			printf("No suspicious bugs found!\n");
		}
		else
		{
			printf("Suspicious bugs found!\n");
		}
	}
	
		
		
}