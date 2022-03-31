//Find minimum index j such thad a[j] >= x

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

int query (int p, int l, int r, int k) {
    if(st[p] < k) return INF;
    if(l == r) return l;
    int query_left = INF;
    query_left = query(2*p, l, (l+r)/2, k);
    if(query_left == INF) return query(2*p + 1, (l + r)/2 + 1, r, k);
    return query_left;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    build(1, 0, n - 1);
    for(int i = 0; i < m; i++){
        int op, pos, val;
        scanf(" %d", &op);
        if(op == 1){
            scanf("%d %d", &pos, &val);
            update(1, 0, n-1, pos, val);
        }
        else{
            scanf("%d", &pos);
            printf("%d\n", query(1, 0, n - 1, pos));
        }
    }
    return 0;
}