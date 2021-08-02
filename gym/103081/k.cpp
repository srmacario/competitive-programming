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
const int B = 31;

string s, ans;
int n;
vector<ll> h, p, invp;

ll fexp(ll b, ll e, ll m = MOD){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans*b)%m;
        b = (b*b)%m;
        e >>=1;
    }
    return ans;
}

bool check(int sz){
    map <ll, int> m;
    for(int i = 0; i + sz - 1 < n; i++){
        ll cur_h = (((h[i + sz] - h[i] + MOD))*invp[i])%MOD;
        // db(sz _ cur_h);
        m[cur_h]++;
        // db(m[cur_h]);
    }
    // for(int i = 0; i + sz - 1 < n; i++){
    //     ll cur_h = (((h[i + sz] - h[i] + MOD))*invp[i])%MOD;
    //     cout << m[cur_h] << " ";
    // }
    // cout << "\n";
    for(int i = 0; i + sz - 1 < n; i++){
        ll cur_h = (((h[i + sz] - h[i] + MOD))*invp[i])%MOD;
        // db(i _ m[cur_h]);

        if(m[cur_h] == 1) return true;
    }
    return false;
}

string binS(){
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r)/2;
        // db(mid _ check(mid));
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    // db(l);
    map <ll, int> m;
    for(int i = 0; i + l - 1 < n; i++){
        ll cur_h = (((h[i + l] - h[i] + MOD))*invp[i])%MOD;
        m[cur_h]++;
    }
    for(int i = 0; i + l - 1 < n; i++){
        ll cur_h = (((h[i + l] - h[i] + MOD))*invp[i])%MOD;
        if(m[cur_h] == 1){
            string resp = s.substr(i, l);
            return resp;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();
    h.resize(n+5), p.resize(n + 5), invp.resize(n + 5);
    h[0] = 0;
    invp[0] = invp[1] = p[0] = p[1] = 1;
    for(int i = 0; i < n; i++){
        p[i+1] = (p[i] * B) % MOD;
        invp[i+1] = fexp(p[i+1], MOD - 2, MOD);
        h[i+1] = (h[i] + ((s[i] - 'a' + 1) * p[i])%MOD)%MOD;
    }
    cout << binS() << "\n";
    return 0;
}