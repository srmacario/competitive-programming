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

int v[N];
pii st[4*N];
int n, m;

void build(int p, int l, int r){
    if(l == r){
        st[p] = {v[l], 1};
        return;
    }
    int m = (l+r)/2;
    build(2*p, l, m);
    build(2*p + 1, m + 1, r);
    st[p] = min(st[2*p], st[2*p + 1]);
    if(st[2*p].st == st[2*p + 1].st) st[p].nd = st[2*p].nd + st[2*p + 1].nd;
}

void update(int p, int l, int r, int x, int k){
    if(x < l or x > r) return;
    if(l == x and r == x){
        st[p] = {k, 1};
        return;
    }
    int m = (l + r)/2;
    update(2*p, l, m, x, k);
    update(2*p + 1, m + 1, r, x, k);
    st[p] = min(st[2*p], st[2*p + 1]);
    if(st[2*p].st == st[2*p + 1].st) st[p].nd = st[2*p].nd + st[2*p + 1].nd;
}

pii query(int p, int l, int r, int i, int j){
    if(j < l or i > r) return {INF, 0};
    if(i <= l and r <= j) return st[p]; 
    int m = (l + r)/2;
    pii x = query(2*p, l, m, i, j);
    pii y = query(2*p + 1, m + 1, r, i, j);
    pii ans = min(x, y);
    if(x.st == y.st) ans.nd = x.nd + y.nd;
    return ans;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    build(1, 0, n-1);
    for(int i = 0; i < m; i++){
        int op, u, v;
        scanf("%d%d%d", &op, &u, &v);
        if(op == 1) update(1, 0, n-1, u, v);
        else{
            pii ans = query(1, 0, n-1, u, v-1);
            printf("%d %d\n", ans.st, ans.nd);
        }
    }
    return 0;
}