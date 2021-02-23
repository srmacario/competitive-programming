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

ll calc(ll num){
    ll ans = 0;
    for(ll i=0;i<=60;i++){
        ll q = num/(1ll<<(i+1));
        ans += q*(1ll<<(i));
        ll cur = (q+1)*(1ll<<(i+1));
        cur -= (1ll<<i);
        ans += max(num-cur+1,0ll);
        if(!q) break;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    while(cin >> a >> b){
        cout << (calc(b) - calc(a-1)) << "\n";
    }
    return 0;
}