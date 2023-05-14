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

int n;

template<class T = long long>
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
			for(int on = std::upper_bound(ord.begin(), ord.end(), a.first) - ord.begin(); on < fw.size(); on += on & -on) {
				if(coord[on].empty() || coord[on].back() != a.second) {
					coord[on].push_back(a.second);
				}
			}
		}
		for(int i = 0; i < fw.size(); i++) {
			fw[i].assign(coord[i].size() + 1, 0);
		}
	}

	void upd(T x, T y, T v) {
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx) {
			for(int yy = std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy) {
				fw[xx][yy] = max(fw[xx][yy], v);
			}
		}
	}

	T qry(T x, T y) {
		T ans = 0;
		for(int xx = std::upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx) {
			for(int yy = std::upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy) {
				ans = max(ans, fw[xx][yy]);
			}
		}
		return ans;
	}

private:
	std::vector<T> ord;
	std::vector<std::vector<T>> fw, coord;
};

struct event{
    int t, x, y;
    ll val;
    int a, b;
    event(int ini_t = 0, int ini_x = 0, int ini_y = 0, ll ini_val = 0) : t(ini_t), x(ini_x), y(ini_y), val(ini_val), a(t - x - y), b(t + x - y){}
    bool operator <(const event e){
        if(y == e.y){
            if(a == e.a) return b < e.b;
            return a < e.a;
        }
        return y < e.y;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    vector<event> eve;
    vector<pll> pts;
    for(int i = 0; i < n; i++){
        int t, x, y, val;
        cin >> t >> x >> y >> val;
        if((t - x - y >= 0) and (t + x - y >= 0)){
            eve.push_back({t, x, y, val});
            pts.push_back({eve.back().a, eve.back().b});
        }

    }
    Bit2D bit(pts);
    sort(eve.begin(), eve.end());
    ll ans = 0;
    for(auto e : eve){
        ll tmp = bit.qry(e.a, e.b);
        bit.upd(e.a, e.b, tmp + e.val);
        ans = max(ans, tmp + e.val);
    }
    cout << ans << "\n";
    return 0;
}