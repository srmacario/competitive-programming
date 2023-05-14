#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 7;
int t, n, m, a, b, c;
vector<pair<int, pair<int, int>>> edges;
vector<int> milkman;
set<int> dif;
int par[N], sz[N], milk[N];

int find(int a) {
	return par[a] == a ? a : par[a] = find(par[a]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b)
		return;
	if(sz[a] < sz[b])
		swap(a,b);
	sz[a] += sz[b];
	par[b] = a;
}

int main () {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		int count_milkman = 0;
		long long cost = 0;
		
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		
		for(int i = 1; i <= n; i++) {
			cin >> milk[i];
			if(milk[i] == 1) {
				milkman.push_back(i);
				count_milkman++;
			}
		}
		
		for(int i = 0; i < count_milkman-1; i++) {
			unite(milkman[i+1], milkman[i]);
		}
		
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			edges.push_back({c, {a,b}});
		}
		sort(edges.begin(), edges.end());
   		for (auto e : edges) {
       		if(find(e.second.first) != find(e.second.second))
           		unite(e.second.first, e.second.second), cost += e.first;
        }
        
        for(int i = 1; i <=n; i++) {
			dif.insert(find(i));
		}
		if(dif.size() != 1 or count_milkman == 0)
			cout << "impossible\n";
		else
			cout << cost << "\n";

		edges.clear();
		milkman.clear();
		dif.clear();
		for(int i = 1; i <=n; i++)
			milk[i] = 0;
	}
	return 0;
}