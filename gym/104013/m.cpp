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
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int mn = 0, mx = INF;
    mn = p[1];
    for(int i = 2; i <= n; i++){
        mn = max(mn, p[i] - p[i - 1]);
        mx = min(mx, p[i] - p[i - 2]);
    }
    if(mn >= mx) mn = 0;
    cout << mn << "\n";
    return 0;
}