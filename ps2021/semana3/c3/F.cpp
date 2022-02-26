#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=2e5+5;

long long n, ans;

long long fexp(long long x, long long y){
	long long r=1;
	while(y){
		if(y&1) r=r*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return r;
}

int main(){
	scanf("%lld", &n);
	ans=1;
	for(long long i=2;i<=2*n-1;i++) ans=ans*i%MOD;
	for(long long i=2;i<=n;i++) ans=ans*fexp(i,MOD-2)%MOD;
	for(long long i=2;i<=n-1;i++) ans=ans*fexp(i,MOD-2)%MOD;
	printf("%lld\n", (2*ans-n+MOD)%MOD);
	return 0;
}
