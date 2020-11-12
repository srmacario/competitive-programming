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

ll n, a, b, num[50];
vector <ll> lft;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    for(int i=0;i<n;i++) cin >> num[i];
    for(int i=0;i<(1ll<<((n+1)/2));i++){
        ll sum = 0;
        for(int j=0;j<(n+1)/2;j++) if((1ll << j)&i) sum += num[j];
        lft.pb(sum);
    }
    //lft.pb(-LINF), lft.pb(LINF);
    sort(lft.begin(),lft.end());
    ll ans = 0;
    for(ll i=0;i<(1ll<<(n - (n+1)/2));i++){
        ll sum = 0;
        for(ll j=((n+1)/2);j<n;j++) if((1ll << (j - (n+1)/2))&i) sum += num[j];
        ll tans = (upper_bound(lft.begin(),lft.end(),b-sum) - lower_bound(lft.begin(),lft.end(),a-sum));
        //db(tans);
        //db(sum);
        if(tans > 0) ans+=tans;
    }
    //for(int i=0;i<lft.size();i++) db(lft[i]);
    cout << ans;
    return 0;
}