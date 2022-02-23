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

int n, m, cnt;
vi st[4*N], v;
map <int,int> id;

vi merge(vi &vl, vi &vr){
    int pl = 0, pr = 0, pos = 0;
    vi ans;
    while(pl < vl.size() or pr < vr.size()){
        if(pl >= vl.size()) ans.pb(vr[pr++]);
        else if(pr >= vr.size()) ans.pb(vl[pl++]);
        else if(vr[pr] > vl[pl]) ans.pb(vl[pl++]);
        else ans.pb(vr[pr++]);
    }
    return ans;
}

void build(int p, int l, int r){
    if(l == r){
        st[p] = vi(1, v[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p + 1, mid + 1, r);
    st[p] = merge(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j, int x){
    if(l > j or r < i) return 0;
    if(i <= l and r <= j) return (upper_bound(st[p].begin(), st[p].end(), x) - st[p].begin());
    int mid = (l+r)/2;
    return query(2*p, l, mid, i, j, x) + query(2*p+1, mid+1, r, i, j, x);
}

int binS(int i, int j, int x){
    int l = 1, r = cnt;
    while(l < r){
        int mid = (l+r)/2;
        if(query(1, 1, n, i, j, id[mid]) < x) l = mid + 1;
        else r = mid;
    }
    return id[l];
}

void compress(){
    id[++cnt] = st[1][0];
    for(int i = 1; i < st[1].size(); i++){
        if(st[1][i] != st[1][i-1]){
            id[++cnt] = st[1][i];
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    v.resize(n+5);
    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
    build(1, 1, n);
    compress();
    for(int i = 0; i < m; i++){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", binS(l, r, k));
    }
    return 0;
}