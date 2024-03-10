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
const int N = 105, K = (1 << 10);

int n, m, c[N][N], ans = INF, inii, inij, fimi, fimj;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool dp[K][N][N];

int bfs(int i, int j){
    queue<pair<int, pii>> q;
    q.push({1 << c[i][j], {i, j}});
    dp[1 << c[i][j]][i][j] = true;
    while(!q.empty()){
        int val = q.front().st;
        int posi = q.front().nd.st, posj = q.front().nd.nd;
        q.pop();
        if(posi == fimi and posj == fimj) ans = min(ans, __builtin_popcount(val));
        for(int k = 0; k < 4; k++){
            int nxti = posi + dx[k], nxtj = posj + dy[k];
            if(nxti < 0 or nxti >= n or nxtj < 0 or nxtj >= m) continue;
            int nxt_val = val | (1 << c[nxti][nxtj]);
            if(!dp[nxt_val][nxti][nxtj]){
                q.push({nxt_val, {nxti, nxtj}});
                dp[nxt_val][nxti][nxtj] = true;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    cin >> inii >> inij >> fimi >> fimj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    inii--, inij--, fimi--, fimj--;
    cout << bfs(inii, inij) << "\n";
    return 0;
}