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

int par[N], sz[N];

vector <plll> edges; //mp(dist, mp(node1, node2))

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n,m,k;
        ll ans = 0, mn = LINF;
        cin >> n >> m >> k;
        for (int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
        for(int i=0;i<m;i++){
            ll x,y,s;
            cin >> x >> y >> s;
            mn = min(mn,abs(k-s));
            edges.pb({s,{x,y}});
        }
        bool ok = false;
        sort(edges.begin(), edges.end());
        for (auto e : edges){
            if (find(e.nd.st) != find(e.nd.nd)){
                unite(e.nd.st, e.nd.nd);
                if(e.st > k) ans += e.st - k, ok = true;
            }
        }
        if(!ok) ans = mn;
        cout << ans << "\n";
        edges.clear();
    }
    return 0;
}