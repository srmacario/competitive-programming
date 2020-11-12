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
const int N = 2e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set <ll> l1,rf,lf;
        vector <ll> a;
        a.pb(0);
        for(int i=1;i<=n;i++){
            int k;
            cin >> k;
            a.pb(k);
        }
        vector <pll> ans;
        ll rmin = LINF, rmax = -LINF, lmin = LINF, lmax = -LINF;
        for(int i=1;i<n;i++){
            if(lf.count(a[i])) break;
            lf.insert(a[i]);
            lmin = min(a[i],lmin), lmax = max(a[i],lmax);
            if((lmin == 1) and (lmax == i)) l1.insert(i);
        }
        for(int i=1;i<n;i++){
            if(rf.count(a[n-i+1])) break;
            rf.insert(a[n-i+1]);
            rmin = min(a[n-i+1],rmin), rmax = max(a[n-i+1],rmax);
            if((rmin == 1) and (rmax == i)){
                if(l1.count(n-i)) ans.pb({n-i,i});
            }
        }
        cout << ans.size() << "\n";
        for(int i=0;i<ans.size();i++) cout << ans[i].st << " " << ans[i].nd << "\n";
    }
    return 0;
}