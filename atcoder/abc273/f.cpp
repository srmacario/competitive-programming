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
const int N = 5e3+5;

int n, x, wall[2][N];
ll dp[2][N][N];
vector<piii> eve;

ll calc(int side, int pos, int l, int r){
    if(eve[pos].st == x) return 0;
    if(!eve[pos].nd.nd){
        if(wall[1][eve[pos].nd.st] < eve[l].st) return LINF;
        if(wall[1][eve[pos].nd.st] > eve[r].st) return LINF;
    }
    if(dp[side][l][r] != LINF) return dp[side][l][r];
    ll lft = LINF, rgt = LINF;
    if(l > 0) lft = calc(0, l - 1, l - 1, r);
    if(lft != LINF) lft += abs(eve[pos].st - eve[l - 1].st);
    if(r + 1 < eve.size()) rgt = calc(1, r + 1, l, r + 1);
    if(rgt != LINF) rgt += abs(eve[pos].st - eve[r + 1].st);
    return dp[side][l][r] = min(lft, rgt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 63, sizeof(dp));
    cin >> n >> x;
    eve.push_back({0, {0, 2}}), eve.push_back({x, {0, 2}});
    for(int k = 0; k < 2; k++){
        for(int i = 0; i < n; i++){
            cin >> wall[k][i];
            eve.push_back({wall[k][i], {i, k}});
        }
    }
    sort(eve.begin(), eve.end());
    int ini = (lower_bound(eve.begin(), eve.end(), make_pair(0, make_pair(0, 2))) - eve.begin());
    ll ans = calc(0, ini, ini, ini);
    cout << (ans == LINF ? -1 : ans) << "\n";
    return 0;
}