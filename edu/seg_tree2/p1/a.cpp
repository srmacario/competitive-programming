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

ll st[4*N], lazy[4*N];
int n, m;

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += (r-l+1)*lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int i, int j, ll k){
    push(p, l, r);
    if(j < l or i > r) return;
    if(i <= l and r <= j){
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    int m = (l+r)/2;
    update(2*p, l, m, i, j, k);
    update(2*p+1, m + 1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
}

ll query(int p, int l, int r, int i, int j){
    push(p, l, r);
    if(j < l or i > r) return 0;
    if(i <= l and r <= j) return st[p];
    int m = (l+r)/2;
    ll x = query(2*p, l, m, i, j);
    ll y = query(2*p + 1, m + 1, r, i, j);
    return x + y;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int op, l, r, k;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d%d%d", &l, &r, &k);
            update(1, 0, n-1, l, r-1, k);
        }
        else{
            scanf("%d", &l);
            printf("%lld\n", query(1, 0, n-1, l, l));
        }
    }
    return 0;
}