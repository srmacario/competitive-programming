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
const int N = 205, M = (1 << 16) + 5;

vector<int> dig;
int D, k;
int dp[M][N];
int pot[N];

void recover(int mask, int mod){
    if(!mask) return;
    int pos = __builtin_popcount(mask);
    int new_mod =  (mod - (dig[dp[mask][mod]] * pot[pos - 1]) % k + k) % k;
    int new_mask = mask ^ (1 << dp[mask][mod]);
 
    cout << char('0' + dig[dp[mask][mod]]);
    recover(new_mask, new_mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> k;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    dig.resize(D);
    for(int i = 0; i < D; i++) cin >> dig[i];
    pot[0] = 1 % k;
    for(int i = 1; i <= D; i++) pot[i] = (pot[i - 1] * 10) % k;
    sort(dig.begin(), dig.end());

    for(int mask = 0; mask < (1 << D); mask++){
        int pos = __builtin_popcount(mask);
        for(int mod = 0; mod < k; mod++){
            if(dp[mask][mod] != -1){
                for(int b = D - 1; b >= 0; b--){
                    if(!(mask & (1 << b))){
                        int new_mask = mask | (1 << b);
                        int new_mod = (mod + (dig[b] * pot[pos]) % k) % k;
                        dp[new_mask][new_mod] = max(dp[new_mask][new_mod], b);
                    }
                }
            }
        }
    }
    for(int i = k - 1; i >= 0; i--){
        if(dp[(1 << D) - 1][i] >= 0){
            recover((1 << D) - 1, i);
            cout << "\n";
            break;
        }
    }
    return 0;
}

/*
    dp[mask][resto]
    mask: cara da posicao i no vetor foi usado

    new_mod + dig * pot = mod % k
*/