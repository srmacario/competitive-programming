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
const int N = 5e5+5;

int n, k, m;
vi pipe[N];

int main(){
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++) pipe[i].pb(j);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
    }
    vi queries(n*k), ans(n*k);
    for(int i = 0; i < n*k; i++) scanf("%d", &queries[i]);
    for(int i = n*k - 1; i >= 0; i--){
        ans[i] = pipe[queries[i]].back();
        pipe[queries[i]].pop_back();
    }
    for(auto s : ans) printf("%d ", s);
    printf("\n");
    return 0;
}