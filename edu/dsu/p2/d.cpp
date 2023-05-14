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

int n, m, par[N], rk[N];

int find(int a){
    if(a == par[a]){
        rk[a] = 0;
        return a;
    }
    int up = find(par[a]);
    rk[a] += rk[par[a]];
    par[a] = up;
    return par[a] = up;
}

void unite(int a, int b){
    par[a] = b;
    rk[a]++;
}

int main(){
    scanf("%d %d", &n, &m);    
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 0; i < m; i++){
        int op, a, b;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d%d", &a, &b);
            unite(a, b);
        }
        if(op == 2){
            scanf("%d", &a);
            find(a);
            printf("%d\n", rk[a]);
        }
    }    
    return 0;
}