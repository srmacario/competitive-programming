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

int v[N];
//sum
//max_sub_seg
//max_prefix
//max_sufix

struct seg_tree{
    int sz;
    vector<ll> sum, seg, pref, suf;

    seg_tree(int sz) : sz(sz){
        int pot = 1;
        while(pot < sz) pot *= 2;
        pot *= 2;
        pot += 5;
        sum.resize(pot, 0);
        seg.resize(pot, 0);
        pref.resize(pot, 0);
        suf.resize(pot, 0);
    }

    void build(int p, int l, int r){
        if(l == r){
            sum[p] = seg[p] = pref[p] = suf[p] = v[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*p, l, mid);
        build(2*p + 1, mid + 1, r);
        sum[p] = sum[2*p] + sum[2*p + 1];
        pref[p] = max(pref[2*p], pref[2*p + 1] + sum[2*p]);
        suf[p] = max(sum[2*p + 1] + suf[2*p], suf[2*p + 1]);
        seg[p] = max({seg[2*p], seg[2*p + 1], suf[2*p] + pref[2*p + 1]});
    }

    void update(int p, int l, int r, int x, ll k){
        if(x < l or x > r) return;
        if(l == r and l == x){
            sum[p] = seg[p] = pref[p] = suf[p] = k;
            return;
        }
        int mid = (l+r)/2;
        update(2*p, l, mid, x, k);
        update(2*p + 1, mid + 1, r, x, k);
        sum[p] = sum[2*p] + sum[2*p + 1];
        pref[p] = max({pref[2*p], pref[2*p + 1] + sum[2*p], 0ll});
        suf[p] = max({sum[2*p + 1] + suf[2*p], suf[2*p + 1], 0ll});
        seg[p] = max({seg[2*p], seg[2*p + 1], suf[2*p] + pref[2*p + 1], 0ll});
    }

    ll get_sum(int p, int l, int r, int i, int j){
        if(l > j or r < i) return 0;
        if(i <= l and r <= j) return sum[p];
        int mid = (l + r)/2;
        ll sum_l = get_sum(2*p, l, mid, i, j);
        ll sum_r = get_sum(2*p + 1, mid + 1, r, i, j);
        return sum_l + sum_r;
    }

    ll get_pref(int p, int l, int r, int i, int j){
        if(l > j or r < i) return -LINF;
        if(i <= l and r <= j) return pref[p];
        int mid = (l + r)/2;
        ll sum_l = get_sum(2*p, l, mid, i, j);
        // ll sum_r = get_sum(2*p + 1, mid + 1, r, i, j);
        ll pref_l = get_pref(2*p, l, mid, i, j);
        ll pref_r = get_pref(2*p + 1, mid + 1, r, i, j);
        return max({pref_l, sum_l + pref_r});
    }

    ll get_suf(int p, int l, int r, int i, int j){
        if(l > j or r < i) return -LINF;
        if(i <= l and r <= j) return suf[p];
        int mid = (l + r)/2;
        // ll sum_l = get_sum(2*p, l, mid, i, j);
        ll sum_r = get_sum(2*p + 1, mid + 1, r, i, j);
        ll suf_l = get_suf(2*p, l, mid, i, j);
        ll suf_r = get_suf(2*p + 1, mid + 1, r, i, j);
        return max({suf_l + sum_r, suf_r});
    }

    ll get_seg(int p, int l, int r, int i, int j){
        if(l > j or r < i) return -LINF;
        if(i <= l and r <= j) return seg[p];
        int mid = (l + r)/2;
        ll seg_l = get_seg(2*p, l, mid, i, j);
        ll seg_r = get_seg(2*p + 1, mid + 1, r, i, j);
        ll suf_l = get_suf(2*p, l, mid, i, j);
        ll pref_r = get_pref(2*p + 1, mid + 1, r, i, j);
        return max({seg_l, seg_r, suf_l + pref_r});
    }
};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    seg_tree st1 = seg_tree(n);
    st1.build(1, 0, n - 1);
    printf("%lld\n", max(st1.get_seg(1, 0, n-1, 0, n-1), 0ll));
    for(int i = 0; i < m; i++){
        int pos, val;
        scanf("%d %d", &pos, &val);
        st1.update(1, 0, n-1, pos, val);
        printf("%lld\n", max(st1.get_seg(1, 0, n-1, 0, n-1), 0ll));
    }
    return 0;
}