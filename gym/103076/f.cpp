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
const int INF = 0x3f3f3f3f, MOD = 1e9+9;
const int N = 2e5+5;

ll B = 31;
ll pot[N], invpot[N];

ll fexp(ll b, ll e, ll m = MOD){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans * b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

void pre(){
    pot[0] = 1;
    invpot[0] = 1;
    for(int i = 1; i < N; i++){
        pot[i] = (B * pot[i-1]) % MOD;
        invpot[i] = fexp(pot[i], MOD-2) % MOD;
    }
}

struct seg_tree{
    int sz;
    string s;
    vector<ll> sum, invsum;

    void build(int p, int l, int r){
        if(l == r){
            sum[p] = ((s[l] - 'a' + 1) * pot[l]) % MOD;
            invsum[p] = ((s[l] - 'a' + 1) * pot[sz - l - 1]) % MOD;
            return;
        }
        int mid = (l+r)/2;
        build(2*p, l, mid);
        build(2*p + 1, mid + 1, r);
        sum[p] = (sum[2*p] + sum[2*p + 1]) % MOD;
        invsum[p] = (invsum[2*p] + invsum[2*p + 1]) % MOD;
    }

    seg_tree(string x) : s(x){
        sz = (int) s.size();
        int pot2 = 1;
        while(pot2 < sz) pot2 *= 2;
        pot2 *= 2;
        pot2 += 5;
        sum.resize(pot2, 0);
        invsum.resize(pot2, 0);
        build(1, 0, sz-1);
    }

    void update(int p, int l, int r, int x){
        if(x < l or x > r) return;
        if(l == r and l == x){
            sum[p] = ((s[l] - 'a' + 1) * pot[l]) % MOD;
            invsum[p] = ((s[l] - 'a' + 1) * pot[sz - l - 1]) % MOD;
            return;
        }
        int mid = (l+r)/2;
        update(2*p, l, mid, x);
        update(2*p + 1, mid + 1, r, x);
        sum[p] = (sum[2*p] + sum[2*p + 1]) % MOD;
        invsum[p] = (invsum[2*p] + invsum[2*p + 1]) % MOD;
    }

    void upd(int x, char c){
        x--;
        s[x] = c;
        update(1, 0, sz - 1, x);
    }

    ll get_sum(int p, int l, int r, int i, int j){
        if(l > j or r < i) return 0;
        if(i <= l and r <= j) return sum[p] % MOD;
        int mid = (l + r)/2;
        ll sum_l = get_sum(2*p, l, mid, i, j);
        ll sum_r = get_sum(2*p + 1, mid + 1, r, i, j);
        return (sum_l + sum_r) % MOD;
    }

    ll get_inv_sum(int p, int l, int r, int i, int j){
        if(l > j or r < i) return 0;
        if(i <= l and r <= j) return invsum[p] % MOD;
        int mid = (l + r)/2;
        ll sum_l = get_inv_sum(2*p, l, mid, i, j);
        ll sum_r = get_inv_sum(2*p + 1, mid + 1, r, i, j);
        return (sum_l + sum_r) % MOD;
    }

    ll hash(int l, int r){
        return get_sum(1, 0, sz-1, l-1, r-1);
    }

    ll invhash(int l, int r){
        return get_inv_sum(1, 0, sz-1, l-1, r-1);
    }
};

vector<seg_tree> songs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    pre();
    songs.pb(seg_tree("a"));
    for(int i = 1; i <= n; i++){
        string x;
        cin >> x;
        songs.pb(seg_tree(x));
    }
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        if(op == 1){
            int song, pos;
            char c;
            cin >> song >> pos >> c;
            songs[song].upd(pos, c);
        }
        if(op == 2){
            int u, v, lu, ru, lv, rv;
            ll ansu, ansv;
            cin >> u >> v >> lu >> ru >> lv >> rv;
            ansu = (songs[u].hash(lu, ru)*invpot[lu-1])%MOD;
            ansv = (songs[v].hash(lv, rv)*invpot[lv-1])%MOD;
            // db(ansu _ ansv);
            if(ansu == ansv) cout << "equal\n";
            else cout << "different\n";
    
        }
        if(op == 3){
            int u, v, lu, ru, lv, rv, du, dv, dx = 0;
            cin >> u >> v >> lu >> ru >> lv >> rv;
            du = (ru - lu + 1), dv = (rv - lv + 1);
            int half = (du + dv)/2;
            if((du + dv)%2) dx++;
            ll lhs, rhs;
            // db(du _ dv _ half);
            if(half == du or half == dv){
                lhs = (songs[u].hash(lu, lu + half - 1)*invpot[lu-1])%MOD;
                rhs = (songs[v].invhash(rv - half + 1, rv)*invpot[songs[v].sz-rv])%MOD;
            }
            else if(half < du){
                lhs = (songs[u].hash(lu, lu + half - 1)*invpot[lu - 1])%MOD;
                rhs = (songs[v].invhash(lv, rv)*invpot[songs[v].sz-rv])%MOD;
                rhs = (rhs + (((songs[u].invhash(lu + half + dx, ru)*(invpot[songs[u].sz-ru]))%MOD) * pot[dv]))%MOD;
            }
            else{
                lhs = (songs[u].hash(lu, ru)*invpot[lu-1])%MOD;
                rhs = (songs[v].invhash(rv - half + 1, rv)*invpot[songs[v].sz-rv])%MOD;
                lhs = (lhs + (((songs[v].hash(lv, rv - half - dx)*(invpot[lv - 1]))%MOD) * pot[du]))%MOD;
            }
            // db(lhs _ rhs);
            if(lhs == rhs) cout << "cool\n";
            else cout << "not so cool\n";
        }
    }
    return 0;
}