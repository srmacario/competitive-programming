
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

pair<pii, int> arv[N];
vector<pair<pair<pii, pii>, int>> q50;
vector<pair<pii, pii>> qry;

int n, q, ans[N];

void solve50(){
    vector<int> vx;
    vector<vector<int>>  h(q50.size());
    map<int, vector<pii>> mpx;
    map<int, vector<pair<pii, int>>> ev, ev2;
    for(int i = 0; i < n; i++){
        mpx[arv[i].st.st].push_back({arv[i].st.nd, arv[i].nd});
        vx.push_back(arv[i].st.st);
    }
    for(int i = 0; i < q50.size(); i++){
        ev[q50[i].st.st.st].push_back({{q50[i].st.st.nd, q50[i].st.nd.nd}, i});
        ev2[q50[i].st.nd.st].push_back({{q50[i].st.st.nd, q50[i].st.nd.nd}, i});
        vx.push_back(q50[i].st.st.st);
        vx.push_back(q50[i].st.nd.st);
    }
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    set<pii> es;
    for(int i : vx){
        for(pair<pii, int> j : ev[i]){
            es.insert({j.st.st, -j.nd});
            es.insert({j.st.nd + 1, -j.nd});
        }
        set<pii> s;
        for(pii j : mpx[i])
            s.insert({j.st, j.nd});
        for(pii j : es)
            s.insert(j);
        set<int> hs;
        for(pii j : s){
            if(j.nd > 0)
                for(int k : hs)
                    h[k].push_back(j.nd);
            else if(hs.find(-j.nd) == hs.end())
                hs.insert(-j.nd);
            else
                hs.erase(-j.nd);
        }
        for(pair<pii, int> j : ev2[i]){
            es.erase({j.st.st, -j.nd});
            es.erase({j.st.nd + 1, -j.nd});
        }
    }
    for(int i = 0; i < h.size(); i++){
        sort(h[i].begin(), h[i].end());
        for(int j = 0; j + 2 < h[i].size(); j++)
            if(h[i][j] + h[i][j + 1] > h[i][j + 2])
                ans[q50[i].nd] = true;
    }
}
// O(N(logN)^2)
template<class T = int>
struct Bit2D{
	vector<T> ord;
	vector<vector<T>> fw, coord;
	
	// pts needs all points that will be used in the upd
	// if range upds remember to build with {x1, y1}, {x1, y2 + 1}, {x2 + 1, y1}, {x2 + 1, y2 + 1}
	Bit2D(vector<pair<T, T>> pts){
		sort(pts.begin(), pts.end());
		for(auto a : pts)
			if(ord.empty() || a.first != ord.back())
				ord.push_back(a.first);
		fw.resize(ord.size() + 1);
		coord.resize(fw.size());
		
		for(auto &a : pts)
			swap(a.first, a.second);
		sort(pts.begin(), pts.end());
		for(auto &a : pts){
			swap(a.first, a.second);
			for(int on = std::upper_bound(ord.begin(), ord.end(), a.first) - ord.begin(); on < fw.size(); on += on & -on)
				if(coord[on].empty() || coord[on].back() != a.second)
					coord[on].push_back(a.second);
		}
		
		for(int i = 0; i < fw.size(); i++)
			fw[i].assign(coord[i].size() + 1, 0);
	}

	// point upd
	void upd(T x, T y, T v){
		for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx)
			for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy)
				fw[xx][yy] += v;
	}
	
	// point qry
	T qry(T x, T y){
		T ans = 0;
		for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx)
			for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy)
				ans += fw[xx][yy];
		return ans;
	}

	// range qry
	T qry(T x1, T y1, T x2, T y2){
		return qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1);
	}

	// range upd
	void upd(T x1, T y1, T x2, T y2, T v) {
		upd(x1, y1, v);
		upd(x1, y2 + 1, -v);
		upd(x2 + 1, y1, -v);
		upd(x2 + 1, y2 + 1, v);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    vector<pii> pts(n);
    for(int i = 0; i < n; i++){
        cin >> arv[i].st.st >> arv[i].st.nd >> arv[i].nd;
        pts[i] = arv[i].st;
    }
    sort(arv, arv + n);
    Bit2D bit(pts);
    for(int i = 0; i < n; i++){
        bit.upd(arv[i].st.st, arv[i].st.nd, 1);
    }
    qry.resize(q);
    for(int i = 0; i < q; i++){
        cin >> qry[i].st.st >> qry[i].st.nd >> qry[i].nd.st >> qry[i].nd.nd;
        if(bit.qry(qry[i].st.st, qry[i].st.nd, qry[i].nd.st, qry[i].nd.nd) <= 50) q50.push_back({{qry[i].st, qry[i].nd}, i});
        else ans[i] = true;
    }
    solve50();
    for(int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}