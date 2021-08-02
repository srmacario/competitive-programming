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

int t, s, n, a[N], cur[2];

int main(){
    scanf("%d%d%d", &t, &s, &n);
    cur[1] = s;
    int bit = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        cur[bit] = max(cur[bit] - (a[i] - a[i-1]), 0);
        cur[bit^1] = s - cur[bit];
        bit ^= 1;
    }
    cur[bit] = max(cur[bit] - (t-a[n]), 0);
    printf("%d\n", cur[bit]);
    return 0;
}