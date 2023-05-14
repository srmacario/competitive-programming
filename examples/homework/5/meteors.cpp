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
const int N = 3e5+5;

struct sh{
    int l, r;
    ll a;
};

int n, m, k, obj[N];
int lo[N], hi[N];
vi has[N];
sh pred[N];
ll bit[N];
vi who[N];

void add(int p, int v) {
  for (p += 2; p < N; p += p & -p) bit[p] += v;
}

ll query(int p) {
  ll r = 0;
  for (p += 2; p; p -= p & -p) r += bit[p];
  return r;
}

void ins(sh x, int sgn){
    if(x.l <= x.r){
        add(x.l, x.a*sgn), add(x.r+1, -x.a*sgn);
    }
    else{
        add(1, x.a*sgn), add(x.r+1, -x.a*sgn);
        add(x.l, x.a*sgn), add(m+1, -x.a*sgn);
    }
}

bool upd_range(int i, int mid){
    //se for igual ja achou pra aquela empresa
    if(lo[i] == hi[i]) return false;
    //testa se a soma atingiu objetivo da empresa
    ll sum = 0;
    for(auto pos : has[i]){
        sum += query(pos);
        if(sum >= obj[i]) break;
    }
    //se sim, aquela é uma posição favorável
    if(sum >= obj[i]) hi[i] = mid;
    //senão, descarta todos para trás
    else lo[i] = mid + 1;
    who[(lo[i] + hi[i])/2].pb(i);
    return true;
}

int btree(int i, int j, int cur){
    //a função retornará até qual chuva a segtree está atualizada
    //out of bounds
    if(i == j) return cur;
    int mid = (i + j)/2;
    //adiciona/subtrai até chegar no mid atual
    while(cur < mid) ins(pred[++cur], 1);
    while(cur > mid) ins(pred[cur--], -1);
    //checa se naquele range existe alguem ainda passível de propagação
    bool ok = false;
    while(who[mid].size()){
        int x = who[mid].back();
        who[mid].pop_back();
        ok = upd_range(x, mid);
    }
    //saiu da checagem com ok = false
    //nao propaga mais
    if(!ok) return cur;
    else{
        cur = btree(mid + 1, j, cur);
        cur = btree(i, mid, cur);
    }
    return cur;
}

int main(){
    //read
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
        int sec;
        scanf("%d", &sec);
        has[sec].pb(i);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &obj[i]);
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) scanf("%d%d%lld", &pred[i].l, &pred[i].r, &pred[i].a);
    //init
    for(int i = 1; i <= n; i++) lo[i] = 1, hi[i] = k + 1, who[(k+2)/2].pb(i);
    //run parallel
    btree(1, k+1, 0);
    //print answer
    for(int i = 1; i <= n; i++){
        assert(lo[i] == hi[i]);
        if(lo[i] > k) printf("NIE\n");
        else printf("%d\n", lo[i]);
    }
    return 0;
}