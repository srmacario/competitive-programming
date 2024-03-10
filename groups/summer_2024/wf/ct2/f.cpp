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
const int N = 505;

int ni, m, a[N], id_variable[N], id_r[N], id_l[N], cnt, src, snk, initial_var[N], last_val[N], var_val[N];
vector<string> ans;

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
    void recover(){
        for(int i = 0; i < list.size(); i += 2){
            //edge (u -> v) is being used with flow cap
            if(list[i^1].cap > 0) {
                int v = list[i].to;
                int u = list[i^1].to;
                if(u >= 1 and u <= m and v >= m + ni + 1 and v <= m + ni + ni){
                    last_val[v - m - ni] = u;
                    initial_var[v - m - ni] = 1;
                }

                if(u >= m + 1 and u <= ni + m and v >= m + ni + 1 and v <= m + ni + ni){
                    last_val[v - m - ni] = u - m;
                }
            }
        }
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
    
    cin >> ni >> m;
    
    for(int i = 1; i <= ni; i++) cin >> a[i];

    //1 -> m: variables;
    for(int i = 1; i <= m; i++) id_variable[i] = ++cnt;
    //m + 1 -> m + n: left values;
    for(int i = 1; i <= ni; i++) id_l[i] = ++cnt;
    //m + n + 1 -> m + 2 * n: right values;
    for(int i = 1; i <= ni; i++) id_r[i] = ++cnt; 
    snk = ++cnt;
    MCMF mcmf(cnt + 5);

    for(int i = 1; i <= ni; i++){
        for(int j = 1; j <= m; j++){
            mcmf.addEdge(id_variable[j], id_r[i], 1, __builtin_popcount(a[i]));
        }

        for(int j = i + 1; j <= ni; j++){
            mcmf.addEdge(id_l[i], id_r[j], 1, (a[i] != a[j]) * __builtin_popcount(a[j]));
        }
        mcmf.addEdge(id_r[i], snk, 1, 0);
        mcmf.addEdge(src, id_l[i], 1, 0);
    }

    for(int j = 1; j <= m; j++){
        mcmf.addEdge(src, id_variable[j], 1, 0);
    }
    auto flw = mcmf.mcmf(src, snk);
    mcmf.recover();
    for(int i = 1; i <= ni; i++){
        string variable, integerVal;
        if(initial_var[i]){
            variable += char(last_val[i] + 'a' - 1), integerVal += to_string(a[i]);
            
            ans.push_back(variable + "=" + integerVal + "\n"), var_val[last_val[i]] = a[i];
            ans.push_back("print(" + variable + ")\n");
        }
        else{
            last_val[i] = last_val[last_val[i]];
            variable += char(last_val[i] + 'a' - 1), integerVal += to_string(a[i]);
            if(var_val[last_val[i]] != a[i])
                ans.push_back(variable + "=" + integerVal + "\n"), var_val[last_val[i]] = a[i];
            ans.push_back("print(" + variable + ")\n");
        }
    }
    cout << ans.size() << " " << flw.nd << "\n";
    for(auto r : ans) cout << r;
    return 0;
}