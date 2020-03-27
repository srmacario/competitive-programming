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

ll n, k, ans;

bool win(ll sz){
    ll pwr = sz*sz, rmn = n - sz, mxpwr = 0;
    if((n-sz)%(k-1)) mxpwr = n*
}

ll bin_search(){
    ll l = 1, r = n;
    while(l<=r){
        ll mid = (l+r)/2;
        if(win(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}