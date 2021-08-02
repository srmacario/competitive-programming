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
const int N = 1e6+10; // Upper limit to n

int n, k, nxt[N], dp[N], vis[N], pnt[N], cnt;
ll sum[N];

int cmp[N];
vi pr;

void primes() {
    for (ll i = 2; i < N; i++) if (!cmp[i]) {
        for (ll j = i*i; j < N; j += i) cmp[j] = 1;
        pr.pb(i);
    }
}

int fact(int x){
    if(x == 1) return 1;
    vi pot;
    for(int i = 0; pr[i]*pr[i] <= x; i++){
        if(x % pr[i] == 0) pot.pb(0);
        while(x % pr[i] == 0){
            pot[pot.size()-1]++;
            x /= pr[i];
        }
    }
    if(x > 1) pot.pb(1);
    int mult = 1;
    for(auto p : pot) mult *= (p + 1);
    return mult;
}

void dfs(int s){
    vis[s] = 1;
    if(!vis[nxt[s]]){
        dfs(nxt[s]);
    }
    dp[s] = dp[nxt[s]] + 1;
    sum[s] = sum[nxt[s]] + s;
}

void print(int s){
    if(cnt == k) return;
    printf("%d ", s);
    cnt++;
    pnt[s] = 1;
    if(!pnt[nxt[s]]) print(nxt[s]);
}

int main(){
    primes();
    scanf("%d%d", &n, &k);
    nxt[0] = 0;
    for(int i = 1; i <= n; i++){
        int f = (i + fact(i)) % n;
        nxt[i] = f;
    }
    for(int i = 1; i <= n; i++){
        if(!dp[i]){
            dfs(i);
        }
        if(dp[i] >= k){
            print(i);
            printf("\n");
            return 0;
        }
    }
    printf("\n");
    return 0;
}