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

int n, k;
ll v[N];

int binS(int l, int r, ll targ){
    while(l < r){
        int m = (r+l)/2;
        if(v[m] < targ) l = m + 1;
        else r = m;
    }
    return l;
}

int main(){
    scanf("%d%d", &n, &k);
    v[0] = -LINF;
    v[n+1] = LINF;
    for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);
    for(int i = 0; i < k; i++){
        ll x;
        scanf("%lld", &x);
        printf("%d\n", binS(0, n + 1, x));
    }
    return 0;
}