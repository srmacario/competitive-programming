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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, w, h;
        cin >> n >> w >> h;
        vector<ll> a(n), b(n), l(n), r(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        l[0] = (b[0] - h) - (a[0] - w);
        r[0] = (b[0] + h) - (a[0] + w);
        if(l[0] > r[0]) swap(l[0], r[0]);
        ll cur_l = l[0], cur_r = r[0];
        bool ok = true;
        for(int i = 1; i < n; i++){
            l[i] = (b[i] - h) - (a[i] - w);
            r[i] = (b[i] + h) - (a[i] + w);
            if(l[i] > r[i]) swap(l[i], r[i]);
            //db(l[i] _ r[i] _ cur_l _ cur_r);
            cur_l = max(l[i], cur_l), cur_r = min(r[i], cur_r);
            if(cur_l > cur_r){
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}