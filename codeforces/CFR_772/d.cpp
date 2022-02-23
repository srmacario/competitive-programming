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
const int N = 2e5+5;
const ll M = 1e9 + 5;

ll f[N];
int cur = 0;
set<int> base;

bool dfs(int i){
    if(base.count(i)) return true;
    if(i == 1) return false;
    else if(!(i % 4)) return dfs(i / 4);
    else if(!((i - 1) % 2)) return dfs((i - 1) / 2);
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //pre
    f[0] = 0, f[1] = 1;
    for(int i = 2; i < N; i++) f[i] = (f[i - 1] + f[i - 2] + 1)%MOD;

    //input
    int n, p;
    cin >> n >> p;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        bool ok = dfs(a[i]);
        if(!ok) base.insert(a[i]);
        //cout << "\n";
    }
    ll ans = 0;
    for(auto x : base){
        //db(x);
        int pot = 0;
        for(ll i = 30; i >= 0; i--){
            if((1ll << i) > x) pot = i;
        }
        if(p - pot + 1 < 0) continue;
        ans = (ans + f[p - pot + 1]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}