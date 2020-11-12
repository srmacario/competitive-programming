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

ll n,k,a[N],ps[N];
map <ll,ll> idz,idf;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(ll i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a,a+n+1);
    for(ll i = 1;i<=n;i++){
        if(a[i] != a[i-1]) idz[a[i]] = i, idf[a[i-1]] = i-1;
        ps[i] = a[i] + ps[i-1];
    }
    idz[a[1]] = 1, idf[a[n]] = n;
    ll ans = LINF;
    for(ll i = 1;i<=n;i++){
        if((idf[a[i]] - idz[a[i]] + 1) >= k){
            ans = 0;
            break;
        } 
        ll sum1 = LINF, sum2 = LINF, sum3 = LINF;
        if(idf[a[i]] < k) sum1 = LINF;
        else sum1 = (a[i]-1)*(idz[a[i]] - 1) - ps[idz[a[i]] - 1] + (k - (idf[a[i]] - idz[a[i]] + 1));
        if(n - idz[a[i]] + 1 < k) sum2 = LINF;
        else sum2 = -(a[i]+1)*(n - idf[a[i]]) + ps[n] - ps[idf[a[i]]] + (k - (idf[a[i]] - idz[a[i]] + 1));
        ll x1 = (a[i]-1)*(idz[a[i]] - 1) - ps[idz[a[i]] - 1];
        ll x2 = - (a[i]+1)*(n - idf[a[i]]) + ps[n] - ps[idf[a[i]]];
        if(i!= 1 and i!= n) sum3 = (k - (idf[a[i]] - idz[a[i]] + 1)) + x1 + x2;
        ans = min({sum1,sum2,sum3,ans});
    }
    cout << ans << "\n";
    return 0;
}