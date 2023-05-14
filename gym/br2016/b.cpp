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

int n, m, a, b, ing[N];
set<int> adj[N];
set<pii> cur, cur_max;

bool removeA(){
    bool ok = false;
    vector<pii> rem, add;
    while(true){
        pii lo = *cur.begin();
        if(lo.st >= a or n <= 0) break;
        ok = true;
        for(auto u : adj[lo.nd]){
            adj[u].erase(lo.nd);
            cur.erase({ing[u], u});
            cur_max.erase({-ing[u], u});
            cur.insert({--ing[u], u});
            cur_max.insert({-ing[u], u});
        }
        cur.erase(lo);
        cur_max.erase({-lo.st, lo.nd});
        adj[lo.nd].clear();
        n--;
    }
    return ok;
}

bool removeB(){
    bool ok = false;
    while(true){
        pii hi = *cur_max.begin();
        if(n - 1 + hi.st >= b or n <= 0) break;
        ok = true;
        for(auto u : adj[hi.nd]){
            adj[u].erase(hi.nd);
            cur.erase({ing[u], u});
            cur_max.erase({-ing[u], u});
            cur.insert({--ing[u], u});
            cur_max.insert({-ing[u], u});
        }
        cur.erase({-hi.st, hi.nd});
        cur_max.erase(hi);
        adj[hi.nd].clear();
        n--;
        removeA();
    }
    return ok;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        ing[u]++, ing[v]++;
    }
    for(int i = 1; i <= n; i++){
        cur.insert({ing[i], i});
        cur_max.insert({-ing[i], i});
    }
    removeA();
    while(removeB());
    cout << n << "\n";
    return 0;
}