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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    set<int> keys;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++){
        cin >> b[i];
        keys.insert(b[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(keys.count(a[i])) ans++;
    }
    cout << ans << "\n";
    return 0;
}