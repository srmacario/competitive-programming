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

ll n,x;
vector <ll> d, ps, dsum;

ll busca(ll i){
    ll l = 1, r = i;
    while(l<r){
        ll mid = (l+r)/2;
        if(ps[i] - ps[mid-1] == x) return mid;
        else if(ps[i] - ps[mid-1] < x) r = mid;
        else l = mid + 1; 
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    d.pb(0), ps.pb(0), dsum.pb(0);
    for(ll i=0;i<n;i++){
        ll k;
        cin >> k;
        d.pb(k);
        ps.pb(k + ps[i]);
        ll sum = ((d[i+1] + 1)*(d[i+1]))/2;
        dsum.pb(dsum[i] + sum);
    }
    for(ll i=n+1;i<=2*n;i++){
        d.pb(d[i-n]);
        ps.pb(d[i] + ps[i-1]);
        ll sum = ((d[i] + 1)*(d[i]))/2;
        dsum.pb(dsum[i-1] + sum);
    }
    ll ans = 0;
    for(ll i=n+1;i<=2*n;i++){
        ll p = busca(i);
        ll rest = x - (ps[i] - ps[p-1]);
        ll partans = dsum[i] - dsum[p-1];
        if(rest < 0){
            rest = -rest;
            partans -= (rest*(rest+1))/2;
        }
        else{
            partans += (rest*(2*d[p-1] - rest + 1))/2;
        }
        ans = max(ans,partans);
    }
    cout << ans << "\n";
    return 0;
}