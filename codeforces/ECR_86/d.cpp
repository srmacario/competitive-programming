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

ll a[N], ps[N], c[N];
vi resp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, ans;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=k;i++) cin >> c[i];
    sort(a, a + n);
    for(int i=0;i<n;i++){
        ps[a[i]]++;
    }
    ans = (ps[k] - 1)/c[k] + 1;
    for(int i=k-1;i>=1;i--){
        ps[i] += ps[i+1];
        ll aux = ((ps[i] - 1)/c[i] + 1);
        ans = max(ans, aux);
    }
    cout << ans << "\n";
    for(int i=0;i<n;i++){
        resp[i%ans].pb(a[i]);
    }
    for(int i=0;i<ans;i++){
        cout << resp[i].size() << " ";
        for(int j=0;j<resp[i].size();j++){
            cout << resp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}