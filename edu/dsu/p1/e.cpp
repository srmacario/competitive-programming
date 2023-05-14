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
const int N = 2e5+5;

int n, m, par[N], ans[N], l[N], r[N];

pair<int, int> find(int u){
    if(par[u] == u or par[u] == 1) return {par[u], ans[u]};
    pii cur = find(par[u]);
    par[u] = cur.st;
    ans[u] = cur.nd;
    return cur;
}

void unite(int a, int b, int t){
    if((a = find(a).st) == (b = find(b).st)) return;
    if(b == 1) swap(a, b);
    par[b] = a;
    if(a == 1) ans[b] = t;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        par[i] = i;
        ans[i] = -1;
    }
    vector<pii> up(m);
    for(int i = 0; i < m; i++){
        int u, op;
        cin >> u >> op;
        if(op == 1) up[i] = {u, l[u]}, l[u] = -1;
        else up[i] = {u, r[u]}, r[u] = -1;
    }
    for(int u = 1; u <= n; u++){
        if(l[u] != -1) unite(u, l[u], -1);
        if(r[u] != -1) unite(u, r[u], -1);
    }
    for(int i = m - 1; i >= 0; i--){
        // db(find(up[i].st).st _ find(up[i].nd).st _ i);
        unite(up[i].st, up[i].nd, i);
    }
    for(int i = 1; i <= n; i++) cout << find(i).nd << "\n";
    return 0;
}