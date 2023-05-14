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
const int N = 1e4+5, M = 760;

int bit[M][N];

void add (int p, int v, int id) {
    for (p+=2; p<M; p += p&-p) bit[p][id] = ((v + MOD)%MOD + (bit[p][id] + MOD)%MOD)%MOD;
}

int query (int p, int id) {
    int r = 0;
    for (p+=2; p; p -= p&-p) r = ((r + MOD)%MOD + (bit[p][id] + MOD)%MOD)%MOD;
    return r;
}

ll ans;
int grid[M][M];

int main(){
    int k, l;
    scanf("%d%d", &k, &l);
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            scanf("%d", &grid[i][j]);
        }
    }
    for(int j = 1; j <= k; j++){
        grid[0][j] = grid[j][0] = 0;
        grid[k+1][j] = grid[j][k+1] = INT_MAX;
    }
    int n;
    scanf("%d", &n);
    add(1, 1, 1);
    add(k + 1, -1, 1);
    for(int i = 1; i < n; i++){
        int p;
        scanf("%d", &p);
        for(int j = 1; j <= k; j++){
            int left = (lower_bound(grid[j], grid[j] + k + 2, p - l) - grid[j]);
            int right = (upper_bound(grid[j], grid[j] + k + 2, p + l) - grid[j] - 1);
            if(left > right) continue;
            if(!left) left = 1;
            int x = query(j, i);
            add(left, x, i+1);
            add(right + 1, -x, i+1);
        }
    }
    for(int i = 1; i <= k; i++){
        ans = (ans + query(i, n))%MOD;
    }
    printf("%lld\n", ans);
    return 0;
}