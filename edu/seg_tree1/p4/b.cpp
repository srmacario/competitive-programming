/*arvore
numeros
upd soma no caminho simples
qry gcd*/
#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5 + 5;
const pair<pii, pii> ID  = {{1, 0}, {0, 1}};

int r, n, m;

pair<pii, pii> st[4*N], v[N];

pair<pii, pii> calc(pair<pii, pii> x, pair<pii, pii> y){
    pair<pii, pii> ans;
    ans.st.st = ((x.st.st * y.st.st)%r + (x.st.nd * y.nd.st)%r)%r;
    ans.st.nd = ((x.st.st * y.st.nd)%r + (x.st.nd * y.nd.nd)%r)%r;
    ans.nd.st = ((x.nd.st * y.st.st)%r + (x.nd.nd * y.nd.st)%r)%r;
    ans.nd.nd = ((x.nd.st * y.st.nd)%r + (x.nd.nd * y.nd.nd)%r)%r;
    return ans;
}

pair<pii, pii> query (int p, int l, int r, int i, int j) {
    if (r < i or j < l) return ID;
    if (i <= l and r <= j) return st[p];
    pair<pii, pii> x = query(2*p, l, (l+r)/2, i, j);
    pair<pii, pii> y = query(2*p+1, (l+r)/2+1, r, i, j);
    return calc(x, y);
}

void build (int p, int l, int r) {
    if (l == r) {st[p] = v[l]; return;}
    build (2*p, l, (l+r)/2);
    build (2*p+1, (l+r)/2+1, r);
    st[p] = calc(st[2*p], st[2*p+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i].st.st >> v[i].st.nd >> v[i].nd.st >> v[i].nd.nd;
    }

    build(1, 1, n);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        
        pair<pii, pii> ans = query(1, 1, n, l, r);
        cout << ans.st.st << " " << ans.st.nd << "\n";
        cout << ans.nd.st << " " << ans.nd.nd << "\n";
        cout << "\n";
    }
    return 0;
}
/*
    


*/
