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

int n, cnt, vis[N];
vector<pii> b;
map<pii, int> all;
pii adj[6] = {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}};

void dfs(pii cur){
    // db(all[cur] _ cnt _ vis[all[cur]]);
    vis[all[cur]] = 1;
    for(auto p : adj){
        pii nxt = {cur.st + p.st, cur.nd + p.nd};
        // db(nxt.st _ nxt.nd);
        if(all.count(nxt) and !vis[all[nxt]]) dfs(nxt);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    b.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> b[i].st >> b[i].nd;
        all[b[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[all[b[i]]]) ++cnt, dfs(b[i]);
    }
    cout << cnt << "\n";
    return 0;
}