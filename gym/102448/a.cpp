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
const int N = 5e5+5;
const int B = 31;

ll fexp (ll b, ll e, ll m = MOD) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (ans*b) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    string s;
    cin >> n >> m >> s;
    vector <ll> hash (n+5), invhash(n+5), p(n+5), invp(n+5);
    hash[0] = invhash[0] = 0;
    invp[0] = invp[1] = p[0] = p[1] = 1;
    for(int i=1;i<=n;i++){
        if(i != 1){
            //ṕrecompute p^i and inv(p^1)
            p[i] = (p[i-1] * B) % MOD;
            invp[i] = fexp(p[i],MOD - 2, MOD);
        }
        //calculate hash as a prefix sum
        hash[i] = (hash[i-1] + ((s[i-1] - 'a' + 1) * p[i])%MOD)  % MOD;
    }
    for(int i=n;i>=1;i--){
        //calculate hash from inverse string
        invhash[n-i+1] = (invhash[n - i] + ((s[i-1] - 'a' + 1) * p[n-i+1])%MOD) % MOD;
    }
    for(int i=1;i<=n-m+1;i++){
        //index [l1,r1] from normal string and [l2,r2] from reverse string, if both are equal its palindrome
        //pay attention to odd m
        ll l1 = i, r1 = i + m/2 - 1, r2 = n - r1 - m%2, l2 = r2 - m/2 + 1;
        //using the prefix sum already calculated, we can find hash[l1,r1] and hash[l2,r2]
        ll h1 = (((hash[r1] - hash[l1 - 1] + MOD) % MOD) * invp[l1]) % MOD;
        ll h2 = (((invhash[r2] - invhash[l2 - 1] + MOD) % MOD) * invp[l2]) % MOD;
        if(h1 == h2){
            cout << "Accept\n";
            return 0;
        }
    }
    cout << "Reject\n";
    return 0;
}