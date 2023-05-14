//finding for the given x and l the minimum index j such that j>=l and a[j]>=x.
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

int st[4*N], v[N];

void build (int p, int l, int r) {
    if (l == r) {
        st[p] = v[l];
        return;
    }
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = max(st[2*p], st[2*p+1]);
}

void update (int p, int l, int r, int x, int k) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        st[p] = k;
        return;
    }
    update (2*p, l, (l+r)/2, x, k);
    update (2*p+1, (l+r)/2+1, r, x, k);
    st[p] = max(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int k, int i) {
    if(r < i or st[p] < k) return INF;
    if(l == r){
        return l;
    }
    int query_left = INF, query_right = INF;
    query_left = query(2*p, l, (l+r)/2, k, i);
    // db(l _ r _ query_left);
    if(l < i or query_left == INF) query_right = query(2*p + 1, (l + r)/2 + 1, r, k, i);
    return min(query_left, query_right);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    build(1, 0, n - 1);
    for(int i = 0; i < m; i++){
        int op, pos, val, l;
        scanf(" %d", &op);
        if(op == 1){
            scanf("%d %d", &pos, &val);
            update(1, 0, n-1, pos, val);
        }
        else{
            scanf("%d %d", &pos, &l);
            int ans = query(1, 0, n - 1, pos, l);
            printf("%d\n", (ans == INF) ? -1 : ans);
        }
    }
    return 0;
}