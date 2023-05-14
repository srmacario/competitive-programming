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

int par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

int unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return sz[a];
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
  return sz[a];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    while(t--){
        int n, cnt = 0;
        cin >> n;
        map<string, int> id;
        for(int i = 0; i < n; i++){
            string u, v;
            cin >> u >> v;
            if(id.count(u) == 0){
                id[u] = ++cnt;
            }
            if(id.count(v) == 0){
                id[v] = ++cnt;
            }
            cout << unite(id[u], id[v]) << "\n";
        }

        for(int i = 1; i <= cnt; i++) par[i] = i, sz[i] = 1;
    }
    return 0;
}