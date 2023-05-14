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

int st[4*N], lazy[4*N];


void push (int p, int l, int r) {
    for(int id = 0; id < 30; id++){
        if (lazy[p]) {
            st[p] |= lazy[p];
            // RMQ (max/min)   -> update: = lazy[p],         incr: += lazy[p]
            // RSQ (sum)       -> update: = (r-l+1)*lazy[p], incr: += (r-l+1)*lazy[p]
            // Count lights on -> flip:   = (r-l+1)-st[p];
            if (l != r) {
                lazy[2*p] |= lazy[p];
                lazy[2*p + 1] |= lazy[p];
                // update:    lazy[2*p] = lazy[p],  lazy[2*p+1] = lazy[p];
                // increment: lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
                // flip:      lazy[2*p] ^= 1,       lazy[2*p+1] ^= 1;
            }
            lazy[p] = 0;
        }
    }
}

void update (int p, int l, int r, int i, int j, int val) {
    push(p, l, r);
    if(j < l or i > r) return;
    if(i <= l and r <= j){
        lazy[p] |= val;
        push(p, l, r);
        return;
    }
    update (2*p, l, (l+r)/2, i, j, val);
    update (2*p+1, (l+r)/2+1, r, i, j, val);
    st[p] = st[2*p] & st[2*p+1];
}

int query (int p, int l, int r, int i, int j) {
    push(p, l, r);
    if(j < l or i > r) return ((1 << 30) - 1);
    if(i <= l and r <= j){
        return st[p];
    }
    int m = (l + r)/2;
    int x = query(2*p, l, m, i, j);
    int y = query(2*p + 1, m + 1, r, i, j);
    return (x & y);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int op, ini, fim, val;
        scanf(" %d", &op);
        if(op == 1){
            scanf("%d %d %d", &ini, &fim, &val);
            update(1, 0, n - 1, ini, fim - 1, val);
        }
        else{
            scanf("%d%d", &ini, &fim);
            int ans = 0;
            printf("%d\n", query(1, 0, n - 1, ini, fim - 1));
        }
    }
    return 0;
}