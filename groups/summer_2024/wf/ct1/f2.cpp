#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T = int>
class MCMF {
public:
	struct Edge {
		Edge(int a, T b, T c) : to(a), cap(b), cost(c) {}
		int to;
		T cap, cost;
	};

	MCMF(int size) {
		n = size;
		edges.resize(n);
		pot.assign(n, 0);
		dist.resize(n);
		visit.assign(n, false);
	}

	std::pair<T, T> mcmf(int src, int sink) {
		std::pair<T, T> ans(0, 0);
		if(!SPFA(src, sink)) return ans;
		fixPot();
		// can use dijkstra to speed up depending on the graph
		while(SPFA(src, sink)) {
			auto flow = augment(src, sink);
			ans.first += flow.first;
			ans.second += flow.first * flow.second;
			fixPot();
		}
		return ans;
	}

	void addEdge(int from, int to, T cap, T cost) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap, cost));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, 0, -cost));
	}
    int find(int x) {
        for(auto e : edges[x]) {
            if(e & 1 and list[e].cap != 0) {
                return list[e].to;
            }
        }
        assert(false);
        return -1;
    } 
private:
	int n;
	std::vector<std::vector<int>> edges;
	std::vector<Edge> list;
	std::vector<int> from;
	std::vector<T> dist, pot;
	std::vector<bool> visit;

	std::pair<T, T> augment(int src, int sink) {
		std::pair<T, T> flow = {list[from[sink]].cap, 0};
		for(int v = sink; v != src; v = list[from[v]^1].to) {
			flow.first = std::min(flow.first, list[from[v]].cap);
			flow.second += list[from[v]].cost;
		}
		for(int v = sink; v != src; v = list[from[v]^1].to) {
			list[from[v]].cap -= flow.first;
			list[from[v]^1].cap += flow.first;
		}
		return flow;
	}

	std::queue<int> q;
	bool SPFA(int src, int sink) {
		T INF = std::numeric_limits<T>::max();
		dist.assign(n, INF);
		from.assign(n, -1);
		q.push(src);
		dist[src] = 0;
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			visit[on] = false;
			for(auto e : edges[on]) {
				auto ed = list[e];
				if(ed.cap == 0) continue;
				T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
				if(toDist < dist[ed.to]) {
					dist[ed.to] = toDist;
					from[ed.to] = e;
					if(!visit[ed.to]) {
						visit[ed.to] = true;
						q.push(ed.to);
					}
				}
			}
		}
		return dist[sink] < INF;
	}

	void fixPot() {
		T INF = std::numeric_limits<T>::max();
		for(int i = 0; i < n; i++) {
			if(dist[i] < INF) pot[i] += dist[i];
		}
	}
};

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();

    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    MCMF<int> mcmf(3 * n + 50);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(x[i] == x[j]) {
                mcmf.addEdge(i + n + 10, j + 5, 1, 0);
            }
            else {
                mcmf.addEdge(i + n + 10, j + 5, 1, __builtin_popcountll(x[j]));
            }
        }
        mcmf.addEdge(0, i + 5, 1, __builtin_popcountll(x[i]));
        mcmf.addEdge(i + 5, i + n + 10, 1, -1e6);
        mcmf.addEdge(i + n + 10, 2 * n + 15, 1, 0);
    }
    mcmf.addEdge(0, 2 * n + 15, 50, 0);
    int mnf = m;
    mcmf.addEdge(2 * n + 16, 0, mnf, 0);
    auto fuck = mcmf.mcmf(2 * n + 16, 2 * n + 15);
    vector<int> pos(m + 1, -1);
    vector<array<int, 3>> ans;
    int var = 1;
    for(int i = 0; i < n; i++) {
        int k = mcmf.find(i + 5);
        if(k == 0) {
            pos[var] = i + n + 10;
            ans.push_back({0, var, x[i]});
            ans.push_back({1, var++, 0});
        } else {
            int qual = -1;
            for(int i = 1; i <= m; i++) {
                if(pos[i] == k) {
                    qual = i;
                    break;
                }
            }
            int p = k - n - 10;
            if(x[i] == x[p]) {
                ans.push_back({1, qual, 0});
            } else {
                ans.push_back({0, qual, x[i]});
                ans.push_back({1, qual, 0});
            }
            pos[qual] = i + n + 10;
        }
    }
    cout << ans.size() << " " << fuck.second + n * 1e6 << endl;

    for(auto [a, b, c] : ans) {
        if(a == 0) {
            cout << (char)('a' + b - 1) << "=" << c << endl;
        } else {
            cout << "print(" << (char)('a' + b - 1) << ")" << endl;
        }
    }

    end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms\n";
}