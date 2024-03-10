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

int n, b[N];
ll ones[2][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int par = 0, count = 0;
    vector<pii> pos;
    for(int i = 1; i <= n; i++){
        ones[0][i] = ones[0][i - 1];
        ones[1][i] = ones[1][i - 1];
        count++;
        cin >> b[i];
        if(b[i]){
            par ^= b[i];
            ones[par][i] += count;
            pos.push_back({i, par});
            count = 0;
        }
    }
    ll ans = 0;
    for(auto p : pos){
        ans += ones[p.nd][p.st];
        ans += (ones[p.nd][p.st] - ones[p.nd][p.st - 1] - 1) * ones[p.nd ^ 1][p.st];
    }
    ans += count * ones[par][n];
    cout << ans << "\n";
    return 0;
}