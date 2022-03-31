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
const ll M = 1e15;

#include <bits/stdc++.h>

vector<int> e, d;
vector<piii> mx;
//begin creating node 0, then start your segment tree creating node 1
int create(){
    mx.push_back({0, {0, 0}});
    e.push_back(0);
    d.push_back(0);
    return mx.size() - 1;
}

void update(int pos, ll ini, ll fim, ll id, piii val){
    if(id < ini || id > fim) return;

    if(ini == fim){
        mx[pos] = max(val, mx[pos]);
        return;
    }

    ll m = (ini + fim) >> 1;
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

piii query(int pos, ll ini, ll fim, ll l, ll r){
    if(r < ini or l > fim) return {0, {0, 0}};

    if(pos == 0) return {0, {0, 0}};

    if(l <= ini and r >= fim) return mx[pos];

    ll m = (ini + fim) >> 1;
    return max(query(e[pos], ini, m, l, r), query(d[pos], m + 1, fim, l, r));
}

vi ans;
int to[N];

void dfs(int u){
    if(u == 0) return;
    ans.pb(u);
    dfs(to[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //init segtree
    create(), create();
    int n, d;
    cin >> n >> d;
    vector<ll> h(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        piii l = {0, {0, 0}}, r = {0, {0, 0}};
        if(1ll <= h[i] - d) l = query(1, 1, M, 1, h[i] - d);
        if(h[i] + d <= M) r = query(1, 1, M, h[i] + d, M);
        piii cur = max(l, r);
        cur.st++;
        cur.nd.st = cur.nd.nd;
        cur.nd.nd = i;
        to[i] = cur.nd.st;
        update(1, 1, M, h[i], cur);
    }
    piii cur = mx[1];
    cout << cur.st << "\n";
    dfs(cur.nd.nd);
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a << " ";
    cout << "\n";
    return 0;
}