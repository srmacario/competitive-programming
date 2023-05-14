#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

vii rg, memo;

int dp(int l, int r){
    if(~memo[l][r]) return memo[l][r];
    memo[l][r] = 0;
    if(l > r) return memo[l][r];
    //insert that segment, ignoring equal segments
    bool ins = count(rg[l].begin(), rg[l].end(), r);
    //solve for (l,r) and (l+1,r), if possible
    int right = 0;
    if(l+1 <=r) right = dp(l+1,r);
    memo[l][r] = max(memo[l][r], (ins + right));
    //insert that segment and for each r associated to l, divide and conquer, solve for (l,cur) and (cur+1,r)
    for(auto cur: rg[l]){
        if(cur>=r) continue;
        int right_cur = 0;
        if(cur+1 <=r) right_cur = dp(cur+1,r);
        int left_cur = dp(l,cur);
        memo[l][r] = max(memo[l][r], (ins + left_cur + right_cur));
    }
    return memo[l][r];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi l(n), r(n), coord;
        for(int i=0;i<n;i++){
            cin >> l[i] >> r[i];
            coord.pb(l[i]), coord.pb(r[i]);
        }
        //compress coordinates
        sort(coord.begin(),coord.end());
        coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
        for(int i=0; i<n; i++){
            l[i] = lower_bound(coord.begin(),coord.end(),l[i]) - coord.begin();
            r[i] = lower_bound(coord.begin(),coord.end(),r[i]) - coord.begin();
        }
        memo = vii(coord.size(), vi(coord.size(),-1));
        rg = vii(coord.size());
        //map each r to a l
        for(int i=0;i<n;i++) rg[l[i]].pb(r[i]);
        cout << dp(0,coord.size()-1) << "\n";
    }
    return 0;
}