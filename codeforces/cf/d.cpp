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
const int INF = 0x3f3f3f3f, MOD = 998244353 ;
const int N = 2e5+5;

vector<pair<int, map<int,int>>> adj[N];
map<int, int> mult[N];
int vis[N], t;
ll ans = 0;

int p[N];
vi primes;
void sieve(){
    for (ll i = 2; i < N; ++i) if (!p[i]) {
    for (ll j = i*i; j < N; j+=i) p[j] = 1;
        primes.pb(i);
    }
}

void dfs(int u){
    vis[u]++;
    for(auto v : adj[u]){
        if(!vis[v.st]){
            mult[v.st] = mult[u];
            for(auto x : v.nd) mult[v.st][x.st] += x.nd;
            dfs(v.st);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    cin >> t;
    while(t--){
        ans = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n - 1; i++){
            int u, v, a, b;
            cin >> u >> v >> a >> b;

            map<int, int> m;
            for(int j = 0; j < primes.size() and 1ll * primes[j] * primes[j] <= b; j++){
                while(!(b % primes[j])) b /= primes[j], m[primes[j]]++;
            }
            if(b > 1) m[b]++;
 
            for(int j = 0; j < primes.size() and 1ll * primes[j] * primes[j] <= a; j++){
                while(!(a % primes[j])) a /= primes[j], m[primes[j]]--;
            }
            if(a > 1) m[a]--;

            adj[u].pb({v, m});
            for(auto x : m) m[x.st] = -m[x.st];
            adj[v].pb({u, m});
        }
        map<int, int> mmc;
        dfs(1);
        for(int i = 1; i <= n; i++){
            for(auto x : mult[i]){
                if(x.nd < 0) mmc[x.st] = max(mmc[x.st], -x.nd);
            }
        }
        for(int i = 1; i <= n; i++){
            ll k = 1;
            for(auto x : mmc) mult[i][x.st] += x.nd;
            for(auto x : mult[i]) for(int j = 0; j < x.nd; j++) k = (k * x.st) % MOD;
            ans = (ans + k) % MOD;
            vis[i] = 0;
            mult[i].clear();
            adj[i].clear();
        }
        cout << ans << "\n";
    }
    return 0;
}