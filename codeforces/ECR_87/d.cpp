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
const int N = 1e6+5;

int st[4*N];

int query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[p];
    int x = query(2*p, l, (l+r)/2, i, j);
    int y = query(2*p+1, (l+r)/2+1, r, i, j);
    return x+y;
}

void update (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[p] += v; return;}
    update (2*p, l, (l+r)/2, x, v);
    update (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) st[p] = st[2*p]+st[2*p+1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        update(1,1,n,x,1);
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        if(x > 0) update(1,1,n,x,1);
        else{
            x = -x;
            int l = 1, r = n, p = 1;
            while(l <= r){
                if(l == r){
                    update(1,1,n,l,-1);
                    break;
                }
                int mid = (l+r)/2;
                int lq, rq;
                lq = st[2*p];
                rq = st[2*p + 1];
                if(lq >= x) r = mid, p = 2*p;
                else l = mid+1, p = 2*p+1, x -= lq;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(query(1,1,n,i,i) > 0){
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}