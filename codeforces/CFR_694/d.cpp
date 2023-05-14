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

ll sq[N], a[N], d[N], c[N], mk[N];

void calc(){
    int cnt = 0;
    for(ll i=1;i<=N;i++){
        sq[cnt++] = i*i;
        if(i <= 1000) mk[i*i]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    calc();
    while(t--){
        int n;
        cin >> n;
        vector<ll> v;
        ll mx = 0, ans = 0, wans = 0;
        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            mx = max(x,mx);
            v.pb(x);
            a[x]++;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int cnt = 0;
            ll cur = v[i];
            bool ok = true;
            if(i and v[i] == v[i-1]) ok = false;
            while(ok){
                ll div = (cur*cur)/v[i];
                ll md = (cur*cur)%v[i];
                if(div > mx) break; 
                if(!(md)){
                    if(a[div]){
                        d[v[i]] += a[div];
                        if(!mk[div]) c[v[i]] += a[div];
                        if(cur != v[i]){
                            d[div] += a[v[i]];
                            if(!mk[v[i]]) c[div] += a[v[i]];
                        }
                    }
                }
                cur++;
            }
            if(!(c[v[i]]%2)) wans++;
            ans = max(ans,d[v[i]]);
        }
        int q;
        cin >> q;
        wans = max(ans,wans);
        for(int i=0;i<q;i++){
            ll w;
            cin >> w;
            if(w) cout << wans << "\n";
            else cout << ans << "\n";
        }
        for(int i=0;i<n;i++) a[v[i]] = d[v[i]] = c[v[i]] = 0;
    }
    return 0;
}