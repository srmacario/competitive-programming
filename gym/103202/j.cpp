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
const int N = 5e5 + 5;

int n, q, mx_root;

map<int, int> id;
vector<int> e, d, par, l, r, mx, root;
vector<set<int>> lvls;

//begin creating node 0, then start your segment tree creating node 1
int create(int ini = 0, int fim = 0, int val = -1){
    l.push_back(ini);
    r.push_back(fim);
    e.push_back(0);
    d.push_back(0);
    par.push_back(0);
    if(val >= 0) lvls.push_back({});
    return (int)e.size() - 1;
}

void build(int par_pos, int pos, int ini, int fim, int val = -1){
    par[pos] = par_pos;
    if(ini == fim) return;
    int m = (ini + fim) >> 1;
    if(e[pos] == 0){
        int aux = create(ini, m, val);
        e[pos] = aux;
    }
    build(pos, e[pos], ini, m, val);
    if(d[pos] == 0){
        int aux = create(m + 1, fim, val);
        d[pos] = aux;
    }
    build(pos, d[pos], m + 1, fim, val);
}

void init(int pos_mx, int pos, int ini, int fim){
    lvls[pos_mx].insert(pos);
    if(ini == fim) return;
    int m = (ini + fim) >> 1;
    init(e[pos_mx], e[pos], ini, m);
    init(d[pos_mx], d[pos], m + 1, fim);
}

int merge(int from, int to, int super_root, int x){
    if(from == 0 and to == 0) return 0;
    if(from == 0 and to != 0){
        return to;
    }
    if(from != 0 and to == 0){
        return from;
    }
    e[to] = merge(e[from], e[to], e[super_root], x);
    d[to] = merge(d[from], d[to], d[super_root], x);
    lvls[super_root].erase(from);
    if(e[to]) par[e[to]] = to;
    if(d[to]) par[d[to]] = to;
    return to;
}

pii upd(int from, int to, int super_root, int ini, int fim, int p, int q, int x){
    if(from == 0) return {from, to};
    if(q < ini || p > fim) return {from, to};
    //update interval: remove from 'from' and insert into 'to'
    if(p <= ini and fim <= q){
        //merge
        lvls[super_root].erase(from);
        lvls[super_root].insert(to);
        return {0, merge(from, to, super_root, x)};
    }

    if(to == 0){
        to = create(ini, fim);
    }
    int m = (ini + fim) >> 1;
    pii lft = upd(e[from], e[to], e[super_root], ini, m, p, q, x);
    pii rgt = upd(d[from], d[to], d[super_root], m + 1, fim, p, q, x);
    e[to] = lft.nd, e[from] = lft.st;
    d[to] = rgt.nd, d[from] = rgt.st;
    if(e[from] == 0 and d[from] == 0){
        lvls[super_root].erase(from);
        from = 0;
    }
    if(e[to]) par[e[to]] = to;
    if(d[to]) par[d[to]] = to;
    if(e[to] and d[to]) lvls[super_root].insert(to);
    else to = 0;
    return {from, to};
}

int query(int pos, int ini, int fim, int p, int q){
    if(pos == 0) return 0;
    if(q < ini || p > fim) return 0;
    if(p <= ini and fim <= q){
        int ans = 0;
        // for(auto cur : lvls[pos]){
        //     while(par[cur] != 0) cur = par[cur];
        //     ans = max(ans, id[cur]);
        // }
        int cur = *lvls[pos].rbegin();
        while(par[cur] != 0) cur = par[cur];
        ans = id[cur];
        return ans;
    }
    int m = (ini + fim) >> 1;
    return max(query(e[pos], ini, m, p, q) , query(d[pos], m + 1, fim, p, q));
}

void walk(int pos){
    if(pos == 0) return;
    db(pos _ l[pos] _ r[pos] _ par[pos]);
    walk(e[pos]);
    walk(d[pos]);
}
 
void walk_super(int pos){
    if(pos == 0) return;
    db(pos _ l[pos] _ r[pos]);
    for(auto u : lvls[pos]) db(u);
    walk_super(e[pos]);
    walk_super(d[pos]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    //create dummy root
    create(0, 0, 0);

    //create mx root
    mx_root = create(1, n, 0);
    build(0, 1, 1, n, 0);

    //create root of level 0
    root.push_back(create(1, n));
    id[root.back()] = 0;
    build(0, root.back(), 1, n);

    //initialize set of index
    init(1, root.back(), 1, n);

    for(int i = 0; i < q; i++){
        int op, l, r, x;
        cin >> op;
        if(op == 1){
            cin >> l >> r >> x;
            //level x does not exist yet
            if(x >= root.size()) continue;
            //level x exist but x + 1 does not
            if(x + 1 == root.size()) root.push_back(0);
            //update and update roots
            pii cur = upd(root[x], root[x + 1], mx_root, 1, n, l, r, x);
            root[x + 1] = cur.nd, root[x] = cur.st;
            par[root[x + 1]] = 0, par[root[x]] = 0;
            if(cur.st) id[cur.st] = x;
            if(cur.nd) id[cur.nd] = x + 1;
            // db(x);
            // walk(root[x]);
            // db(x + 1);
            // walk(root[x + 1]);
        }
        else{
            cin >> l >> r;
            cout << query(mx_root, 1, n, l, r) << "\n";
        }
    }
    // for(int i = 0; i < root.size(); i++){
    //     db(i);
    //     walk(root[i]);
    // }
    // db(mx_root);
    // walk_super(mx_root);
    return 0;
}