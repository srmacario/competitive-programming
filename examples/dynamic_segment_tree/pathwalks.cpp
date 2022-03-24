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

#include <bits/stdc++.h>

vector<int> e, d, mx;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    mx.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return mx.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        mx[pos] = max(val, mx[pos]);
        return;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        if(e[pos] == 0){
            int aux = create();
            e[pos] = aux;
        }
        update(e[pos], ini, m, id, val);
    }
    else{
        if(d[pos] == 0){
            int aux = create();  
            d[pos] = aux;
        }
        update(d[pos], m + 1, fim, id, val);
    }

    mx[pos] = max(mx[e[pos]], mx[d[pos]]);
}

int query(int pos, int ini, int fim, int l, int r){
    if(r < ini or l > fim) return 0;

    if(pos == 0) return 0;

    if(l <= ini and r >= fim) return mx[pos];

    int m = (ini + fim) >> 1;
    return max(query(e[pos], ini, m, l, r), query(d[pos], m + 1, fim, l, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //init segtree
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) create();
    for(int i = 0; i < m; i++){
        int u, v, p;
        cin >> u >> v >> p;
        int cur = query(u, 0, N, 0, p - 1);
        //db(cur);
        update(v, 0, N, p, cur + 1);
    }
    int ans = -INF;
    for(int i = 1; i <= n; i++) ans = max(ans, mx[i]);
    cout << ans << "\n";
    return 0;
}