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
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e5+5;

int dp[N], par[N];
vector<pii> interval[N];
set <piii> s;

void update_interval(int l, int r, int i){
    vector<piii> add, rem;
    auto it = s.lower_bound({{l, 0}, 0});
    if(it != s.begin()) it--;
    for(; it != s.end(); it++){
        int ll = it->st.st;
        int rr = it->st.nd;
        int j = it->nd;
        //if interval overlaps, update dp
        if((l >= ll and l <= rr) or (ll >= l and ll <= r)){
            if(j != i){
                if(dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1, par[i] = j;
            }
        }
        //removing old overlapping intervals
        if(ll > r) break;
        if(rr < l) continue;
        if(ll < l){
            add.pb({{ll, l-1}, j});
        }
        if(rr > r){
            add.pb({{r+1, rr}, j});
        }
        rem.pb(*it);
    }
    //adding new interval
    add.pb({{l, r}, i});
    for(auto x : rem) s.erase(x);
    for(auto x : add) s.insert(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int j, l, r;
        cin >> j >> l >> r;
        interval[j].pb({l, r});
    }
    //sort intervals
    for(int i = 1; i <= n; i++) sort(interval[i].begin(), interval[i].end());
    //update intervals and update dp
    for(int i = 1; i <= n; i++){
        for(auto p : interval[i]){
            update_interval(p.st, p.nd, i);
        }
    }
    //pick best answer
    pii mx = {0, 0};
    for(int i = 1; i <= n; i++){
        mx = max(mx, {dp[i], i});
    }
    //recover lines from best answer
    int cur = mx.nd;
    set<int> bst, ans;
    while(cur){
        bst.insert(cur);
        cur = par[cur];
    }
    //pick lines which are not from the best answer
    for(int i = 1; i <= n; i++){
        if(!bst.count(i)) ans.insert(i);
    }
    //print answer
    cout << ans.size() << "\n";
    for(auto p : ans) cout << p << " ";
    cout << "\n";
    return 0;
}