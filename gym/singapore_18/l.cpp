#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 4e5 + 5;

int s[N];

pii st[4*N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = {INF, INF}; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]);
}

pii query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return {INF, INF};
    if (i <= l and r <= j) return st[p];
    pii x = query(2*p, l, (l+r)/2, i, j);
    pii y = query(2*p+1, (l+r)/2+1, r, i, j);
    pii ans = {INF, INF};
    if(x.st < y.st){
        ans.st = x.st;
        if(y.st != x.st) ans.nd = min(ans.nd, y.st);
        if(x.nd != x.st) ans.nd = min(ans.nd, x.nd);
        if(y.nd != x.st) ans.nd = min(ans.nd, y.nd);
    }
    else{
        ans.st = y.st;
        if(x.st != y.st) ans.nd = min(ans.nd, x.st);
        if(x.nd != y.st) ans.nd = min(ans.nd, x.nd);
        if(y.nd != y.st) ans.nd = min(ans.nd, y.nd);
    }
    return ans;
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        st[p] = {v, INF};
        return;
    }
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    if(st[2*p].st < st[2*p + 1].st){
        st[p].st = st[2 * p].st;
        if(st[2 * p].nd != st[2 * p].st) st[p].nd = min(st[p].nd, st[2 * p].nd);
        if(st[2 * p + 1].st != st[2 * p].st) st[p].nd = min(st[p].nd, st[2 * p + 1].st);
        if(st[2 * p + 1].nd != st[2 * p].st) st[p].nd = min(st[p].nd, st[2 * p + 1].nd);
    }
    else{
        st[p].st = st[2 * p + 1].st;
        if(st[2 * p].nd != st[2 * p + 1].st) st[p].nd = min(st[p].nd, st[2 * p].nd);
        if(st[2 * p].st != st[2 * p + 1].st) st[p].nd = min(st[p].nd, st[2 * p].st);
        if(st[2 * p + 1].nd != st[2 * p + 1].st) st[p].nd = min(st[p].nd, st[2 * p + 1].nd);
    }
}

int n, p[N], r[N], used[N];
pii ans = {INF, INF};
vi occ[N];

void upd(int i){
    if(!used[i]){
        used[i] = 1;
        for(auto x : occ[i]) update(1, 1, n, x, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(st, 63, sizeof(st));
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        r[p[i]] = i;
        occ[p[i]].pb(i);
    }
    for(int i = 1; i <= n; i++){
        if(r[p[i]] > i){
            pii cur = query(1, 1, n, i, r[p[i]]);
            if(cur.st != INF and cur.st != p[i]) ans = min(ans, {cur.st, p[i]});
            if(cur.nd != INF and cur.nd != p[i]) ans = min(ans, {cur.nd, p[i]});
        }
        upd(p[i]);
    }
    if(ans.st != INF and ans.nd != INF) cout << ans.st << " " << ans.nd << "\n";
    else cout << "-1\n";
    return 0;
}