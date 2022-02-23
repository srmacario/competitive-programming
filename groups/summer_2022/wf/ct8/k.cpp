#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int,int> pii;

const int N = 1e3 + 5;

int n, ans, f[N];
set<int> v[N];
set<pii> s;

int find(int a){
	if(f[a] == a)
		return a;
	return f[a] = find(f[a]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b)
		return;
	if(v[a].size() < v[b].size())
		swap(a, b);
	s.erase({v[a].size(), a});
	s.erase({v[b].size(), b});
	for(int i : v[b])
		v[a].insert(i);
	f[b] = a;
	s.insert({v[a].size(), a});
}

pair<pii, int> query(int u){
	printf("1 %d %d\n", v[u].size(), n - v[u].size());
	for(int i : v[u])
		printf("%d ", i);
	printf("\n");
	for(int i = 1; i <= n; i++)
		if(v[u].find(i) == v[u].end())
			printf("%d ", i);
	printf("\n");
	fflush(stdout);
	int uu, vv, ww;
	scanf("%d %d %d", &uu, &vv, &ww);
	return {{uu, vv}, ww};
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		f[i] = i;
		v[i] = {i};
		s.insert({1, i});
	}
	for(int i = 1; i < n; i++){
		auto b = s.begin();
		int u = b->nd;
		pair<pii, int> r = query(u);
		ans += r.nd;
		unite(r.st.st, r.st.nd);
	}
	printf("%d\n", ans);
	return 0;
}