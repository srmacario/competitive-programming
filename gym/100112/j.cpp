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
const int N = 1e5+5;

int n;
pii p[N], r[N];

bool dfs(int u, int cost){
    if(!u) return true;
    if(p[u].st < cost) return false;
    p[u].st -= cost;
    bool ok = dfs(p[u].nd, cost);
    if(!ok) p[u].st += cost;
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i].nd >> r[i].st >> p[i].st;
        r[i].nd = i;
    }
    sort(r + 1, r + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dfs(r[i].nd, r[i].st);
    }
    cout << ans << "\n";
    return 0;
}