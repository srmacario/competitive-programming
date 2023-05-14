#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector<int> vi;
typedef vector <vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 5e3 + 5;

ll n, R, C, k, f[N], ans, g[N];

ll fexp(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> R >> C >> k;
    for(int i = 0; i < N; i++)
        g[i] = (fexp(i + 1, n) - fexp(i, n) + MOD) % MOD;
    for(int b = 1; b <= R; b++)
        for(int l = 0; l + b <= R; l++)
            f[b] = (f[b] + g[l] * fexp(R - l - b + 1, n)) % MOD;
    for(int a = 1; a <= C; a++){
        if((k + a - 1) / a >= N)
            continue; 
        for(int l = 0; l + a <= C; l++)
            ans = (ans + g[l] * g[C - l - a] % MOD * f[(k + a - 1) / a]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}