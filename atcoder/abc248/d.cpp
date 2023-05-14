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

int n, q, a[N];
vector<int> num[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        num[a[i]].push_back(i);
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        cout << upper_bound(num[x].begin(), num[x].end(), r) - lower_bound(num[x].begin(), num[x].end(), l) << "\n";
    }
    return 0; 
}