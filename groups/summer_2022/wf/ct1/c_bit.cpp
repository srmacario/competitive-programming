#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
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
typedef vector<int> vi;
typedef vector <vi> vii;

//const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1048576, K = 3e5 + 5;

int a, b, C = ~(1<<31), M = (1<<16)-1;
int r() {
  a = 36969 * (a & M) + (a >> 16);
  b = 18000 * (b & M) + (b >> 16);
  return (C & ((a << 16) + b)) % 1000000;
}

struct pt{
    int x, y, z;
    pt(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z){}
    bool operator < (const pt &p) const{
        return  x < p.x or
                (x == p.x and y < p.y) or
                (x == p.x and y == p.y and z < p.z);
    }
};

pt pts[K];
int ans[K];

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

int main(){
    while(true){
        int m, n, mx = 0;
        scanf("%d%d%d%d", &m, &n, &a, &b);
        if(!m and !n and !a and !b) return 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &pts[i].x , &pts[i].y, &pts[i].z);
            ans[i] = 0;
        }
        for(int i = 0; i < n; i++){
            pts[i + m].x = r();
            pts[i + m].y = r();
            pts[i + m].z = r();
            ans[i + m] = 0;
        }
        n = (m + n);
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++){
            p.push_back({pts[i].y, pts[i].z});
        }
        Bit2D<int> bit(p);
        //ordered by x
        sort(pts, pts + n);
        int i = 0, j = 0, tot = 0;
        do{
            //query for segment with same x
            for(j = i; j < n and (pts[i].x == pts[j].x); j++){
                ans[j] = max(1, 1 + bit.qry(pts[j].y - 1, pts[j].z - 1));
                tot = max(tot, ans[j]);
            }
            //update for segment with same x;
            for(; i < j; i++){
                bit.upd(pts[i].y, pts[i].z, ans[i]);
            }
        } while(i < n);
        printf("%d\n", tot);
    }
    return 0;
}