#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef unsigned long long ll;
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

ll lazy[4*N], st[4*N];
int n, m;

void build(int p, int l, int r){
    if(l == r){
        st[p] = 1;
        return;
    }
    int m = (l+r)/2;
    build(2*p, l, m);
    build(2*p+1, m + 1, r);
    st[p] = (st[2*p] + st[2*p+1])%MOD;
}

void push (int p, int l, int r) {
    if (lazy[p] > 1) {
        st[p] = (st[p]*lazy[p])%MOD;
        // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
        // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
        // Count lights on -> flip:   = (r-l+1)-st[p];
        if (l != r) {
            lazy[2*p] = (lazy[2*p] * lazy[p])%MOD;
            lazy[2*p+1] = (lazy[2*p + 1] * lazy[p])%MOD;
            // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
            // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
            // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
        }
        lazy[p] = 1;
    }
}

void update(int p, int l, int r, int i, int j, ll k){
    push(p, l, r);
    if(j < l or i > r) return;
    if(i <= l and r <= j){
        lazy[p] = (lazy[p]*k)%MOD;
        push(p, l, r);
        return;
    }
    int m = (l + r)/2;
    update(2*p, l, m, i, j, k);
    update(2*p + 1, m + 1, r, i, j, k);
    st[p] = (st[2*p] + st[2*p + 1])%MOD;
}

ll query(int p, int l, int r, int i, int j){
    push(p, l, r);
    if(j < l or i > r) return 0;
    if(i <= l and r <= j) return st[p]; 
    int m = (l + r)/2;
    ll x = query(2*p, l, m, i, j);
    ll y = query(2*p + 1, m + 1, r, i, j);
    return (x + y)%MOD;
}

int main(){
    scanf("%d%d", &n, &m);
    // memset(st, 63, sizeof(st));
    for(int i = 0; i < 4*N; i++) lazy[i] = 1;
    build(1, 0, n-1);
    for(int i = 0; i < m; i++){
        int op, l, r, k;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d%d%d", &l, &r, &k);
            update(1, 0, n-1, l, r-1, k);
        }
        else{
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, 0, n-1, l, r-1)%MOD);
        }
    }
    return 0;
}