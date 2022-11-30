#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int n, m, a[N], to[N], pos[N], p[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <=m; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) p[i] = pos[i] = to[i] = i;
    for(int i = m; i > 0; i--) swap(to[a[i]], to[a[i] + 1]);
    for(int i = 1; i <= m; i++){
        swap(to[a[i]], to[a[i] + 1]);
        cout << to[pos[1]] << "\n";
        swap(p[a[i]], p[a[i] + 1]);
        swap(pos[p[a[i]]], pos[p[a[i] + 1]]);
    }
    return 0;
}