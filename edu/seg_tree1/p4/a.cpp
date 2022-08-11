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
const int N = 1e5+5;

int n, m;

int st[2][4*N], v[2][N];

int query (int p, int l, int r, int i, int j, int par) {
    if (r < i or j < l) return 0;
    if (i <= l and r <= j) return st[par][p];
    int x = query(2*p, l, (l+r)/2, i, j, par);
    int y = query(2*p+1, (l+r)/2+1, r, i, j, par);
    return x+y;
}

void update (int p, int l, int r, int x, int v, int par) {
    if (x < l or r < x) return;
    if (l == r and l == x) {st[par][p] = v; return;}
    update (2*p, l, (l+r)/2, x, v, par);
    update (2*p+1, (l+r)/2+1, r, x, v, par);
    if (l != r) st[par][p] = st[par][2*p] + st[par][2*p + 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v[i%2][i];
        update(1, 1, n, i, v[i%2][i], i%2);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 0){
            update(1, 1, n, l, r, l%2);
            // db(query(1, 1, n, l, l, l%2));
        }
        else{
            int odd = query(1, 1, n, l, r, 1);
            int even = query(1, 1, n, l, r, 0);
            int sum = (even - odd);
            // db(odd _ even _ sum);
            if(l % 2) sum = -sum;
            cout << sum << "\n";
        }
    }
    return 0;
}