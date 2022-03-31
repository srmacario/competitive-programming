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
const int N = 1e5+5, M = 1e9;

#include <bits/stdc++.h>

vector<int> e, d, sum, mn;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    mn.push_back(INF);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        sum[pos] = val;
        mn[pos] = ini;
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
    mn[pos] = min(mn[e[pos]], mn[d[pos]]);
}

int k_query(int pos, int ini, int fim, int k){
    //db(pos _ ini _ fim);
    //if(pos == 0) return 0;

    if(ini == fim) return ini;

    int m = (ini + fim) >> 1;

    if(sum[e[pos]] >= k)
        return k_query(e[pos], ini, m, k);
    
    return k_query(d[pos], m + 1, fim, k - sum[e[pos]]);
}

int c_query(int pos, int ini, int fim, int k){
    if(pos == 0) return 0;

    if(ini == fim){
        if(k == ini) return 0;
        return sum[pos];
    }

    int m = (ini + fim) >> 1;
    
    if(mn[d[pos]] <= k){
        return sum[e[pos]] + c_query(d[pos], m + 1, fim, k);
    }
    return c_query(e[pos], ini, m, k);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //init segtree
    create(), create();
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'I'){
            update(1, -M, M, x, 1);
            //db(sum[1]);
        }
        if(c == 'D'){
            update(1, -M, M, x, 0);
            //db(sum[1]);
        }
        if(c == 'C'){
            cout << c_query(1, -M, M, x) << "\n";
        }
        if(c == 'K'){
            if(sum[1] < x) cout << "invalid\n";
            else cout << k_query(1, -M, M, x) << "\n";
        }
    }
    return 0;
}