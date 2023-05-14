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
const int INF = 1e9, MOD = 1e9+7;
const int N = 2e5+5;

//max seg tree
vector<int> e_mx, d_mx, e, d, sum_st, pref_st;
vector<pii> mx_st;

int mx_create(){
    mx_st.push_back({0, 0});
    e_mx.push_back(0);
    d_mx.push_back(0);
    return (int)mx_st.size() - 1;
}

void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        mx_st[pos] = {val, id};
        return;
    }
    int m = (ini + fim) >> 1;
    if(id <= m){
        if(e_mx[pos] == 0){
            int aux = mx_create();
            e_mx[pos] = aux;
        }
        update(e_mx[pos], ini, m, id, val);
    }
    else{
        if(d_mx[pos] == 0){
            int aux = mx_create();
            d_mx[pos] = aux;
        }
        update(d_mx[pos], m + 1, fim, id, val);
    }

    mx_st[pos] = max(mx_st[e_mx[pos]], mx_st[d_mx[pos]]);
}

pii query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return {0, 0};
    if(pos == 0) return {0, 0};
    if(p <= ini and fim <= q) return mx_st[pos];

    int m = (ini + fim) >> 1;
    return max(query(e_mx[pos], ini, m, p, q), query(d_mx[pos], m + 1, fim, p, q));
}

//sum seg tree

int sum_create(){
    sum_st.push_back(0);
    pref_st.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return (int)sum_st.size() - 1;
}

void update_sum(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        sum_st[pos] += val;
        //db(ini _ fim _ pref_st[pos]);
        pref_st[pos] += val;
        //db(ini _ fim _ pref_st[pos]);
        return;
    }
    int m = (ini + fim) >> 1;
    if(id <= m){
        if(e[pos] == 0){
            int aux = sum_create();
            e[pos] = aux;
        }
        update_sum(e[pos], ini, m, id, val);
    }
    else{
        if(d[pos] == 0){
            int aux = sum_create();
            d[pos] = aux;
        }
        update_sum(d[pos], m + 1, fim, id, val);
    }

    sum_st[pos] = sum_st[e[pos]] + sum_st[d[pos]];
    int pref_l = pref_st[e[pos]];
    int pref_r = pref_st[d[pos]];
    pref_r += sum_st[e[pos]];
    pref_st[pos] = min({pref_l, pref_r});
}

int sum_query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return 0;
    if(pos == 0) return 0;
    if(p <= ini and fim <= q) return sum_st[pos];

    int m = (ini + fim) >> 1;
    return sum_query(e[pos], ini, m, p, q) + sum_query(d[pos], m + 1, fim, p, q);
}

int pref_query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return INF;
    if(pos == 0) return 0;
    if(p <= ini and fim <= q) return pref_st[pos];

    int m = (ini + fim) >> 1;
    int sum_l = sum_query(e[pos], ini, m, p, q);
    int pref_l = pref_query(e[pos], ini, m, p, q);
    int pref_r = pref_query(d[pos], m + 1, fim, p, q);
    pref_r += sum_l;
    return min(pref_l, pref_r);
}

int pref_search(int pos, int ini, int fim, int p, int q, int val){
    if(q < ini || p > fim) return INF;
    if(pos == 0){
        if(val == 0) return max(ini, p);
        return INF;
    }

    int m = (ini + fim) >> 1;
    if(p <= ini and fim <= q){
        //lesser prefix is not on this branch, return
        if(val != pref_st[pos]) return INF;
        //unitary prefix
        if(ini == fim) return ini;
    }
    //answer is to the left?
    int pref_l = pref_search(e[pos], ini, m, p, q, val);
    if(pref_l != INF) return pref_l;
    //otherwise go right
    int sum_l = sum_query(e[pos], ini, m, p, q);
    int pref_r = pref_search(d[pos], m + 1, fim, p, q, val - sum_l);
    return pref_r;
}

int n, m, s[N];
map<int, vector<int>> dish;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++){
        int h, t;
        cin >> h >> t;
        dish[h + 1].push_back(t);
    }
    //create initial nodes
    mx_create(), sum_create();
    int mx = mx_create();
    int sum = sum_create();

    for(auto& h : dish){
        sort(h.nd.begin(), h.nd.end());
        int val = h.nd.back(), pos = h.st;
        h.nd.pop_back();
        update(mx, 1, INF, pos, val);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int mn = pref_query(sum, 1, INF, s[i], INF);
        int pos = pref_search(sum, 1, INF, s[i], INF, mn);
        pii new_dish = query(mx, 1, INF, 1, pos);
        if(!new_dish.st){
            cout << ans << " ";
            continue;
        }
        ans += new_dish.st;
        update_sum(sum, 1, INF, s[i], -1);
        update_sum(sum, 1, INF, new_dish.nd, 1);
        new_dish.st = 0;
        if(dish[new_dish.nd].size()){
            new_dish.st = dish[new_dish.nd].back();
            dish[new_dish.nd].pop_back();
        }
        update(mx, 1, INF, new_dish.nd, new_dish.st);
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}