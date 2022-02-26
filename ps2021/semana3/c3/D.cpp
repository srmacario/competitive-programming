#include<bits/stdc++.h>
using namespace std;

const long long MOD=1e9+7;
const int N=2e5+5;

long long b;
int ans;

int main(){
	scanf("%lld", &b);
	for(long long i=1;i*i<=b;i++){
		if(b%i) continue;
		ans++;
		if(b/i!=i) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
