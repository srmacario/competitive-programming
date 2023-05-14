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
const ll M = 1e18;

int m;
ll n;
vector<pll> moss;

vector<int> e, d;
vector<ll> lazy;
vector<pair<ll, ll>> mn;

//begin creating node 0, then start your segment tree creating node 1
int create(ll ini, ll fim){
    mn.push_back({0ll, fim - ini + 1});
    lazy.push_back(0);
    e.push_back(0);
    d.push_back(0);
    return mn.size() - 1;
}

void push(int pos, ll ini, ll fim){
    if (lazy[pos]) {
        mn[pos].st += lazy[pos];
        if (ini != fim) {
            ll m = (ini + fim) >> 1;
            if(e[pos] == 0){
                int aux = create(ini, m);
                e[pos] = aux;
            }
            if(d[pos] == 0){
                int aux = create(m + 1, fim);
                d[pos] = aux;
            }
            lazy[e[pos]] += lazy[pos];
            lazy[d[pos]] += lazy[pos];
        }
        lazy[pos] = 0;
    }
}

void update(int pos, ll ini, ll fim, ll p, ll q, ll val){

    push(pos, ini, fim);

    if(q < ini || p > fim) return;

    if(p <= ini and fim <= q){
        lazy[pos] += val;
        push(pos, ini, fim);
        return;
    }

    ll m = (ini + fim) >> 1;
    if(e[pos] == 0){
        int aux = create(ini, m);
        e[pos] = aux;
    }
    update(e[pos], ini, m, p, q, val);

    if(d[pos] == 0){
        int aux = create(m + 1, fim);
        d[pos] = aux;
    }
    update(d[pos], m + 1, fim, p, q, val);
    push(e[pos], ini, m);
    push(d[pos], m + 1, fim);
    if(mn[e[pos]].st == mn[d[pos]].st) mn[pos] = {mn[e[pos]].st, mn[e[pos]].nd + mn[d[pos]].nd};
    else mn[pos] = min(mn[e[pos]], mn[d[pos]]);
}

pair<ll, ll> query(int pos, ll ini, ll fim, ll p, ll q){
    if(pos == 0) return {0, (fim - ini + 1)};

    push(pos, ini, fim);

    if(q < ini || p > fim) return {LINF, 0};

    if(p <= ini and fim <= q) return mn[pos];
    
    ll m = (ini + fim) >> 1;
    pair<ll, ll> lhs = query(e[pos], ini, m, p, q), rhs = query(d[pos], m + 1, fim, p, q);

    if(lhs.st == rhs.st) return {lhs.st, lhs.nd + rhs.nd};
    return min(lhs, rhs);
}

bool calc(ll t){
    e.clear();
    d.clear();
    lazy.clear();
    mn.clear();

    create(1ll, 0ll);
    create(1ll, n);

    vector<pll> hoz, ver;
    vector<pair<ll, pii>> sweep;

    //create events
    for(auto x : moss){
        hoz.pb({max(x.st - t, 1ll), min(x.st + t, n)});
        ver.pb({max(x.nd - t, 1ll), min(x.nd + t, n)});
        //0 for opening, 1 for closure
        sweep.pb({hoz.back().st, {0, hoz.size() - 1}});
        sweep.pb({hoz.back().nd + 1, {1, hoz.size() - 1}});
    }

    sort(sweep.begin(), sweep.end());
    for(int i = 0; i < sweep.size(); i++){
        pair<ll, pii> s = sweep[i];
        if(s.st > n){
            if(!query(1, 1ll, n, 1ll, n).st) return false;
            return true;
        }
        //erase
        if(s.nd.st){
            update(1, 1ll, n, ver[s.nd.nd].st, ver[s.nd.nd].nd, -1);
            if(!query(1, 1ll, n, 1ll, n).st) return false;
        }
        //insert
        else{
            // db(i _ s.st);
            if(!i and s.st != 1) return false;
            update(1, 1ll, n, ver[s.nd.nd].st, ver[s.nd.nd].nd, 1);
        }
    }
    if(!query(1, 1ll, n, 1ll, n).st) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    moss.resize(m);
    for(int i = 0; i < m; i++){
        cin >> moss[i].st >> moss[i].nd;
    }
    ll l = 0, r = n;
    while(l < r){
        ll mid = (l + r) >> 1;
        bool ok = calc(mid);
        if(ok) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}