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
const int N = 3e5+5;

int n, m, par[N], sz[N], len[N], cnt = -1;

pii find(int u){
    if(u == par[u]){
        return {u, 0};
    }
    pii par_u = find(par[u]);
    par[u] = par_u.st;
    len[u] = (len[u] + par_u.nd) % 2;
    return {par[u], len[u]};
}

void unite(int a, int b, int num){
    pii u = find(a), v = find(b);
    if(u == v and cnt == -1) cnt = num; 
    if(sz[v.st] > sz[u.st]) swap(u.st, v.st);
    par[v.st] = u.st;
    len[v.st] = (u.nd + v.nd + 1) % 2;
    sz[u.st] += sz[v.st];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        unite(a, b, i + 1);
    }
    cout << cnt << "\n";
    return 0;
}