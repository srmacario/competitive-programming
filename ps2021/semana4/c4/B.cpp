#include<bits/stdc++.h>
using namespace std;

int t;
long long a,b;

long long cubic_root(long long x){
	long long lo=1, hi=1e6, mid;
	while(lo<hi){
		mid=(lo+hi)/2;
		if(mid*mid*mid<x) lo=mid+1;
		else hi=mid;
	}
	return lo;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &a, &b);
		long long crt=cubic_root(a*b);
		if(crt*crt*crt==a*b && a%crt==0 && b%crt==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
