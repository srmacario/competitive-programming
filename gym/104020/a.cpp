#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1505;

int n, k;
ll sum, a[N], x;
ld ans;

int main(){
	scanf("%d %d %lld", &n, &k, &x);
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		sum += a[i];
	}

	sort(a, a + n);
	ans = (ld)abs(sum - x * n) / n;
	
    ll hans = 1e15;
    for(int i = 0; i < n; i++)
		hans = min(hans, abs(sum - a[i] - x * (n - 1)));
    ans = min(ans, (ld)hans / (n - 1));

	if(k >= 2){
		ll hans = 1e15;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				hans = min(hans, abs(sum - a[i] - a[j] - x * (n - 2)));
		ans = min(ans, (ld)hans / (n - 2));
	}
	if(k >= 3){
		ll hans = 1e15;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
					hans = min(hans, abs(sum - a[i] - a[j] - a[k] - x * (n - 3)));
		ans = min(ans, (ld)hans / (n - 3));
	}
	if(k == 4){
		ll hans = 1e15;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				int p1 = 0, p2 = n - 1;
				while(p1 < p2){
					if(p1 == i || p1 == j)
						p1++;
					else if(p2 == i || p2 == j)
						p2--;
					else{
						hans = min(hans, abs(sum - a[p1] - a[p2] - a[i] - a[j] - x * (n - 4)));
						if(sum - a[p1] - a[p2] - a[i] - a[j] > x * (n - 4))
							p2--;
						else
							p1++;
					}
				}
			}
		ans = min(ans, (ld)hans / (n - 4));
	}
	printf("%.9Lf", ans);
	return 0;
}