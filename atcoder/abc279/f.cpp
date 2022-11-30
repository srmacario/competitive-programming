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
const int N = 1e6+5;

int par[N];
int cur_par[N], id_par[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  par[b] = a;
}

int n, q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 0; i < N; i++) par[i] = i;
    for(int i = 1; i <= n; i++) unite(N - i - 1, i), id_par[N - i - 1] = i, cur_par[i] = N - i - 1;
    int k = n, last_par = N - n - 1;
    for(int i = 0; i < q; i++){
        int op, x, y;
        cin >> op;
        if(op == 1){
            cin >> x >> y;
            unite(cur_par[x], cur_par[y]);
            last_par--;
            id_par[last_par] = y, cur_par[y] = last_par;
        }
        if(op == 2){
            cin >> x;
            unite(cur_par[x], ++k);
        }
        if(op == 3){
            cin >> x;
            cout << id_par[find(x)] << "\n";
        }
    }
    return 0;
}