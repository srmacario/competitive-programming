#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;

int n, a, ant, ans, at;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &a);
		if(a>=ant) at++;
		else at=1;
		ans=max(ans,at);
		ant=a;
	}
	printf("%d\n", ans);
	return 0;
}
