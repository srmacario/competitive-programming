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

int s[N];

int st[4*N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = INF; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = min(st[2*p], st[2*p+1]);
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] = v; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) st[p] = min(st[2*p], st[2*p+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> cnt(n + 5), l_nd, pos_l(n + 5), r_nd(n + 5), ans(n + 5);
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        ++cnt[s[i]];
        if((cnt[s[i]]) == 2){
            l_nd.push_back(i);
            pos_l[s[i]] = i;
            update(1, 1, n, i, s[i]);
        }
    }
    for(int i = 0; i < cnt.size(); i++) cnt[i] = 0;
    for(int i = n; i >= 1; i--){
        if((++cnt[s[i]]) == 2){
            r_nd[s[i]] = i;
            //cout << s[i] << " " << i << "\n";
        }
    }
    sort(l_nd.begin(), l_nd.end());
    //for(auto l : l_nd) cout << l << " ";
    //cout << "\n";
    for(int i = n; i >= 1; i--){
        if(r_nd[s[i]] and r_nd[s[i]] != i){
            int r = n;
            auto l = (upper_bound(l_nd.begin(), l_nd.end(), r_nd[s[i]]));
            if(l == l_nd.end()) continue;
            //cout << *l << " " << r << "\n";
            if(pos_l[s[i]]) update(1, 1, n, pos_l[s[i]], INF);
            if(*l <= r){
                ans[s[i]] = query(1, 1, n, *l, r);
                //cout << s[i] << " " << ans[s[i]] << "\n";
            }
            if(pos_l[s[i]]) update(1, 1, n, pos_l[s[i]], s[i]);
        }
    }
    pii resp = {INF, INF};
    for(int i = 1; i <= n; i++){
        cout << i << " " << ans[i] << "\n";
        if(ans[i]) resp = min(resp, make_pair(ans[i], i));
    }
    if(resp.st == INF) cout << "-1\n";
    else cout << resp.st << " " << resp.nd << "\n";
    return 0;
}