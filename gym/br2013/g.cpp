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


int st[4*N], v[N], nxtr[N], nxtl[N];

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
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
    while(cin >> n){
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        build(1,1,n);
        vi peak;
        for(int i=2;i<n;i++){
            if(v[i] > v[i-1] and v[i] > v[i+1]) peak.pb(i);
        }
        vi s;
        for(int i=0;i<peak.size();i++){
            while(s.size() and v[s.back()] < v[peak[i]]){
                nxtr[s.back()] = peak[i];
                s.pop_back();
            }
            s.pb(peak[i]);
        }
        s.clear();
        for(int i=peak.size()-1;i>=0;i--){
            while(s.size() and v[s.back()] < v[peak[i]]){
                nxtl[s.back()] = peak[i];
                s.pop_back();
            }
            s.pb(peak[i]);
        }
        vi ans;
        for(auto p : peak){
            bool okl = true, okr = true;
            if(nxtl[p]){
                int d = v[p] - query(1,1,n,nxtl[p],p);
                if(d < 150000) okl = false;     
            }
            if(nxtr[p]){
                int d = v[p] - query(1,1,n,p,nxtr[p]);
                if(d < 150000) okr = false;
            }
            if(okl and okr) ans.pb(p);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << ((i==ans.size()-1) ? "\n" : " ");
        }
        for(int i=1;i<=n;i++) v[i] = nxtl[i] = nxtr[i] = 0;
    }
    return 0;
}