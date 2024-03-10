#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, p, s, a[N], b[N], src, snk;

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
    
    //Recover Dinic
    set<int> recover(){
        set<int> endpoints;
        for(int i = 0; i < list.size(); i += 2){
            //edge (u -> v) is being used with flow cap
            if(list[i^1].cap > 0) {
                int v = list[i].to;
                int u = list[i^1].to;
                endpoints.insert(v);
            }
        }
        return endpoints;
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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p >> s;

    src = 0, snk = 4 * n + 5; 
    MCMF mcmf(10 * n);

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++){
        int node = 1 + 4 * (i - 1);
        mcmf.addEdge(src, node, 1, 0);

        mcmf.addEdge(node, node + 1, 1, 0);

        mcmf.addEdge(node + 1, node + 2, 1, -a[i]);
        mcmf.addEdge(node + 1, node + 3, 1, -b[i]);

        mcmf.addEdge(node + 2, 4 * n + 1, 1, 0);
        mcmf.addEdge(node + 3, 4 * n + 2, 1, 0);
    }

    mcmf.addEdge(4 * n + 1, snk, p, 0);
    mcmf.addEdge(4 * n + 2, snk, s, 0);

    pii ans = mcmf.mcmf(src, snk);
    cout << -ans.nd << "\n";
    set<int> endpoints = mcmf.recover();
    vector<int> prog, stu;
    for(int i = 1; i <= n; i++){
        int node = 1 + 4 * (i - 1);
        if(endpoints.count(node + 2)) prog.push_back(i);
        if(endpoints.count(node + 3)) stu.push_back(i);
    }
    for(auto pp : prog) cout << pp << " ";
    cout << "\n";
    for(auto ss : stu) cout << ss << " ";
    cout << "\n";
    return 0;
}