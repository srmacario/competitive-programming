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

int st[4*N];

void build (int p, int l, int r) {
    st[p] = INF;
    if (l == r) return;
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <piii> eng;
        for(int i=0;i<n;i++){
            int r1,r2,r3;
            cin >> r1 >> r2 >> r3;
            eng.pb({r1,{r2,r3}});
        }
        sort(eng.begin(),eng.end());
        ll ans = 1;
        pii e = eng[0].nd;
        build(1,1,n);
        update(1,1,n,e.st,e.nd);
        for(int i = 1; i<n; i++){
            e = eng[i].nd;
            int mn = query(1,1,n,1,e.st-1);
            //db(e.nd), db(mn);
            if(mn > e.nd) ans++;
            update(1,1,n,e.st,e.nd);
        }
        cout << ans << "\n";
    }
    return 0;
}