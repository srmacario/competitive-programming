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

int n;
map<pii, int> pts;
int x[N], y[N], vis[N], cnt[2];
vi adj[N];

bool le(ld x, ld y) { return x - EPS < y; }

void dfs(int s, int cur){
    cnt[cur]++; 
    vis[s] = cur;
    for(auto v : adj[s]){
        if(vis[v] == -1){
            dfs(v, cur^1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(vis, -1, sizeof(vis));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        pts[{x[i], y[i]}] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int h = -5; h <= 5; h++){
            for(int v = -5; v <= 5; v++){
                if(v == 0 and h == 0) continue;
                pii cur = {x[i] + h, y[i] + v};
                if(h*h + v*v > 25) continue;
                if(pts.count(cur)) adj[i].pb(pts[cur]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == -1){
            dfs(i, 0);
            ans += min(cnt[0], cnt[1]);
            cnt[0] = cnt[1] = 0;
        }
    }
    cout << ans << "\n";
    return 0;
}