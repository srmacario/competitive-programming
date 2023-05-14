#include<bits/stdc++.h>
using namespace std;

int t, f[15];

int main(){
	f[0] = 1;
	for(int i = 1; i <= 10; i++)
		f[i] = f[i - 1] * i;
	scanf("%d", &t);
	while(t){
		printf("%d\n", f[t] / 6);
		scanf("%d", &t);
	}
	return 0;
}