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
const int N = 5e5+5;

int v[N], n, dp[N];
//sum
//max_prefix

struct seg_tree{
    int sz;
    vector<pll> sum, pref;

    seg_tree(int init_sz) : sz(init_sz){
        int pot = 1;
        while(pot < sz) pot *= 2;
        pot *= 2;
        pot += 5;
        sum.resize(pot, {0, 0});
        pref.resize(pot, {0, 0});
    }

    void build(int p, int l, int r){
        if(l == r){
            sum[p] = pref[p] = {1, v[l]};
            return;
        }
        int mid = (l+r)/2;
        build(2*p, l, mid);
        build(2*p + 1, mid + 1, r);
        sum[p] = {sum[2*p].st + sum[2*p + 1].st, sum[2*p].nd + sum[2*p + 1].nd};

        //prefix
        pll rgt = {pref[2*p + 1].st + sum[2*p].st, pref[2*p + 1].nd + sum[2*p].nd};
        pll lft = pref[2*p];
        if(rgt.nd > 0){
            pref[p] = rgt;
        }
        else{
            if(lft.nd > 0) pref[p] = lft;
            else pref[p] = min(lft, rgt);
        }
    }

    pll get_sum(int p, int l, int r, int i, int j){
        if(l > j or r < i) return {0, 0};
        if(i <= l and r <= j) return sum[p];
        int mid = (l + r)/2;
        pll sum_l = get_sum(2*p, l, mid, i, j);
        pll sum_r = get_sum(2*p + 1, mid + 1, r, i, j);
        return {sum_l.st + sum_r.st, sum_l.nd + sum_r.nd};
    }

    pll get_pref(int p, int l, int r, int i, int j){
        if(l > j or r < i) return {LINF, -LINF};
        if(i <= l and r <= j) return pref[p];
        int mid = (l + r)/2;
        pll sum_l = get_sum(2*p, l, mid, i, j);
        pll pref_l = get_pref(2*p, l, mid, i, j);
        pll pref_r = get_pref(2*p + 1, mid + 1, r, i, j);
        pll rgt = {pref_r.st + sum_l.st, pref_r.nd + sum_l.nd};

        if(rgt.nd > 0){
            return rgt;
        }
        else{
            if(pref_l.nd > 0) return pref_l;
            return min(pref_l, rgt);
        }
    }

};

seg_tree seg(N);
int calc(int pos){
    if(pos == n) return 0;
    if(dp[pos] != -INF) return dp[pos];
    pll query = seg.get_pref(1, 0, n - 1, pos, n - 1);
    // if(query.nd > 0) return dp[pos] = (query.st + dp[])
}

//[0, n)
int ps[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> v[i];
            ps[i] = ps[i - 1] + v[i];
            dp[i] = -INF;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                int value = 0;
                if(ps[i] - ps[j] > 0) value = (i - j);
                if(ps[i] - ps[j] < 0) value = -(i - j);
                dp[i] = max(dp[i], dp[j] + value);
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}