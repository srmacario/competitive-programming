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

pii st[4*N];
int v[N], n,q;

int ub(int l, int r, int x){
    while(l<r){
        int mid = (l+r+1)/2;
        if(v[mid] > x) r = mid - 1;
        else l = mid;
    }
    return (v[l] == x) ? l : -1;
}

int lb(int l, int r, int x){
    while(l<r){
        int mid = (l+r)/2;
        if(v[mid] < x) l = mid + 1;
        else r = mid;
    }
    return (v[l] == x) ? l : -1;
}

void build (int p, int l, int r) {
    if (l == r) {st[p].st = v[l]; st[p].nd = 1; return;}
    int mid = (l+r)/2;
    build (2*p, l, mid);
    build (2*p+1, mid+1, r);
    int countl = st[2*p].nd + ub(mid+1,r,st[2*p]) - lb(mid+1,r,st[2*p]) + 1;
    int countr = st[2*p+1].nd + ub(l,mid,st[2*p+1]) - lb(l,mid,st[2*p+1]) + 1;
    if(count)
    st[p].nd = st[2*p].ndst[2*p+1].nd;
}

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=q;i++){
        int l,r;
        cin >> l;
        if(!l) return 0;
        cin >> r;
        //cout << ub(1,n,1) - lb(1,n,1) + 1 << "\n";
    }
    cin >> q;
    return 0;
}