#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n;
ll k, sum;

ll a[N], b[N];

ll st[4 * N];

void build(int p = 1, int l = 1, int r = n) {
    if (l == r) {
        if ((a[l] - b[l]) % k == 0) st[p] = LINF;
        else st[p] = (a[l] - b[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    st[p] = min(st[2 * p], st[2 * p + 1]);
}

ll query(int i, int j, int p = 1, int l = 1, int r = n) {
    if (l > j or r < i) return LINF;
    if (l >= i and r <= j) return st[p];

    int mid = (l + r) / 2;
    return min(query(i, j, 2 * p, l, mid), query(i, j, 2 * p + 1, mid + 1, r));
}

ll mult(ll a, ll b) { return (a * b) % MOD; }
ll add(ll a, ll b) { return a >= MOD - b ? a + b - MOD : a + b; }
ll sub(ll a, ll b) { return a >= b ? a - b : a - b + MOD; }

map<ll, int> idx;
vector<int> ops[N];
ll val[N], ps[N];

ll get_sum(int l, int r) { 
    return sub(ps[r], ps[l-1]);
}

int bin(int idx, int j, ll mn) {
    int l = 0, r = ops[idx][j], mid;

    while (l != r) {
        mid = (l + r) / 2;
        if (query(ops[idx][mid] + 1, ops[idx][j]) >= mn) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    ll sum2 = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        ps[i] = a[i];
        ps[i] = add(ps[i], ps[i-1]);
        if (a[i] < b[i]) swap(a[i], b[i]);
        sum = add(sum, mult(mult(i, n - i + 1), a[i]));
        sum2 = (sum2 + a[i]) % k;
        int j = idx[sum2];
        if (!j) {
            j = ++cnt;
            idx[sum2] = j;
        }
        ops[j].push_back(i);
    }

    build();

    for (int i = 1; i <= cnt; i++) {
        ll cnt_inf = 0;
        ll sum_inf = 0;
        for (int j = 1; j < (int)ops[i].size(); j++) {
            int _left = ops[i][j-1] + 1;
            int _right = ops[i][j];
            ll mn = query(_left, _right);
            int ll = bin(i, j - 1, mn);
            sum = sub(sum, val[ops[i][ll]]);
            if (mn == INF) {
                sum = sub(sum, sum_inf);
                cnt_inf++;
                sum = sub(sum, mult(cnt_inf, get_sum(_left, _right)));
                sum_inf = add(sum_inf, mult(cnt_inf, get_sum(_left, _right)));
            } else {
                cnt_inf = 0;
                sum_inf = 0;
                sum = sub(sum, mult(j - ll + 1, mn));
            }
            val[ops[i][j]] = sum;
        }
    }

    cout << sum << "\n";

    return 0;
}