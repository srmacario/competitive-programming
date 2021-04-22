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
const int N = 5e3+5;

ll a[N], vis[N], n;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            vis[i] += vis[i-1];
            ll cur = max(1ll, a[i] - vis[i]);
            ans = ans + cur - 1;
            ll dif = max(0ll, vis[i] - a[i] + 1);
            vis[i+1] += dif;
            vis[i + 2] += 1 - dif;
            vis[min(i + a[i] + 1, 1ll*(n+2))] += -1;
            //for(ll j = min(n,i+a[i]); j >= i+2; j--) vis[j]++;
        }
        printf("%lld\n", ans);
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
    }
    return 0;
}