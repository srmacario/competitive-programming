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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ll ans = 0;
        vector<ll> c,k;
        c.pb(0);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            k.pb(x);
        }
        for(int i=1;i<=m;i++){
            ll x;
            cin >> x;
            c.pb(x);
        }
        sort(k.begin(),k.end(),greater<ll>());
        int pos = 1;
        for(auto p : k){
            if(p > pos) ans += c[pos++];
            else ans += c[p];
        }
        cout << ans << "\n";
    }
    return 0;
}