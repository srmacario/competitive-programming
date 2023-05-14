#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

ll st[4*N], lazy[4*N];
ll st2[4*N], lazy2[4*N];

void build (int n) {
    for(int i = 0; i <= 4 * n; i++) st[i] = lazy[i] = 0;
    for(int i = 0; i <= 4 * n; i++) st2[i] = lazy2[i] = 0;
}

void push (int p, int l, int r) {
    if (lazy[p]) {
        st[p] += 1ll * (r-l+1) * lazy[p];
        if (l != r) {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
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

void update (int p, int l, int r, int i, int j, int k) {
    push(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push(p, l, r);
        return;
    }
    update(2*p, l, (l+r)/2, i, j, k);
    update(2*p+1, (l+r)/2+1, r, i, j, k);
    st[p] = st[2*p] + st[2*p+1];
}

void push2 (int p, int l, int r) {
    if (lazy2[p]) {
        st2[p] += 1ll * (r-l+1) * lazy2[p];
        if (l != r) {
            lazy2[2*p] += lazy2[p];
            lazy2[2*p+1] += lazy2[p];
        }
        lazy2[p] = 0;
    }
}

ll query2(int p, int l, int r, int i, int j) {
    push2(p, l, r);
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st2[p];
    ll x = query2(2*p, l, (l+r)/2, i, j);
    ll y = query2(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update2 (int p, int l, int r, int i, int j, int k) {
    push2(p, l, r);
    if (r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy2[p] += k;
        // update:    lazy[p] = k;
        // increment: lazy[p] += k;
        // flip:      lazy[p] = 1;
        push2(p, l, r);
        return;
    }
    update2(2*p, l, (l+r)/2, i, j, k);
    update2(2*p+1, (l+r)/2+1, r, i, j, k);
    st2[p] = st2[2*p] + st2[2*p+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        build(n);
        vector<pii> a(n + 1);
        vector<pii> old_a(n + 1);
        set<int> pos;
        for(int i = 1; i <= n; i++){
            cin >> a[i].st;
            old_a[i].st = a[i].st;
            a[i].nd = i;
        }
        sort(a.begin() + 1, a.end());
        ll cnt = 0;
        int cur = 1;
        for(int i = 1; i <= n; i++){
            int m = a[i].st;
            old_a[a[i].nd].nd = i;
            if(m < cur){
                pos.insert(i);
                update(1, 1, n, i, i, m);
            }
            else{
                cnt += (m - cur);
                a[i].st = cur;
                update(1, 1, n, i, i, cur);
                cur++;
            }
        }
        pos.insert(n + 1);
        vector<ll> ans(n + 1);
        ans[n] = cnt;
        for(int i = n; i > 1; i--){
            auto lb = pos.lower_bound(old_a[i].nd);
            ll old = 0, novo = 0;
            ll shift = 0;
            if(*lb - 1 >= old_a[i].nd + 1){
                old = query(1, 1, n, old_a[i].nd + 1, *lb - 1);
                update(1, 1, n, old_a[i].nd + 1, *lb - 1, -1);
                novo = query(1, 1, n, old_a[i].nd + 1, *lb - 1);
                shift += query2(1, 1, n, old_a[i].nd + 1, *lb - 1);
            }
            if(*lb != n + 1) pos.erase(*lb);
            ll cur = query(1, 1, n, old_a[i].nd, old_a[i].nd);
            update(1, 1, n, old_a[i].nd, old_a[i].nd, -cur);
            update2(1, 1, n, old_a[i].nd, old_a[i].nd, 1);
            cnt += (old - novo - shift - (old_a[i].st - cur));
            ans[i - 1] = cnt;
        }
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}