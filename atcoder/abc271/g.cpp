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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 1e5+5;

ll n, x[2], inv;
ll q[25];
string t;

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

vector <vector <ll> > A, AN, B, C, D, p;

void mul () {
    // Resizing and clearing D
    D.resize(B.size());
    for (auto& row : D) row.resize(C[0].size());
    for (auto& row : D)
        for (auto& elem : row)
            elem = 0;

    // Multiplying B*C = D
    for (int i = 0; i < D.size(); i++) {
        for (int j = 0; j < D[i].size(); j++) {
            for (int k = 0; k < B[0].size(); k++) {
                D[i][j] += (B[i][k]*C[k][j])%MOD;
                D[i][j] %= MOD;
            }
        }
    }
}

// Fast matrix exponential to get A^n
void getAN (ll n) {
    AN.clear();
    AN.resize(A.size());
    for (auto& row : AN) row.resize(A[0].size());

    for (int i = 0; i < AN.size(); i++)
        AN[i][i] = 1;

    //exponentiation
    ll e = n;
    while (e) {
        if (e&1) {
            B = AN;
            C = A;
            mul();
            AN = D;
        }
        B = A;
        C = A;
        mul();
        A = D;
        e >>= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x[0] >> x[1] >> t;
    //base recurrence cases
    inv = fexp(100, MOD - 2);
    p.resize(1);
    p[0].resize(24);
    q[0] = 1;
    //chance of no wins during a cycle (prefix sum) or chance of someone winning
    for(int i = 0; i < 24; i++){
        if(t[i] == 'T'){
            q[i + 1] = ((100 - x[0]) * inv) % MOD;
            p[0][i] = (((q[i] * x[0])%MOD) * inv) % MOD;
        }
        else{
            q[i + 1] = ((100 - x[1]) * inv) % MOD;
            p[0][i] = (((q[i] * x[1])%MOD) * inv) % MOD;
        }
        q[i + 1] = (q[i + 1] * q[i]) % MOD;
    }
    //creating transition matrix
    A.resize(24);
    for(int i = 0; i < 24; i++){
        A[i].resize(24);
        for(int j = 0; j < 24; j++){
            ll probn = 1;
            ll prob = 1;
            if(t[j] == 'T') prob = (x[0] * inv) % MOD;
            else prob = (x[1] * inv) % MOD;
            db(prob);
            if(j > i){
                probn = (q[j] * fexp(q[i + 1], MOD - 2)) % MOD;
            }
            if(j <= i){
                probn = (((q[j] * q[24]) % MOD) * fexp(q[i + 1], MOD - 2)) % MOD;
            }
            A[i][j] = (((prob * probn) % MOD) * fexp(1 - q[24] + MOD, MOD - 2)) % MOD;
        }
    }
    //exponentiate matrix
    getAN(n - 1);
    //multiply AN * base
    C = AN;
    B = p;
    mul();
    ll ans = 0;
    for(int i = 0; i < 24; i++){
        if(t[i] == 'A') ans = (ans + ((fexp(1 - q[24] + MOD, MOD - 2) * D[0][i]) % MOD)) % MOD;
    }
    cout << ans << "\n";
    return 0;
}