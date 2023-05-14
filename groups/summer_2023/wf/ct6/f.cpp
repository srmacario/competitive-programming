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

map<int, vector<int>> cnt;
map<int, int> root;
vector<int> e, d, sum;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

int update(int pos, int ini, int fim, int id, int val){
    int novo = create();
    
    sum[novo] = sum[pos];
    e[novo] = e[pos];
    d[novo] = d[pos];
    pos = novo;

    if(ini == fim){
        sum[pos] += val;
        return novo;
    }

    int m = (ini + fim) >> 1;
    if(id <= m){
        int aux = update(e[pos], ini, m, id, val);
        e[pos] = aux;
    }
    else{
        int aux = update(d[pos], m + 1, fim, id, val);
        d[pos] = aux;
    }

    sum[pos] = sum[e[pos]] + sum[d[pos]];
    return pos;
}

int query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return 0;

    if(pos == 0) return 0;

    if(p <= ini and fim <= q) return sum[pos];
    
    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, p, q) + query(d[pos], m + 1, fim, p, q);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cnt[0].push_back(0);
    root[0] = create();
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x].push_back(i);
    }
    int r = 0;
    for(auto a : cnt){
        if(a.st == 0) continue;
        for(auto p : a.nd){
            r = update(r, 1, INF, p, a.st);
        }
        root[a.st] = r;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        int sum = 0, ans = 1;
        while(true){
            auto it = cnt.upper_bound(ans);
            it--;
            int p = root[it->st];
            sum = query(p, 1, INF, l, r);
            if(ans <= sum){
                ans = sum + 1;
            }
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}