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

int n,q;

int v[N];

int stm[4*N];

int querym (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return -INF;
    if (i <= l and r <= j) return stm[p];
    int x = querym(2*p, l, (l+r)/2, i, j);
    int y = querym(2*p+1, (l+r)/2+1, r, i, j);
    return max(x, y);
}

void updatem (int p, int l, int r, int x, int v) {
    if (x < l or r < x) return;
    if (l == r and l == x) {stm[p] = v; return;}
    updatem (2*p, l, (l+r)/2, x, v);
    updatem (2*p+1, (l+r)/2+1, r, x, v);
    if (l != r) stm[p] = max(stm[2*p], stm[2*p+1]);
}

int buscar(int pos, int l, int r, int targ){
    int m;
    while(l < r){
        m = l + (r-l)/2;
        if(querym(1,0,n,pos,pos+m) <= targ) l = m+1;
        else r = m; 
    }
    if(l == pos){
        if(querym(1,0,n,l,l) <= targ) return l;
        return l-1;
    }
    return l;
}
int buscal(int pos, int l, int r, int targ){
    int m;
    while(l < r){
        m = l + (r-l)/2;
        if(querym(1,0,n,pos-m,pos) <= targ) l = m+1;
        else r = m; 
    }
    if(l == pos){
        if(querym(1,0,n,l,l) <= targ) return l;
        return l-1;
    }
    return l;
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=2;i<=n;i++){
        abs(v[i] - v[i-1]);
        updatem(1,0,n,i-1,abs(v[i]-v[i-1]));
    }
    updatem(1,0,n,0,-INF);
    updatem(1,0,n,N,-INF);
    for(int j=0;j<q;j++){
        int op,i,H;
        scanf("%d%d%d",&op,&i,&H);
        if(op == 1){
            v[i] = H;
            int left = -1, right = -1;
            if(i > 1){
                left = v[i-1];
                updatem(1,0,n,i-1, abs(H-left));
            }
            if(i < n){
                right = v[i+1];
                updatem(1,0,n,i, abs(H-right));
            }
        }
        if(op == 2){
            int ans = 0;
            ans += buscal(i-1,0,i-1,H);
            ans += buscar(i,0,n-i,H);
            printf("%d\n",ans+1);
        }
    }
    return 0;
}