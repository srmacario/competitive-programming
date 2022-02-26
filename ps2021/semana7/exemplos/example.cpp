#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
//0, -1, 63 = INF
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
    st[p] = st[2*p]+st[2*p+1];
    // st[p] = min(st[2*p], st[2*p+1]);
    // st[p] = max(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    // return INF;
    // return -INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
    // return min(x, y);
    // return max(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {
        st[p] = v;
        return;
    }
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    st[p] = st[2*p] + st[2*p+1];
    //st[p] = min(st[2*p], st[2*p+1]);
    //st[p] = max(st[2*p], st[2*p+1]);
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    build(1, 0, n-1);
    for(int i = 0; i < q; i++){
        //1 -> update
        //2 -> query 
        int op;
        cin >> op;
        if(op == 1){
            int pos, val;
            cin >> pos >> val;
            update(1, 0, n-1, pos, val);
        }
        if(op == 2){
            // [1, n]
            int left, right;
            cin >> left >> right;
            //[left, right]
            cout << query(1, 0, n-1, left, right);
            // [1, n]
            // cout << query(1, 0, n-1, left-1, right-1);
        }
    }
    return 0;
}