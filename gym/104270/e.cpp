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
const ll LINF = 1e18;
const int N = 1e5+5;

bool check(vector<int>& a, ll m, ll goal){
    int n = a.size();
    vector<ll> cur(n);
    for(int i = 0; i < n - 1; i++){
        m--;
        if(goal > cur[i]){
            cur[i] += a[i];
            if(goal > cur[i]){
                ll upd = 2 * ((goal - cur[i] - 1) / a[i] + 1);
                // db(goal _ cur[i] _ upd _ a[i]);
                cur[i] += (upd / 2) * a[i];
                cur[i + 1] += (upd / 2) * a[i + 1];
                m -= upd;
            }
            if(m < 0) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll l = 0, r = LINF;
        while(l < r){
            ll mid = (l + r + 1) / 2;
            if(check(a, m, mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << "\n";
    }
    return 0;
}