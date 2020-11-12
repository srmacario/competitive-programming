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
const int N = 1e7+5, mx = 1e9;

int cnt = 1, st[N], lc[N], rc[N], lazy[N], n;

struct eve{
    int x1,y1,y2,s;
};

vector <eve> e;

void push(int p, int l, int r){
    if(lazy[p]){
        st[p] = (r-l+1) - st[p];
        if(l != r){
            if(lc[p]) lazy[lc[p]] ^= 1;
            if(rc[p]) lazy[rc[p]] ^= 1;
        }
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int i, int j){
    if(!p) return;
    if(!lc[p]) lc[p] = ++cnt;
    if(!rc[p]) rc[p] = ++cnt;
    push(p, l, r);
    if(r < i or j < l) return;
    if (i <= l and r <= j) {
        lazy[p] = 1;
        push(p, l, r);
        return;
    }
    int mid = (l+r)/2;
    update(lc[p],l,mid,i,j);
    update(rc[p],mid+1,r,i,j);
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

bool cmp(eve a, eve b){
    if(a.x1 == b.x1) return a.s < b.s;
    return a.x1 < b.x1;
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
    cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        eve x;
        x.x1 = a, x.y1 = b, x.y2 = d, x.s = 1;
        e.pb(x);
        x.x1 = c, x.s = -1;
        e.pb(x);
    }
    sort(e.begin(),e.end(),cmp);
    ll ans = 0;
    for(int i=0;i<e.size();i++){
        if(i){
            ll pans = query(1,0,mx,0,mx);
            pans *= e[i].x1 - e[i-1].x1;
            ans += pans;
        }
        update(1,0,mx,e[i].y1,e[i].y2 - 1);
    }
    cout << ans << "\n";
    return 0;
}