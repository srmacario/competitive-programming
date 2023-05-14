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

map<int, vector<int>> h;
map<int, int> root;
vector<int> e, d, seg, pref, suf;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    seg.push_back(0);
    pref.push_back(0);
    suf.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return seg.size() - 1;
}

int update(int pos, int ini, int fim, int id, int val){
    int novo = create();
    
    seg[novo] = seg[pos];
    pref[novo] = pref[pos];
    suf[novo] = suf[pos];
    e[novo] = e[pos];
    d[novo] = d[pos];
    pos = novo;

    if(ini == fim){
        seg[pos] = pref[pos] = suf[pos] = 1;
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
    pref[pos] = pref[e[pos]];
    if(pref[pos] == (m - ini + 1)) pref[pos] += pref[d[pos]];

    suf[pos] = suf[d[pos]];
    if(suf[pos] == (fim - m)) suf[pos] += suf[e[pos]];
    
    seg[pos] = max({seg[e[pos]], seg[d[pos]], pref[pos], suf[pos], suf[e[pos]] + pref[d[pos]]});
    return pos;
}

int query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim) return 0;
    if(pos == 0) return 0;

    if(p <= ini and fim <= q){
        return seg[pos];
    }
    
    int m = (ini + fim) >> 1;
    int resp = max({query(e[pos], ini, m, p, q), query(d[pos], m + 1, fim, p, q), min(m - p + 1, suf[e[pos]]) + min(q - m, pref[d[pos]])});
    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    root[0] = create();
    vector<int> ids;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        h[x].push_back(i);
        ids.push_back(x);
    }
    sort(ids.begin(), ids.end());
    ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
    int r = 0;
    for(auto p = h.rbegin(); p != h.rend(); p++){
        for(auto ph : p->nd){
            r = update(r, 1, INF, ph, 1);
        }
        root[p->st] = r;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int l, r, w;
        cin >> l >> r >> w;
        int lo = 0, hi = ids.size() - 1;
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(query(root[ids[mid]], 1, INF, l, r) >= w) lo = mid;
            else hi = mid - 1;
        }
        cout << ids[lo] << "\n";
    }
    return 0;
}