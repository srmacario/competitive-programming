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
const int N = 1e4+5, T = 125;

int d[N], c[N], n;
double dp[N][T][7];

int id(int p){
    if(p == 1 or p > 6) return 1;
    return p;
}

double calc(int i, int t, int p){
    if(i == n) return 0;
    if(dp[i][t][id(p)]) return dp[i][t][id(p)];
    dp[i][t][id(p)] = c[i];
    if(p == 2) dp[i][t][id(p)] *= 0.5;
    if(p <= 6 and p > 2) dp[i][t][id(p)] *= 0.25;
    double fwd, wait;
    wait = calc(i+1, 0, 1);
    if(t + d[i] < 120) fwd = calc(i+1, t + d[i], p + 1);
    else fwd = calc(i+1, 0, 1);
    // db(fwd _ wait);
    return dp[i][t][id(p)] += min(wait, fwd);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d %d", &d[i], &c[i]);
    printf("%0.2lf\n", calc(0,0,1));
    return 0;
}