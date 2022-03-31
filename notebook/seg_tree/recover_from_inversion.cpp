/*

This problem is the reversed version of the previous one.
There was a permutation pi of n elements, for each i we wrote down the number ai, the number of j such that j<i and pj>pi.
Restore the original permutation for the given ai.

*/

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

void build(int p, int l, int r){
    if(l == r){
        st[p] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p + 1, mid + 1, r);
    st[p] = st[2*p] + st[2*p + 1];
}

int query (int p, int l, int r, int k) {
    if(st[p] < k) return -1;
    if(l == r) return l;
    int mid = (l + r)/2, query_right;
    query_right = query(2*p + 1, mid + 1, r, k);
    if(query_right != -1) return query_right;
    return query(2*p, l, mid, k - st[2*p + 1]);
}

void update (int p, int l, int r, int x, int k) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        st[p] = k;
        return;
    }
    update (2*p, l, (l+r)/2, x, k);
    update (2*p+1, (l+r)/2+1, r, x, k);
    st[p] = st[2*p] + st[2*p+1];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    build(1, 1, n);
    for(int i = n; i >= 1; i--){
        v[i] = query(1, 1, n, v[i] + 1);
        update(1, 1, n, v[i], 0);
    }
    for(int i = 1; i <= n; i++) printf("%d ", v[i]);
    printf("\n");
    return 0;
}