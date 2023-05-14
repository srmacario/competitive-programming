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

int par[N], sz[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    map<pii, int> edges;
    priority_queue<piii> pq;
    ll cost = 0;
    for (int i = 1; i <= n; i++){
        int u;
        cin >> u;
        if(i == n) pq.push({u, {n, 1}});
        else pq.push({u, {i, i + 1}});
        cost += u;
    }
    while(!pq.empty()){
        piii p = pq.top();
        pq.pop();
        if(edges[p.nd]) continue;
        cost -= p.st;
        edges[p.nd] = 1;

        int u = p.nd.st - 1, v = p.nd.st;
        if(u == 0) u = n;
        edges[{u, v}] = 1;

        u = p.nd.nd, v = p.nd.nd + 1;
        if(v == n + 1) v = 1;
        edges[{u, v}] = 1;
    }
    cout << cost << "\n";
    return 0;
}