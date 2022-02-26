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

int a[N];

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < q; i++){
        int x;
        scanf("%d", &x);
        auto ans = lower_bound(a, a + n, x);
        if(*ans != x) printf("-1\n");
        else printf("%d\n", (int)(ans - a));
    }
    return 0;
}