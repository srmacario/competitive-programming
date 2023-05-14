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
const int N = 2e5+5;

map<string, int> drink;

int st[4*N], v[N];

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] = v; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) st[p] = st[2*p]+st[2*p+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,q;
    cin >> n >> m >> q;
    vector <string> ini;
    for(int i=0;i<n;i++){
        string d;
        cin >> d;
        ini.pb(d);
    }
    for(int i=0;i<m;i++){
        string d;
        int v;
        cin >> d >> v;
        drink[d] = v;
    }
    for(int i=0;i<n;i++){
        update(1,1,n,i+1,drink[ini[i]]);
    }
    for(int i=0;i<q;i++){
        int o;
        cin >> o;
        if(o == 1){
            int p;
            string d;
            cin >> p >> d;
            update(1,1,n,p,drink[d]);
        }
        else{
            int l, r;
            cin >> l >> r;
            int ans = query(1,1,n,l,r);
            if(ans <= (r-l+1)*30) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}