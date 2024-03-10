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
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, a[N];
ll st[4 * N][2][2];

void set_seg_val(int p){
    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            st[p][i][j] = LINF;
            for(int k = 0; k <= 1; k++){
                st[p][i][j] = min(st[p][i][j], max(st[2*p][i][k], st[2*p + 1][k][j]));
            }
        }
    }
}

void build(int p, int l, int r){
    if(l == r){
        st[p][0][0] = a[l];
        st[p][0][1] = (l == n) ? LINF: a[l] + a[l + 1];
        st[p][1][0] = (l == 1) ? LINF : -LINF;
        st[p][1][1] = LINF;
        return;
    }
    int m = (l + r) >> 1;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    set_seg_val(p);
}

void update(int p, int l, int r, int pos, int op){
    if(pos < l or pos > r) return;
    if(l == r){
        st[p][0][op] = LINF;
        return;
    }
    int m = (l + r) >> 1;
    update(2 * p, l, m, pos, op);
    update(2 * p + 1, m + 1, r, pos, op);
    set_seg_val(p);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<ll, pii>> min_ans;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            min_ans.push_back({a[i], {i, 0}});
            if(i > 1) min_ans.push_back({a[i] + a[i - 1], {i - 1, 1}});
        }
        sort(min_ans.begin(), min_ans.end());
        build(1, 1, n);
        ll ans = LINF;
        for(auto p : min_ans){
            // db(st[1][0][0] _ p.st _ p.nd.st _ p.nd.nd);
            ans = min(ans, st[1][0][0] - p.st);
            update(1, 1, n, p.nd.st, p.nd.nd);
        }
        cout << ans << "\n";
    }
    return 0;
}