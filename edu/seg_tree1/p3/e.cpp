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

ll st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) {
        st[p] = v[l];
        return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = st[2*p]+st[2*p+1];
}

ll query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    ll x = query(2*p, l, (l+r)/2, i, j);
    ll y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int x, ll v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        st[p] += v;
        return;
    }
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    st[p] = st[2*p] + st[2*p+1];
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    // build(1, 0, n);
    for(int i = 0; i < m; i++){
        int op;
        scanf(" %d", &op);
        if(op == 1){
            int l, r, k;
            scanf(" %d%d%d", &l, &r, &k);
            update(1, 0, n, l, k);
            update(1, 0, n, r, -k);
        }
        else{
            int pos;
            scanf(" %d", &pos);
            printf("%lld\n", query(1, 0, n, 0, pos));
        }
    }
    return 0;
}