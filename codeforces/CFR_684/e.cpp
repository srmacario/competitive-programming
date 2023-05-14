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

ll st[4*N], v[N], lazy[4*N];
int stm[4*N];
int n,q;

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}

void push (int p, ll l, ll r) {
    if (lazy[p]) {
        st[p] = (r-l+1)*lazy[p];
        stm[p] = lazy[p];
        if (l != r) {
            lazy[2*p] = lazy[p];
            lazy[2*p+1] = lazy[p];
        }
        lazy[p] = 0;
    }
}

ll query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int i, int j, ll k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = k;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
    stm[p] = min(stm[2*p], stm[2*p+1]);
}

void buildm (int p, int l, int r) {
    if (l == r) {stm[p] = v[l]; return;}
    buildm (2*p, l, (l+r)/2);
    buildm (2*p+1, (l+r)/2+1, r);
    stm[p] = min(stm[2*p], stm[2*p+1]);
}

int busca(int p, int l, int r, ll k){
    if(l == r){
        if(st[p] <= k) return r;
        return r-1;
    }
    if(st[2*p] <= k) return busca(2*p+1, (l+r)/2 + 1,r,k - st[2*p]);
    return busca(2*p,l,(l+r)/2,k);
}

int buscanum(int p, int l, int r, int pos, ll k){
    if(l == r) return l;
    if(pos <= (l+r)/2){
        if(stm[2*p] <= k){
            return buscanum(2*p,l,(l+r)/2,pos,k);
        }
    }
    return buscanum(2*p+1,(l+r)/2+1,r,pos,k);
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++) scanf("%lld", &v[i]);
    build(1,1,n);
    buildm(1,1,n);
    for(int i=0;i<q;i++){
        int op,x;
        ll y;
        scanf("%d %d %lld", &op, &x, &y);
        if(op == 1){
            int l=1, r=x;
            while(l < r){
                int m = (l+r)/2;
                ll cur = query(1,1,n,m,m);
                if(cur < y) r = m;
                else l = m+1;
            }
            if(l >= x){
                if(query(1,1,n,x,x) > y) continue;
            }
            update(1,1,n,l,x,y);
        }
        if(op == 2){
            int ans = 0;
            int l = x, r = n;
            while(y > 0 and l <= n){
                l = buscanum(1,1,n,l,y);
                if(l == n){
                    if(query(1,1,n,n,n) <= y) ans++;
                    break;
                }
                y += query(1,1,n,1,l-1);
                int s = busca(1,1,n,y);
                ans += (s-l+1);
                l = s+1;
                y -= query(1,1,n,1,l-1);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}