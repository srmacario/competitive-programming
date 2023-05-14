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
const int N = 2e5+5;

int n, a[N], pos[N], sz, cyc, ini;
ll k;

int dfs(int u, int cnt){
    if(pos[u]){
        ini = u;
        cyc = cnt - pos[u];
        sz = sz - cyc;
        return u;
    }
    sz++;
    pos[u] = cnt;
    int v = (u + a[u]) % n;
    return dfs(v, cnt + 1);
}

ll calc_path(int u, int cur){
    if(cur > sz or k == 0) return 0;
    ll ans = a[u];
    int v = (u + a[u]) % n;
    k--;
    ans += calc_path(v, cur + 1);
    return ans;
}

ll calc_cyc(int u){
    if(u == ini) return 0;
    ll ans = a[u];
    int v = (u + a[u]) % n;
    ans += calc_cyc(v);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    dfs(0, 1);
    ll ans = calc_path(0, 1), cyc_sum = calc_cyc((ini + a[ini]) % n) + a[ini];
    if(k > 0){
        ans += (k / cyc) * cyc_sum;
        sz = cyc;
        k %= cyc;
        ans += calc_path(ini, 1);
    }
    cout << ans << "\n";
    //db(path_sum _ k _ cyc_sum);
    return 0;
}