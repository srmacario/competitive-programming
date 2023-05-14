#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

template<class T = int>
struct Bit2D {
public:
	Bit2D(std::vector<std::pair<T, T>> pts) {
		std::sort(pts.begin(), pts.end());
		for(auto a : pts) {
			if(ord.empty() || a.first != ord.back()) {
				ord.push_back(a.first);
			}
		}
		fw.resize(ord.size() + 1);
		coord.resize(fw.size());
		for(auto &a : pts) {
			std::swap(a.first, a.second);
		}
		std::sort(pts.begin(), pts.end());
		for(auto &a : pts) {
			std::swap(a.first, a.second);
			for(int on = (int)(std::upper_bound(ord.begin(), ord.end(), a.first) - ord.begin()); on < (int)fw.size(); on += (on & -on)) {
				if(coord[on].empty() || coord[on].back() != a.second) {
					coord[on].push_back(a.second);
				}
			}
		}
		for(int i = 0; i < (int)fw.size(); i++) {
			fw[i].assign(coord[i].size() + 1, 0);
		}
	}

	void upd(T x, T y, T v) {
		for(int xx = (int)(std::upper_bound(ord.begin(), ord.end(), x) - ord.begin()); xx < (int)fw.size(); xx += (xx & -xx)) {
			for(int yy = (int)(std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin());yy <  (int)fw[xx].size(); yy += (yy & -yy)) {
				fw[xx][yy] += v;
			}
		}
	}

	T qry(T x, T y) {
		T ans = 0;
		for(int xx = (int)(std::upper_bound(ord.begin(), ord.end(), x) - ord.begin()); xx > 0; xx -= (xx & -xx)) {
			for(int yy = (int)(std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin()); yy > 0; yy -= (yy & -yy)) {
				ans += fw[xx][yy];
			}
		}
		return ans;
	}

	T qry(T x1, T y1, T x2, T y2) {
		return qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1);
	}

	void upd(T x1, T y1, T x2, T y2, T v) {
		upd(x1, y1, v);
		upd(x1, y2 + 1, -v);
		upd(x2 + 1, y1, -v);
		upd(x2 + 1, y2 + 1, v);
	}
private:
	std::vector<T> ord;
	std::vector<std::vector<T>> fw, coord;
};

int q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pii> pts, qry, rect_pts;
    vector<pair<pii, pii>> rect;
    cin >> q;
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        if(op == 1){
            pii p;
            cin >> p.st >> p.nd;
            pts.push_back(p);
            rect_pts.push_back(p);
            qry.push_back({1, pts.size() - 1});
        }
        else{
            pii p1, p2;
            cin >> p1.st >> p1.nd >> p2.st >> p2.nd;
            rect.push_back({p1, p2});
            rect_pts.push_back(p1);
            rect_pts.push_back(p2);
            rect_pts.push_back({p1.st, p2.nd + 1});
            rect_pts.push_back({p2.st + 1, p1.nd});
            rect_pts.push_back({p2.st + 1, p2.nd + 1});
            qry.push_back({2, rect.size() - 1});
        }
    }

    Bit2D bit_pts(pts);
    Bit2D bit_rect(rect_pts);

    ll ans = 0;
    for(auto e : qry){
        if(e.st == 1){
            bit_pts.upd(pts[e.nd].st, pts[e.nd].nd, 1);
            ans += bit_rect.qry(pts[e.nd].st, pts[e.nd].nd);
        }
        else{
            bit_rect.upd(rect[e.nd].st.st, rect[e.nd].st.nd, rect[e.nd].nd.st, rect[e.nd].nd.nd, 1);
            ans += bit_pts.qry(rect[e.nd].st.st, rect[e.nd].st.nd, rect[e.nd].nd.st, rect[e.nd].nd.nd);
        }
        cout << ans << "\n";
    }
    return 0;
}