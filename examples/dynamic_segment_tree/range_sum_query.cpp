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

vector<ll> e, d, sum;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        sum[pos] = val;
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

    sum[pos] = sum[e[pos]] + sum[d[pos]];
}

ll query(int pos, int ini, int fim, int l, int r){
    if(r < ini or l > fim) return 0;

    if(pos == 0) return 0;

    if(l <= ini and r >= fim) return sum[pos];

    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, l, r) + query(d[pos], m + 1, fim, l, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //init segtree
    create(), create();
    int n, m;
    cin >> n >> m;
    ll P = 91, Q = 47;
    for(int i = 0; i < m; i++){
        char c;
        ll a, b;
        cin >> c >> a >> b;
        if(c == '!'){
            update(1, 0, n, (a + P) % n, (b + Q) % MOD);
        }
        else{
            int l = (a + P) % n, r = (b + Q) % n;
            if(l > r) swap(l, r);
            ll z = query(1, 0, n, l, r);
            cout << z << "\n";
            P = (((P * 31)%MOD + z) % MOD);
            Q = (((Q * 29)%MOD + z) % MOD);
        }
    }
    return 0;
}