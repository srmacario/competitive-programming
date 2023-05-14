#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int n, m, q;

#define nd second
#define st first

vector<pair<int, int>> adj[N];
int dist[N];

void dijkstra(int s) {
	priority_queue<pair<int, int>> pq;
	for(int i = 0; i < n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
	pq.push({0, s});

	while(!pq.empty()) {
		long long ud = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(dist[u] < ud)
			continue;
		for(auto x: adj[u]) {
			int v = x.first;
			long long w = x.second;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;

				pq.push({-dist[v], v});
			}
		}
	}
}

int main () {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		int a, b, l;
		cin >> a >> b >> l;
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
	}
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		dijkstra(x);
		pair<int, int> ans = {0, 1};
		for(int i = 0; i < n; i++) {
			if(dist[i] == INF) continue;
			if(dist[i] > ans.st) ans.st = dist[i], ans.nd = 1;
			else if(dist[i] == ans.st) ans.nd++;
		}
		cout << ans.st << " " << ans.nd << "\n";
	}
	return 0;
}