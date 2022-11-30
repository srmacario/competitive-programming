#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll el[35];
 
ll c1(int b, int x){
	if(b < 0)
		return 1;
	if(x & (1 << b))
		return el[b] * 2 + c1(b - 1, x);
	else
		return c1(b - 1, x) * 2;
}
 
ll c2(int b, int x, int y){
	if(b < 0)
		return 1;
	if(x & (1 << b)){
		if(y & (1 << b))
			return el[b] + c1(b - 1, x) + c1(b - 1, y);
		else
			return c2(b - 1, x, y) + c1(b - 1, y);
	}
	else if(y & (1 << b))
		return c2(b - 1, x, y) + c1(b - 1, x);
	else
		return c2(b - 1, x, y);
}
 
int t;
 
int main(){
	el[0] = 1;
	for(int i = 1; i <= 30; i++)
		el[i] = el[i - 1] * 3;
	scanf("%d", &t);
	while(t--){
		int x, y;
		scanf("%d %d", &x, &y);
		int bmx, bmy;
		ll ans = 0;
		for(bmx = -1; 1 << (bmx + 1) <= x; bmx++){}
		for(bmy = -1; 1 << (bmy + 1) <= y; bmy++){}
		for(int i = 0; i < bmx; i++){
			if(i - 1 < bmy)
				ans += (ll)(1 + i) * el[i];
			else
				ans += (ll)(1 + i) * c1(i - 1, y);
		}
		if(bmx - 1 < bmy)
			ans += (ll)(1 + bmx) * c1(bmx - 1, x);
		else
			ans += (ll)(1 + bmx) * c2(bmx - 1, x, y);

		for(int i = 0; i < bmy; i++){
			if(i - 1 < bmx)
				ans += (ll)(1 + i) * el[i];
			else
				ans += (ll)(1 + i) * c1(i - 1, x);
		}
		if(bmy - 1 < bmx)
			ans += (ll)(1 + bmy) * c1(bmy - 1, y);
		else
			ans += (ll)(1 + bmy) * c2(bmy - 1, x, y);
		printf("%lld\n", ans);
	}
	return 0;
}