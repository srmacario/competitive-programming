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

int par[N], sz[N];

int find(int a){return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
    }
    vector <pair<string,pii>> q;
    for(int i = 0; i < k; i++){
        string op;
        int u, v;
        cin >> op >> u >> v;
        q.pb({op,{u,v}});
    }
    vector <string> ans;
    for(int i = q.size()-1; i >= 0; i--){
        int u = par[q[i].nd.st], v = par[q[i].nd.nd];
        if(q[i].st == "ask"){
            if(find(u) == find(v)){
                ans.pb("YES");
            }
            else ans.pb("NO");
        }
        else{
            unite(u, v);
        }
    }
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << "\n";
    
    return 0;
}