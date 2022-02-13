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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

struct point{
    int x, y;

    point(int a = 0, int b = 0): x(a), y(b){}

    bool operator <(const point &p) const {
        return (x < p.x) or (x == p.x and y < p.y);
    }
};

ld calc(point l, point r, int pos_y){
    //y = mx + n;
    //cout << "pts: " << l.x << " " << l.y << " " << r.x << " " << r.y << "\n";
    ld m = (ld)(r.y - l.y)/(r.x - l.x);
    ld n = r.y - m * r.x;
    //db(m _ n);
    return (1.0 * pos_y - n) / m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<point> pts(n + 1);
    pts[0] = {-1, -1};
    for(int i = 1; i <= n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    point l = {-1, -1}, r = {-1, -1}, peak = {-1, -1}, valley = {-1, -1};
    point dummy = {INF, -1};
    pts.push_back(dummy);
    vector<point> lbounds;
    ld ans = 0;
    for(int i = 1; i < pts.size(); i++){
        point cur = pts[i];
        //if current is greater than the last
        if(cur.y > pts[i - 1].y){
            //if there is not a left bound, make it cur
            //else make cur a right bound
            if(l.x == -1){
                l = cur;
                lbounds.clear();
                lbounds.push_back(l);
            }
            else{
                //calculate areas
                if(r.x == -1){
                    while(lbounds.size() > 1){
                        //change last from lbounds
                        if(lbounds[lbounds.size() - 2].y <= cur.y){
                            ld h = (lbounds[lbounds.size() - 2].y - lbounds.back().y);
                            ld base = (calc(cur, valley, lbounds.back().y) - lbounds.back().x);
                            ld top = (calc(cur, valley, lbounds[lbounds.size() - 2].y) - lbounds[lbounds.size() - 2].x);
                            ans += (base + top) * h / 2;
                            lbounds.pop_back();
                        }
                        else{
                            ld h = (cur.y - lbounds.back().y);
                            ld base = (calc(cur, valley, lbounds.back().y) - lbounds.back().x);
                            ld top = (cur.x - calc(lbounds[lbounds.size() - 2], lbounds.back(), cur.y));
                            ans += (base + top) * h / 2;
                            break;
                        }
                    }
                }
                else{
                    //part 1
                    if(lbounds.size() > 1){
                        if(cur.y > lbounds[lbounds.size() - 2].y){
                            ld h = lbounds[lbounds.size() - 2].y - r.y;
                            ld base = (r.x - calc(lbounds[lbounds.size() - 2], lbounds.back(), r.y));
                            ld top = calc(r, cur, lbounds[lbounds.size() - 2].x) - lbounds[lbounds.size() - 2].x;
                            ans += (base + top) * h / 2;
                            lbounds.pop_back();
                        }
                        else{
                            ld h = cur.y - r.y;
                            ld base = (r.x - calc(lbounds[lbounds.size() - 2], lbounds.back(), r.y));
                            ld top = (cur.x - calc(lbounds[lbounds.size() - 2], lbounds.back(), cur.y));
                            ans += (base + top) * h / 2;
                        }
                    }
                    while(lbounds.size() > 1 and lbounds.back().y < cur.y){
                        if(lbounds[lbounds.size() - 2].y <= cur.y){
                            ld h = (lbounds[lbounds.size() - 2].y - lbounds.back().y);
                            ld base = (calc(cur, r, lbounds.back().y) - lbounds.back().x);
                            ld top = (calc(cur, r, lbounds[lbounds.size() - 2].y) - lbounds[lbounds.size() - 2].x);
                            ans += (base + top) * h / 2;
                            lbounds.pop_back();
                        }
                        else{
                            ld h = (cur.y - lbounds.back().y);
                            ld base = (calc(cur, r, lbounds.back().y) - lbounds.back().x);
                            ld top = (cur.x - calc(lbounds[lbounds.size() - 2], lbounds.back(), cur.y));
                            ans += (base + top) * h / 2;
                            break;
                        }
                    }
                }
                //change r to cur
                r = cur;
            }
        }
        // cur decreased
        if(cur.y < pts[i - 1].y){
            //no right bound, still going down
            if(r.x == -1){
                valley = cur;
                lbounds.push_back(cur);
            }
            //has right bound
            else{
                //change bounds
                valley = cur;
                lbounds.clear();
                l = pts[i - 1];
                lbounds.push_back(l);
                lbounds.push_back(cur);
                r = {-1, -1};
            }
        }
        //change new last bigger
        if(cur.y >= pts[i - 1].y){
            peak = cur;
        }
    }
    cout << setprecision(15) << fixed << ans << "\n";
    return 0;
}