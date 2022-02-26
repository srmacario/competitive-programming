#include<bits/stdc++.h>
 
using namespace std;
 
int a1, a2, ans;
	
int main(){
	scanf("%d %d", &a1, &a2);
	for(ans=0; a1>2 || a2>2; ans++){
		if(a1<a2) a1+=3;
		else a2+=3;
		a1-=2;
		a2-=2;
	}
	if(a1>=2 || a2>=2) ans++;
	printf("%d\n", ans);
	return 0;
}
