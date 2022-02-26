#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=2e5+5;

long long n;

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
	if(n==0) printf("1\n");
	else printf("%lld\n", (fexp(2,n-1)+fexp(2,2*n-1))%MOD);
	return 0;
}
