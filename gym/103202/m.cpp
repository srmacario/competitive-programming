#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 20;

void fwht(ll* a, int n){
	for(int l = 1; 2 * l <= n; l <<= 1)
		for(int i = 0; i < n; i += 2 * l)
			for(int j = 0; j < l; j++){
				ll u = a[i + j], v = a[i + l + j];
				a[i + j] = u + v; 
				a[i + l + j] = u - v;
			}
}

int n, m, ans;
ll a[N], k;

int main(){
	scanf("%d %d %lld", &n, &m, &k);
	for(int i = 0; i < n; i++){
		int e = 0;
		for(int j = 0; j < m; j++){
			char c;
			scanf(" %c", &c);
			e = (e << 1) + c - 'A';
		}
		a[e]++;
	}
	
	// Hadamard
	fwht(a, 1 << m);
	for(int i = 0; i < (1 << m); i++)
		a[i] *= a[i];
	fwht(a, 1 << m);
	for(int i = 0; i < (1 << m); i++)
		a[i] /= (1 << m);
		
	// SOS
	for(int i = 0; i < m; i++)
		for(int j = 0; j < (1 << m); j++)
			if(j & (1 << i))
				a[j] += a[j ^ (1 << i)];
	
	// Counting valid subsets
	for(int i = 0; i < (1 << m); i++)
		ans += (a[(1 << m) - 1] - a[i] >= k);
	printf("%d\n", ans);
	return 0;
}