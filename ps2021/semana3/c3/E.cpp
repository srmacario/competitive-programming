#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, p[N], a, b, t;
vector<int> v[11];

void crivo(){
	for(int i = 2; i<=N; i++){
		if(p[i]) continue;
		for(int j = i; j<=N; j+=i) p[j]++;
	}
}


int main(){
	crivo();
	for(int j = 1; j<N; j++) v[p[j]].push_back(j);
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &n);
		printf("%d\n", upper_bound(v[n].begin(),v[n].end(),b)-upper_bound(v[n].begin(),v[n].end(),a-1));
	}
	return 0;
}
