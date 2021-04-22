#include<bits/stdc++.h>
using namespace std;
 
const long long MOD=1e9+7;
const int N=1e6+5;
 
int n;
long long d, x[N], y[N];
double ans;
 
int main(){
	scanf("%d %lld", &n, &d);
	for(int i=0;i<n;i++) scanf("%lld", &y[i]);
	for(long long i=0;i<n;i++) x[i]=y[0]+d*i-y[i];
	sort(x,x+n);
	ans=double(x[n-1]-x[0])/2;
	for(long long i=0;i<n;i++) x[i]=y[0]-d*i-y[i];
	sort(x,x+n);
	ans=min(ans,double(x[n-1]-x[0])/2);
	printf("%.1lf\n", ans);
	return 0;
}