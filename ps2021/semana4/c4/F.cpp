#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n, wt, w, v, dp[N], ans;

int main(){
	scanf("%d %d", &n, &wt);
	for(int i=1;i<N;i++) dp[i]=wt+1;
	while(n--){
		scanf("%d %d", &w, &v);
		for(int i=N-1;i>=v;i--) dp[i]=min(dp[i],dp[i-v]+w);
	}
	for(int i=0;i<N-1;i++) if(dp[i]<=wt) ans=i;
	printf("%d\n", ans);
}
