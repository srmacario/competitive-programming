#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int cnt = 1, st[4*N], lc[4*N], rc[4*N], lazy[4*N], n;

void push(int p, int l, int r){
    if(lazy[p]){
        st[p] += (r-l+1)*lazy[p];
        if(l != r){
            if(lc[p])lazy[lc[p]] += lazy[p];
            if(rc[p])lazy[rc[p]] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int i, int j, int k){
    if(!p) return;
    if(!lc[p]) lc[p] = ++cnt;
    if(!rc[p]) rc[p] = ++cnt;
    push(p, l, r);
    if(r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] += k;
        push(p, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(lc[p],l,mid,i,j,k);
    update(rc[p],mid+1,r,i,j,k);
    st[p] = st[lc[p]] + st[rc[p]];
}

int query(int p, int l, int r, int i, int j){
    if(!p) return 0;
    push(p,l,r);
    if(r < i or j < l) return 0;
    if(i <= l and r <= j) return st[p];
    int mid = (l+r)/2;
    return query(lc[p], l, mid, i, j) + query(rc[p], mid+1, r, i, j);
}

void debug(int p){
    if(!p) return;
    cout << st[p] << " ";
    debug(lc[p]), debug(rc[p]);
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}