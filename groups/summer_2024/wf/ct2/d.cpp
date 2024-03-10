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
const int N = 5e3+5;


int n, m, d, k[N], p[N], c[N], src, snk;
template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			// maybe random shuffle edges against bad cases?
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(src, sink))) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap, T other = 0) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, other));
	}

	bool inCut(int u) const { return h[u] < n; }
	int size() const { return n; }
private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow = 1e9) {
		if(flow == 0) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < (int) edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
				if(list[a].cap == 0) {
					continue;
				}
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    cin >> d;
    set<int> removed;
    for(int i = 1; i <= d; i++){
        cin >> k[i];
        removed.insert(k[i]);
    }
    
    //src e snk nodes
    src = 5 * N - 2, snk = 5 * N - 1;
    Dinic dinic(5 * N);
    //power: 0 -> N + 1
    //club:  3 * N + 1 -> 3 * N + N

    //adding edge src => club
    for(int i = 3 * N + 1; i <= 3 * N + N; i++) dinic.addEdge(src, i, 1);

    //adding mex 0 to snk
    dinic.addEdge(0, snk, 1);

    int mex = 0;
    for(int i = 1; i <= n; i++){
        if(removed.count(i)) continue;
        dinic.addEdge(3 * N + c[i], p[i], 1);
    }
    
    vector<int> resp;
    for(int i = d; i >= 1; i--){
        int add_flow = true;
        while(add_flow){
            add_flow = dinic.maxFlow(src, snk);
            for(int j = 1; j <= add_flow; j++){
                mex++;
                dinic.addEdge(mex, snk, 1);
            }
        }
        resp.push_back(mex);
        dinic.addEdge(3 * N + c[k[i]], p[k[i]], 1);
    }
    reverse(resp.begin(), resp.end());
    for(int i = 0; i < d; i++) cout << resp[i] << "\n";
    return 0;
}