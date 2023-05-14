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
const int N = 6e5+5;

int par[N], sz[N], mx[N];

int find(int a){ return par[a] == a ? a : par[a] = find(par[a]);}

void unite(int a, int b){
    if((a = find(a)) == (b = find(b))) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    mx[a] = max(mx[a], mx[b]);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < N; i++) par[i] = mx[i] = i, sz[i] = 1;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        x = mx[find(x-1)];
        printf("%d ", (x%n) + 1);
        if(x < n){
            unite(x, x+1);
            unite(x+n, x+n+1);
        }
        else{
            unite(x, x+1);
            unite(x-n, x-n+1);
        }
    }
    printf("\n");
    return 0;
}