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

int n, m, par[N], sz[N], len[N];

pii find(int u){
    if(u == par[u]){
        return {u, 0};
    }
    pii par_val = find(par[u]);
    par[u] = par_val.st;
    len[u] = (len[u] + par_val.nd) % 2;
    return {par[u], len[u]};
}

void unite(int a, int b){
    pii u = find(a), v = find(b);
    if(u.st == v.st) return;
    if(sz[v.st] > sz[u.st]) swap(u, v);
    par[v.st] = u.st;
    sz[u.st] += sz[v.st];
    len[v.st] = (1 + u.nd + v.nd) % 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
    int shift = 0;
    for(int i = 0; i < m; i++){
        int op, a, b;
        cin >> op >> a >> b;
        a = (a + shift) % n;
        b = (b + shift) % n;
        if(op == 0){
            unite(a, b);
        }
        if(op == 1){
            int ca = find(a).nd, cb = find(b).nd;
            if(ca == cb){
                cout << "YES\n";
                shift++;
            }
            else cout << "NO\n";
        }
    }
    return 0;
}