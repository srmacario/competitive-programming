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
const int N = 4e5+5, M = 2e5 + 5;

int st[4 * N];

void update(int p, int l, int r, int v, int pos){
    if(r < pos or l > pos) return;
    if(l >= pos and r <= pos) { st[p] = v; return; }

    int mid = (l + r) >> 1;
    update(2 * p, l, mid, v, pos);
    update(2 * p + 1, mid + 1, r, v, pos);
    st[p] = max(st[2 * p], st[2 * p + 1]);
}

int query(int p, int l, int r, int i, int j){
    if(r < i or l > j) return 0;
    if(l >= i and r <= j) return st[p];

    int mid = (l + r) >> 1;
    int x = query(2 * p, l, mid, i, j);
    int y = query(2 * p + 1, mid + 1, r, i, j);

    return max(x, y);
}

pii x[M];
int w[M];
int n;

map<int, int> id;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> val;
    for(int i = 0; i < n; i++){
        cin >> x[i].st >> w[i];
        x[i].nd = i;
        val.push_back(x[i].st + w[i]);
        val.push_back(x[i].st - w[i]);
    }
    sort(x, x + n);
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for(int i = 0; i < val.size(); i++){
        id[val[i]] = i + 1;
    }
    int sz = val.size();
    int resp = 0;
    for(int i = 0; i < n; i++){
        int ans = query(1, 1, sz, 1, id[x[i].st - w[x[i].nd]]);
        update(1, 1, sz, ans + 1, id[x[i].st + w[x[i].nd]]);
        resp = max(ans + 1, resp);
    }
    cout << resp << "\n";
    return 0;
}