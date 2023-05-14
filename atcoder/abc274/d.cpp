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
const int N = 2e4 + 5, M = 1e4 + 2;

int n, x, y;
bitset<N> dp[2][N];
vector<int> a[2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        a[i%2].push_back(k);
    }
    dp[0][0][M] = dp[1][0][M] = 1;
    x += M, y += M;
    for(int b = 0; b < 2; b++){
        for(int i = 0; i < a[b].size(); i++){
            bitset<N> cur = dp[b][i];
            if(b == 0 and i == 0 ) dp[b][i + 1] = (cur << a[b][i]);
            else dp[b][i + 1] = (cur << a[b][i]) | (cur >> a[b][i]);
        }
    }
    if(dp[0][a[0].size()][x] and dp[1][a[1].size()][y]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}