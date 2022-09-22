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
const int N = 1e3+5;

bool ge(ld x, ld y) { return x + EPS > y; }
bool le(ld x, ld y) { return x - EPS < y; }
bool eq(ld x, ld y) { return ge(x, y) and le(x, y); }

int n, l, mark[N*N];
vector<pair<pair<ld, int>, int>> intervals;
ld x[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> l;
    for(int i = 0; i < n; i++) cin >> x[i];
    int all = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            all++;
            int k = 1;
            ld dist = fabs(x[i] - x[j]);
            ld min_v = dist / (l + 1), max_v = dist / (l - 1);
            intervals.push_back({{dist, 1}, all});
            while(ge(max_v, 0.1)){
                if(le(min_v, 10.0)){
                    intervals.push_back({{min_v, 1}, all});
                    intervals.push_back({{max_v, -1}, all});
                }
                k++;
                min_v = dist / (k * l + 1), max_v = dist / (k * l - 1);
            }
        }
    }
    intervals.push_back({{-INF, 1}, all}), intervals.push_back({{0.1, -1}, all});
    intervals.push_back({{10.0, 1}, all});
    sort(intervals.begin(), intervals.end());
    int cnt = 0;
    ld ans = -INF;
    for(auto p : intervals){
        if(p.st.nd == -1){
            if((--mark[p.nd]) == 0) cnt--;
            if(cnt == 0) ans = max(ans, p.st.st);
        }
        else{
            if(cnt == 0) ans = max(ans, p.st.st);
            if((++mark[p.nd]) == 1) cnt++;
        }
    }
    if(eq(ans, -INF)) cout << "no fika\n";
    else cout << setprecision(15) << fixed << ans << "\n";
    return 0;
}