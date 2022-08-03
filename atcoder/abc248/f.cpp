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
const int N = 3e3+5;

ll dp[2][N][N];
ll n, p;

ll calc(int idx, int pos, int used){
    if(used < 0) return 0;
    if(dp[idx][pos][used] != -1) return dp[idx][pos][used];
    if(pos == n){
        if(used > 1) return dp[idx][pos][used] = 0;
        if(used == 1){
            if(idx == 1) return dp[idx][pos][used] = 0;
            return dp[idx][pos][used] = 1;
        }
        return dp[idx][pos][used] = 1;
    }
    ll cur = 0;
    if(idx == 0){
        cur = (cur + calc(0, pos + 1, used)) % p;
        cur = (cur + calc(0, pos + 1, used - 1))%p;
        cur = (cur + (2 * calc(1, pos + 1, used - 2))%p)%p;
        cur = (cur + (2 * calc(1, pos + 1, used - 1))%p)%p;
    }
    else{
        cur = (cur + calc(0, pos + 1, used)) % p;
        cur = (cur + calc(1, pos + 1, used - 1)) % p;
        cur = (cur + (2 * calc(1, pos + 1, used - 1))%p) % p;
    }
    return dp[idx][pos][used] = cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    memset(dp, -1, sizeof(dp));
    
    for(int i = 1; i < n; i++){
        cout << calc(1, 1, i) << "\n";
    }
    return 0;
}