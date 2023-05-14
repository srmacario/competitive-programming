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
    int t;
    cin >> t;
    ll f[50];
    f[0] = f[1] = 1;
    for(int i = 2; i <= 44; i++) f[i] = f[i - 1] + f[i - 2];
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;
        x--, y--;
        vector<ll> s[2];
        for(int i = 1; i <= n; i++) s[i%2].push_back(f[i]);
        reverse(s[0].begin(), s[0].end());
        reverse(s[1].begin(), s[1].end());
        if(!(n % 2)) swap(x, y);
        bool ok = true;
        for(auto k : s[0]){
            if(x >= k) x -= k;
        }
        if(x) ok = false;
        for(auto k : s[1]){
            if(y >= k) y -= k;
        }
        if(y) ok = false;
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}