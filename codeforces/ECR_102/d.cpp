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

int mxst[4*N], mnst[4*N], v[N];

void mxbuild (int p, int l, int r) {
    if (l == r) {mxst[p] = v[l]; return;}
    mxbuild (2*p, l, (l+r)/2);
    mxbuild (2*p+1, (l+r)/2+1, r);
    mxst[p] = max(mxst[2*p], mxst[2*p+1]);
}

int mxquery (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return mxst[p];
    int x = mxquery(2*p, l, (l+r)/2, i, j);
    int y = mxquery(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void mnbuild (int p, int l, int r) {
    if (l == r) {mnst[p] = v[l]; return;}
    mnbuild (2*p, l, (l+r)/2);
    mnbuild (2*p+1, (l+r)/2+1, r);
    mnst[p] = min(mnst[2*p], mnst[2*p+1]);
}

int mnquery (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return INF;
    if (i <= l and r <= j) return mnst[p];
    int x = mnquery(2*p, l, (l+r)/2, i, j);
    int y = mnquery(2*p+1, (l+r)/2+1, r, i, j);
    return min(x, y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        int x = 0;
        v[0] = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '+') x++;
            if(s[i] == '-') x--;
            v[i+1] = x;
        }
        mnbuild(1,0,n), mxbuild(1,0,n);
        for(int i=0;i<m;i++){
            int l,r,mnr,mxr;
            cin >> l >> r;
            int mnl = mnquery(1,0,n,0,l-1);
            int mxl = mxquery(1,0,n,0,l-1);
            if(r == n) mnr = mnl, mxr = mxl;
            else{
                mnr = mnquery(1,0,n,r+1,n) + v[l-1] - v[r];
                mxr = mxquery(1,0,n,r+1,n) + v[l-1] - v[r];
            }
            //db(mnl _ mxl _ mnr _ mxr);
            cout << max(mxr,mxl) - min(mnl,mnr) + 1 << "\n"; 
        }
    }
    return 0;
}