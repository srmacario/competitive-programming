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

int n, q, par[N], sz[N], mn[N];

int find(int a){return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    mn[a] = min(mn[b], mn[a]);
}

set<pii> comp;

void update(int l, int r){
    vector <pii> rem;
    int last = 0, add_l = l, add_r = r;
    auto it = comp.lower_bound({l, 0});
    if(it != comp.begin()) it--;
    for(; it != comp.end(); it++){
        int cur_l, cur_r;
        cur_l = (*it).st;
        cur_r = (*it).nd;
        if(cur_l > r) break;
        if(cur_r < l) continue;
        unite(mn[find(cur_l)], mn[find(l)]);
        if(cur_l  < l) add_l = cur_l;
        if(r < cur_r) add_r = cur_r;
        rem.pb(*it);
    }
    for(auto x : rem) comp.erase(x);
    comp.insert({add_l, add_r});
}

int main(){
    scanf(" %d%d", &n, &q);
    for(int i = 1; i <= n; i++){
        par[i] = mn[i] = i;
        sz[i] = 1;
        comp.insert({i,i});
    }
    for(int i = 0; i < q; i++){
        int t, x, y;
        scanf(" %d%d%d", &t, &x, &y);
        if(t == 1){
            unite(x, y);
        }
        if(t == 2){
            update(x, y);
        }
        if(t == 3){
            printf("%s\n", (find(x) == find(y) ? "YES" : "NO"));
        }
    }
    return 0;
}