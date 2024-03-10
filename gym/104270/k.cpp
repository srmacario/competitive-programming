#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
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
const int N = 1e5+5, X = 1e6;

int ans[N], n, Y;

void sweep(vector<int>& events, vector<pii>& pts, int mult){
    int i = 0, cnt = 0;
    map<int, int> cur_t;
    for(auto pos : events){
        ans[pos] += (int)cnt;
        vector<int> erase;
        while(i < n and pts[i].x == pos){
            int t = abs(mult * X - pts[i].x) + abs(Y - pts[i].y);
            if(mult == 1) ans[pos]++;
            if(cur_t[t] == 0) cnt++;
            if(cur_t[t] == 1) cnt--;
            if(++cur_t[t] > 1) erase.push_back(t);
            i++;
        }
        sort(erase.begin(), erase.end());
        erase.resize(unique(erase.begin(), erase.end()) - erase.begin());
        for(auto e : erase) cur_t.erase(e);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> Y;
        vector<pii> pts(n);
        vector<int> events;
        for(int i = 0; i < n; i++){
            cin >> pts[i].x >> pts[i].y;
            events.push_back(pts[i].x);
            events.push_back(pts[i].x + 1);
            events.push_back(pts[i].x - 1);
        }
        //go right
        sort(pts.begin(), pts.end());
        sort(events.begin(), events.end());
        events.resize(unique(events.begin(), events.end()) - events.begin());
        sweep(events, pts, 1);
        //go left
        reverse(pts.begin(), pts.end());
        reverse(events.begin(), events.end());
        sweep(events, pts, -1);
        int mn = INF, mx = -INF;
        for(auto e : events) mn = min(mn, ans[e]), mx = max(mx, ans[e]), ans[e] = 0;
        cout << mn << " " << mx << "\n";
    }
    return 0;
}
//