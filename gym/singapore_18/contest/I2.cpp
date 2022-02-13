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
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 4e5 + 5;

vector<int> occur[N];
int left_most[N];
bool added[N];

pair<int, int> ans = { INF, INF };

int n, v[N];
pair<int, int> st[4 * N];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    vector<int> aux = { a.first, a.second, b.first, b.second };
    sort(aux.begin(), aux.end());
    aux.erase(unique(aux.begin(), aux.end()), aux.end());
    if (aux.size() < 2) aux.push_back(INF);
    return { aux[0], aux[1] };
}

void build(int p = 1, int l = 1, int r = n) {
    if (l == r) {
        st[p] = { INF, INF };
        return;
    }

    build(2 * p, l, (l + r) / 2);
    build(2 * p + 1, (l + r) / 2 + 1, r);
    st[p] = merge(st[2 * p], st[2 * p + 1]);
}

pair<int, int> query(int i, int j, int p = 1, int l = 1, int r = n) {
    if (l >= i and j >= r) return st[p];
    if (l > j or r < i) return { INF, INF };
    pair<int, int> lt = query(i, j, 2 * p, l, (l + r)/2);
    pair<int, int> rt = query(i, j, 2 * p + 1, (l + r) / 2 + 1, r);
    return merge(lt, rt);
}

void update(int idx, int v, int p = 1, int l = 1, int r = n) {
    if (l == r) { st[p] = { v, INF }; return; }
    if (idx <= (l + r) / 2) update(idx, v, 2 * p, l, (l + r) / 2);
    else update(idx, v, 2 * p + 1, (l + r) / 2 + 1, r);
    st[p] = merge(st[2 * p], st[2 * p + 1]);
}

void go(int pos) {
    if (added[v[pos]] == true) return;
    added[v[pos]] = true;
    for (int x : occur[v[pos]])
        update(x, v[pos]);
}

void upd_ans(int x, int y) {
    ans = min(ans, { x, y });
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    build();
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        occur[v[i]].push_back(i);
        left_most[v[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (left_most[v[i]] > i) {
            auto x = query(i, left_most[v[i]]);
            int mn = x.first;
            if (mn == v[i]) mn = x.second;

            upd_ans(mn, v[i]);
        }
        go(i);
    }

    if (ans.first == INF or ans.second == INF) {
        cout << -1 << "\n";
    } else {
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}