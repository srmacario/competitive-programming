#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int N = 5e4 + 5;

int x, y, w, h, n, sz[N], f[N];
map<int, set<pair<pii, int>>> us[2];
long long ans, a[N];

int find(int c){
	if(f[c] == c)
		return c;
	return f[c] = find(f[c]);
}

void dsunion(int c, int d){
	c = find(c);
	d = find(d);
	if(c == d)
		return;
	if(sz[c] < sz[d])
		swap(c, d);
	sz[c] += sz[d];
	f[d] = c;
	a[c] += a[d];
	ans = max(ans, a[c]);
}

void acres(int q, int a, int mi, int ma, int i){
	auto lb = us[q][a].lower_bound({{mi, mi}, 0});
	if(lb != us[q][a].end())
		if((*lb).st.st <= ma)
			dsunion(lb->nd, i);
	if(lb != us[q][a].begin()){
		lb--;
		if((*lb).st.nd >= mi)
			dsunion(lb->nd, i);
	}
	us[q][a].insert({{mi, ma}, i});
}

int main(){
	while(scanf("%d", &n) != EOF){
		ans = 0;
		us[0].clear();
		us[1].clear();
		for(int i = 0; i < n; i++){
			scanf("%d %d %d %d", &x, &y, &w, &h);
			sz[i] = 1;
			f[i] = i;
			a[i] = w * h;
			ans = max(ans, a[i]);
			acres(0, x, y, y + h, i);
			acres(0, x + w, y, y + h, i);
			acres(1, y, x, x + w, i);
			acres(1, y + h, x, x + w, i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}