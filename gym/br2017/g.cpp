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

int n, f[N], adj[N][2];
ll saida[N][2], ans[N][2];

void pre(int s){
    if(!s){
        // db(s _ saida[s][0] _ saida[0][1]);
        return;
    }
    ll l[2] = {0}, r[2] = {0};
    ll wl[2] = {0}, wr[2] = {0};
    pre(adj[s][0]);
    l[0] = saida[adj[s][0]][0];
    l[1] = saida[adj[s][0]][1];
    wl[0] = ans[adj[s][0]][0];
    wl[1] = ans[adj[s][0]][1];

    pre(adj[s][1]);
    r[0] = saida[adj[s][1]][0];
    r[1] = saida[adj[s][1]][1];
    wr[0] = ans[adj[s][1]][0];
    wr[1] = ans[adj[s][1]][1];

    saida[s][0] = (l[1]*r[1])%MOD;
    saida[s][1] = (l[0]*r[0]%MOD + l[0]*r[1]%MOD + l[1]*r[0]%MOD + wl[1]*r[0]%MOD + l[0]*wr[1]%MOD + wl[0]*r[0]%MOD + l[0]*wr[0]%MOD + wl[0]*wr[1]%MOD + wl[1]*wr[0]%MOD)%MOD;
    ans[s][0] = (l[1]*wr[1]%MOD + wl[1]*r[1]%MOD + wl[1]*wr[1]%MOD)% MOD;
    ans[s][1] = (wl[0]*wr[0]%MOD + wl[0]*r[1]%MOD + l[1]*wr[0]%MOD) %MOD;
    if(f[s] >= 0){
        ans[s][f[s]] = (ans[s][f[s]] + (saida[s][f[s]^1]))%MOD;
        saida[s][f[s]] = (saida[s][f[s]] + (ans[s][f[s]^1]))%MOD;
        
        saida[s][f[s]^1] = 0;
        ans[s][f[s]^1] = 0;
    }
}

int main(){
    saida[0][0] = saida[0][1] = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d%d%d", &adj[i][0], &adj[i][1], &f[i]);
    pre(1);
    printf("%lld\n", (ans[1][0] + ans[1][1])%MOD);
    return 0;
}