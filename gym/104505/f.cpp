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

int n, q;
pii st[4 * N];
vector<int> a, b;
map<int, set<int>> pos; 

void build(int p, int l, int r){
    if(l == r){
        st[p] = {b[l], l};
        return;
    }
    int m = (l + r) >> 1;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    st[p] = max(st[2 * p], st[2 * p + 1]);
}

pii query(int p, int l, int r, int i, int j){
    if(l > j or r < i) return {-INF, -INF};
    if(l >= i and r <= j) return st[p];
    int m = (l + r) >> 1;
    pii x = query(2 * p, l, m, i, j);
    pii y = query(2 * p + 1, m + 1, r, i, j);
    return max(x, y);
}

void update(int p, int l, int r, int x, int v){
    if(l > x or r < x) return;
    if(l == r and l == x){
        st[p] = {v, l};
        return;
    }
    int m = (l + r) >> 1;
    update(2 * p, l, m, x, v);
    update(2 * p + 1, m + 1, r, x, v);
    st[p] = max(st[2 * p], st[2 * p + 1]);
}

void remove(int x){
    //remove actual from position
    pii cur = query(1, 1, n, x, x);
    auto nxt = pos[a[x]].upper_bound(x);
    //if nxt, nxt now points backwards
    if(nxt != pos[a[x]].end()){
        b[*nxt] = cur.st;
        update(1, 1, n, *nxt, b[*nxt]);
    }
    pos[a[x]].erase(x);
}

void add(int x){
    auto nxt = pos[a[x]].upper_bound(x);
    //if nxt, nxt now points me
    if(nxt != pos[a[x]].end()){
        b[*nxt] = x;
        update(1, 1, n, *nxt, b[*nxt]);
    }
    //if before, me points before
    if(pos[a[x]].size() and nxt != pos[a[x]].begin()){
        nxt--;
        b[x] = *nxt;
    }
    //else me points -1
    else b[x] = -1;
    update(1, 1, n, x, b[x]);
    pos[a[x]].insert(x);
}

void change(int x, int v){
    remove(x);
    a[x] = v;
    add(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a.resize(n + 1), b.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(pos.count(a[i])){
            b[i] = *(pos[a[i]].rbegin());
        }
        else b[i] = -1;
        pos[a[i]].insert(i);
    }
    build(1, 1, n);
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        if(op){
            int l, r;
            cin >> l >> r;
            pii me = query(1, 1, n, l, r);
            if(me.st < l){
                cout << "-1\n";
                continue;
            }
            int v = a[me.st];
            change(me.st, 0);
            change(me.nd, INF);
            pii uchoa = query(1, 1, n, l, r);
            if(uchoa.st < l){
                cout << "-1\n";
            }
            else{
                cout << me.st << " " << me.nd << " " << uchoa.st << " " << uchoa.nd << "\n";
            }
            change(me.st, v);
            change(me.nd, v);
        }
        else{
            int x, v;
            cin >> x >> v;
            change(x, v);
        }
    }
    // cout << "\n";
    // for(int i = 1; i <= n; i++) cout << a[i] << " ";
    // cout << "\n";
    // for(int i = 1; i <= n; i++) cout << query(1, 1, n, i, i).st << " " << query(1, 1, n, i, i).nd << "\n";
    return 0;
}