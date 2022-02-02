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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 5e3+5;

ll dp[30][N], freq[30], fat[N], invfat[N];

ll comb(int n, int k){
    return (fat[n] * ((invfat[n - k] * invfat[k]) % MOD)) % MOD;
}

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e & 1) ans = (ans * b) % MOD;
        b = (b * b)%MOD;
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    fat[0] = 1;
    invfat[0] = 1;
    for(int i = 1; i <= n; i++){
        fat[i] = (fat[i - 1] * i) % MOD;
        invfat[i] = fexp(fat[i], MOD - 2);
        //db(fat[i]);
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) freq[s[i - 1] - 'a' + 1]++;
    for(int i = 1; i <= 26; i++){
        for(ll j = 0; j <= n; j++){
            for(int k = 0; k <= min(j, freq[i]); k++){
                dp[i][j] = (dp[i][j] + ((dp[i - 1][j - k] * comb(j, k))%MOD)) % MOD;
            }
        }
    }
    ll ans = 0;
    for(int j = 1; j <= n; j++) ans = (ans + dp[26][j]) % MOD;
    cout << ans << "\n";
    return 0;
}