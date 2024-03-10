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
const int N = 1e3+5;

struct frac{
    ll n, d;
    frac() = default;

    frac(ll _n, ll _d){
        ll gcd = abs(__gcd(_n, _d));
        int sign = 1;
        if(_n * _d < 0 ) sign = -1;
        
        n = sign * (abs(_n) / gcd);
        d = (abs(_d) / gcd);
    }
    
    bool operator < (const frac& f) const{
        return this->n * f.d < f.n * this->d;
    }
    
    bool operator == (const frac& f) const{
        return this->n * f.d == f.n * this->d;
    }
};

struct line{
    ll s, t;

    line() = default;

    line(ll _s, ll _t) : s(_s), t(_t) {}

    ll eval(ll T){ return s * (t - T); }

    frac inter(line x){
        return frac(x.s * x.t - this->s * this->t, x.s - this->s);
    }
};

struct photo{
    ll u, a, b;

    photo() = default;

    photo(ll _u, ll _a, ll _b) : u(_u), a(_a), b(_b) {}
};

//si (ti - T) = sj (tj - T)
//T = (sj * tj - si * ti) / (sj - si)

struct event{
    frac T;
    int type;
    //type = 0: a, b indices de runners
    //type = 1: a, b range
    ll a, b;

    event() = default;
    event(frac _T, int _type, ll _a, ll _b) : T(_T), type(_type), a(_a), b(_b){}

    bool operator < (const event& e) const{
        if(this->T == e.T){
            return this->type < e.type;
        }
        return this->T < e.T;
    }
};

int r, p;
line runners[N];
photo ph[N];
vector<photo> trash;
vector<event> sweep;
map<int, int> pos;

ll origin = -LINF;
bool cmp(line a, line b){
    return a.eval(origin) < b.eval(origin);
}

//tratar reta igual

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r;
    for(int i = 0; i < r; i++){
        cin >> runners[i].t >> runners[i].s;
    }
    for(int i = 0; i < p; i++){
        cin >> ph[i].u >> ph[i].a >> ph[i].b;
        //botar as photos no sweep
        sweep.push_back({frac(ph[i].u, 1), 1, ph[i].a, ph[i].b});
    }
    //calcular as intersecoes
    for(int i = 0; i < r; i++){
        for(int j = i + 1; j < r; j++){
            if(runners[i].s == runners[j].s) continue;
            sweep.push_back({runners[i].inter(runners[j]), 0, i, j});
        }
    }
    for(int i = 0; i < (int)sweep.size(); i++){
        if(sweep[i].type == 0){
            event cur = sweep[i];
            pair<int, int> L = {pos[cur.a], cur.a}, R = {pos[cur.b], cur.b};
            while(i - 1 < (int)sweep.size() and cur.T == sweep[i + 1].T){
                L = min({pos[sweep[i + 1].a], sweep[i + 1].a}, L);
                R = max({pos[sweep[i + 1].b], sweep[i + 1].b}, R);
                i++;
            }
            for(int j = 0; j < (R.st - L.st + 1) / 2; j++){
                swap(runners[L.st + j], runners[R.st - j]);
                swap(pos[L.nd], pos[R.nd]);
            }
        }
        else{
            int L = 0, R = r - 1;
            bool ok = false;
            while(R >= L){
                int mid = (R + L) / 2;
                if(runners[mid].eval(sweep[i].T.n) > sweep[i].b) R = mid - 1;
                else if(runners[mid].eval(sweep[i].T.n) < sweep[i].a) L = mid + 1;
                else {
                    ok = true;
                    break;
                }
            }
            if(!ok) trash.push_back({sweep[i].T.n, sweep[i].a, sweep[i].b});
        }
    }
    return 0;
}