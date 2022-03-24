#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
#define st first
#define nd second

using ll = long long;
using ld = long double;

const int N = 2e5+5, M = 2e9;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
vector<pair<ll, ll>> loose, fix;

template<class T = int>
struct Bit2D{
    public:
        Bit2D(vector<pair<T, T>> pts){
            sort(pts.begin(), pts.end());
            // ord.reserve(pts.size());
            for(auto a : pts){
                if(ord.empty() || a.st != ord.back()){
                    ord.push_back(a.st);
                }
            }
            fw.resize(ord.size() + 1);
            coord.resize(fw.size());
            for(auto &a : pts){
                swap(a.st, a.nd);
            }
            sort(pts.begin(), pts.end());
            for(auto &a : pts){
                swap(a.st, a.nd);
                for(int on = upper_bound(ord.begin(), ord.end(), a.st) - ord.begin(); on < fw.size(); on += on & -on){
                    if(coord[on].empty() || coord[on].back() != a.nd){
                        coord[on].push_back(a.nd);
                    }
                }
            }
            for(int i = 0; i < fw.size(); i++){
                fw[i].assign(coord[i].size() + 1, 0);
            }
        }

        void upd(T x, T y, T v){
            for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx < fw.size(); xx += xx & -xx){
                for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy < fw[xx].size(); yy += yy & -yy){
                    fw[xx][yy] += v;
                }
            }
        }

        T qry(T x, T y){
            T ans = 0;
            for(int xx = upper_bound(ord.begin(), ord.end(), x) - ord.begin(); xx > 0; xx -= xx & -xx){
                for(int yy = upper_bound(coord[xx].begin(), coord[xx].end(), y) - coord[xx].begin(); yy > 0; yy -= yy & -yy){
                    ans += fw[xx][yy];
                }
            }
            return ans;
        }

        T qry(T x1, T y1, T x2, T y2){
            return qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1);
        }

    private:
        vector<T> ord;
        vector<vector<T>> fw, coord;
};

int main() {
    cin >> n >> m;
    loose.resize(n), fix.resize(m);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &loose[i].st, &loose[i].nd);
        int x = loose[i].st, y = loose[i].nd;
        loose[i].st = x - y;
        loose[i].nd = x + y;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &fix[i].st, &fix[i].nd);
        int x = fix[i].st, y = fix[i].nd;
        fix[i].st = x - y;
        fix[i].nd = x + y;
    }
    
    Bit2D bit(fix);

    for(int i = 0; i < m; i++){
        bit.upd(fix[i].st, fix[i].nd, 1);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int l = 0, r = M;
        while(l < r){
            int m = l + (r - l)/2;
            int x = loose[i].st, y = loose[i].nd;
            int tmp = bit.qry(x - m, y - m, x + m, y + m);
            if(tmp) r = m;
            else l = m + 1;
        }
        ans += l;
    }
    printf("%lld\n", ans);
    return 0;
}