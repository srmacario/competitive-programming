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
const int N = 2e5+5;

int n;
vector<pii> p;

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
    cin >> n;
    p.resize(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].nd;
        p[i].st = i + 1 - p[i].nd;
        p[i].nd += i + 1;
    }
    Bit2D grid(p);
    for(int i = 0; i < n; i++) grid.upd(p[i].st, p[i].nd, 1);
    for(int i = 0; i < n; i++){
        grid.upd(p[i].st, p[i].nd, -1);
        int l = 0, r = 2 * n;
        while(l < r){
            int m = (l + r) / 2;
            if(grid.qry(p[i].st - m, p[i].nd - m, p[i].st + m, p[i].nd + m)) r = m;
            else l = m + 1;
        }
        cout << l << "\n";
        grid.upd(p[i].st, p[i].nd, 1);
    }
    return 0;
}