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
const int N = 2e5+5;

int n, q;

vector<int> e, d, sum_root, cnt_root;
vector<ll> sum;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    sum.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return sum.size() - 1;
}

int update(int pos, int ini, int fim, int id, ll val){
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
    return novo;
}

ll query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return 0;

    if(pos == 0) return 0;

    if(p <= ini and fim <= q) return sum[pos];
    
    int m = (ini + fim) >> 1;
    return query(e[pos], ini, m, p, q) + query(d[pos], m + 1, fim, p, q);
}


int bin_s(int sum_l, int sum_r, int cnt_l, int cnt_r, int ini, int fim, int p, int q, ll s, ll cur_sum, ll cur_cnt){
    if(q < ini || p > fim) return 0;

    if(sum_r == 0) return 0;

    if(ini == fim){
        //db(sum[cnt_r] _ sum[cnt_l]);
        if(sum[cnt_r] - sum[cnt_l] == 0) return 0;

        ll val = (sum[sum_r] - sum[sum_l]) / (sum[cnt_r] - sum[cnt_l]);
        //db(val);

        if(val >= s) return (sum[cnt_r] - sum[cnt_l]);
        //db((cur_cnt * s - cur_sum));
        //db((s - val));
        return min((cur_sum - cur_cnt * s) / (s - val), sum[cnt_r] - sum[cnt_l]);
    }
    int m = (ini + fim) >> 1;
    ll query_sum_right = query(d[sum_r], m + 1, fim, p, q) - query(d[sum_l], m + 1, fim, p, q);
    ll query_cnt_right = query(d[cnt_r], m + 1, fim, p, q) - query(d[cnt_l], m + 1, fim, p, q);
    //db(ini _ m _ fim);
    //db(query_sum_right _ query_cnt_right);
    //db(cur_sum _ cur_cnt);
    if(query_sum_right + cur_sum >= (query_cnt_right + cur_cnt) * s){
        int l = bin_s(e[sum_l], e[sum_r], e[cnt_l], e[cnt_r], ini, m, p, q, s, cur_sum + query_sum_right, cur_cnt + query_cnt_right);
        return query_cnt_right + l;
    }
    return bin_s(d[sum_l], d[sum_r], d[cnt_l], d[cnt_r], m + 1, fim, p, q, s, cur_sum, cur_cnt);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    create();
    sum_root.push_back(create());
    cnt_root.push_back(create());
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        sum_root.push_back(update(sum_root.back(), 1, N, p, p));
        cnt_root.push_back(update(cnt_root.back(), 1, N, p, 1));
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r, a, b, s;
        cin >> l >> r >> a >> b >> s;
        cout << bin_s(sum_root[l - 1], sum_root[r], cnt_root[l - 1], cnt_root[r], 1, N, a, b, s, 0, 0) << "\n";
    }
    return 0;
}

/*
    k * val + sum >= (k + cnt) * s
    k * (val - s) + sum >= cnt * s
    k * (val - s) <= (cnt * s - sum)
    k * val >= k * s
*/