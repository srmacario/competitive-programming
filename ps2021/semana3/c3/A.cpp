#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;

int t;
long long x;
bool pr[N];
set<long long> tp;

int main(){
    for(long long i=2;i<N;i++){
    	if(pr[i]) continue;
    	tp.insert(i*i);
    	for(int j=i;j<N;j+=i) pr[j]=true;
	}
    scanf("%d", &t);
    while(t--){
    	scanf("%lld", &x);
    	if(tp.find(x)==tp.end()) printf("NO\n");
    	else printf("YES\n");
	}
    return 0;
}
