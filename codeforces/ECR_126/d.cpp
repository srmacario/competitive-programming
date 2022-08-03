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
    int k, n;
    cin >> n >> k;
    vector<ll> b(n + 5), ps(n + 5), idx(n + 5), qtd(n + 5);
    for(int i = 1; i <= n; i++) cin >> b[i];
    ll ans = 0;
    for(int i = n; i >= k; i--){
        ps[i] += ps[i + 1];
        idx[i] += idx[i + 1];
        qtd[i] += qtd[i + 1];
        ll dif = b[i] - (ps[i] - (idx[i] - qtd[i]*i));
        //x * k >= dif -> x >= dif/k;
        if(dif > 0){
            ll x = (dif - 1)/k + 1;
            ans += x;
            idx[i] += x * i, idx[i - k] -= x*i;
            qtd[i] += x, qtd[i - k] -= x;
            ps[i] += x * k, ps[i - k] -= x * k;
        }
    }
    for(int i = k - 1; i >= 1; i--){
        ps[i] += ps[i + 1];
        idx[i] += idx[i + 1];
        qtd[i] += qtd[i + 1];
        ll dif = b[i] - (ps[i] - (idx[i] - qtd[i]*i));
        //x * k >= dif -> x >= dif/k;
        if(dif > 0){
            ll x = (dif - 1)/i + 1;
            ans += x;
            idx[i] += x * i;
            qtd[i] += x;
            ps[i] += x * i;
        }
    }
    cout << ans << "\n";
    return 0;
}