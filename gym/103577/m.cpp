#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

using ll = long long;
using ld = long double;

const int N = 5e5+5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int a[N];
int par[N], sz[N];
int in[N], out[N];
int nxt[N];
int vis[N];

void dfs(int a, int& last) {
    if (vis[a] == 1) return;
    vis[a] = 1;
    last = a;
    if (nxt[a] != -1) dfs(nxt[a], last);
}

int find(int a) {
    return a == par[a] ? a : par[a] = find(par[a]);
}

int get_sz(int a) {
    return sz[find(a)];
}

bool same_comp(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    if (same_comp(a, b)) return;
    a = find(a), b = find(b);
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], par[b] = a;
}

bool connect(int u, int v) {
    if (out[u] >= 1) return false;
    if (in[v] >= 1) return false;

    if (same_comp(u, v) and get_sz(u) < n) 
        return false;

    nxt[u] = v;
    out[u]++, in[v]++;
    unite(u, v);
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1, nxt[i] = -1;

    for (int i = 1; i <= n; i++) cin >> a[i];

    bool is_ok = true;
    for (int i = 1; i <= n; i++) {
        if (!connect(i, a[i])) {
            is_ok = false;
            break;
        }
    }

    if (is_ok) {
        for (int i = 1; i <= n; i++) cout << nxt[i] << " ";
        cout << "\n";
        return 0;
    }

    //dbs("debugging");
    //for (int i = 1; i <= n; i++) cout << nxt[i] << " ";
    //cout << "\n";

    set<int> starts, lasts;

    for (int i = 1; i <= n; i++) 
        if (!in[i]) {
            int start = i;
            int last = i;
            dfs(i, last);
            starts.insert(start);
            lasts.insert(last);
            //db(start _ last);
        }
    

    while(starts.size() > 1) {
        int l = *lasts.begin();

        auto it = starts.begin();

        if (same_comp(l, *it)) it++;

        int s = *it;
        starts.erase(s);

        out[l]++, in[s]++;
        nxt[l] = s;
        unite(l, s);

        lasts.erase(l);
    }

    int ns = -1, nl = -1;

    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) nl = i;
        if (in[i] == 0) ns = i; 
    }

    assert(ns != -1);
    assert(nl != -1);
    assert(ns != nl);

    nxt[nl] = ns;

    for (int i = 1; i <= n; i++)
        cout << nxt[i] << " ";
    
    cout << "\n";
    
    return 0;
}