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
const int N = 1e6+5;
 
ll h[N], dp[N];
vector<ll> hi, lo;
 
ll C(ll i, ll j){
    return (h[j] + h[i])*(j - i);
}
 
void compute(ll l, ll r, ll optl, ll optr){
    // stop condition  
    if(l > r) return;
 
    ll mid = (l+r)/2;
    //best : cost, pos
    pair<ll,ll> best = {0,-1};
 
    //searchs best: lower bound to right, upper bound to left
    for(ll i = optl; i <= optr; i++){
        // db(mid _ C(i,mid));
        // db(C(lo[i], hi[mid]));
        best = max(best, {C(lo[i],hi[mid]), i});
    }
    dp[hi[mid]] = best.first;
    ll opt = best.second;
    compute(l, mid-1, optl, opt);
    compute(mid + 1, r, opt, optr);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    hi.pb(n);
    for(int i = n-1; i >= 1; i--){
        if(h[i] > h[hi.back()]) hi.pb(i);
    }
    lo.pb(1);
    for(int i = 2; i <= n; i++){
        if(h[i] > h[lo.back()]) lo.pb(i);
    }
    // reverse(lo.begin(), lo.end());
    compute(0,hi.size()-1,0,lo.size()-1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(dp[i], ans);
    }
    cout << ans << "\n";
    return 0;
}