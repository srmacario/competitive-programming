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

ll h[N], dp[N];

ll calldp(ll pos){
    if(~dp[pos]) return dp[pos];
    if(pos == 1) return dp[pos] = 0;
    if(pos < 1) return INF;
    return dp[pos] = min(calldp(pos-2) + abs(h[pos] - h[pos-2]), calldp(pos-1) + abs(h[pos] - h[pos-1]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    cout << calldp(n) << "\n";
    return 0;
}