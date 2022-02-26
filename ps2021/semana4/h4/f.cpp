#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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
const int M = 2e3+5;

ll w[M],v[M],dp[M][M],n,s;

void call_dp(){
    //percorrendo os n elementos candidatos a ser colocados na bolsa
    for(int i=0;i<n;i++){
        //para cada tamanho de bolsa, verificando a condição da dp
        for(int j=0;j<=s;j++){
            if(i == 0) {if(w[i] <= j) dp[i][j] = v[i];}
            else{
                //carrega o resultado da dp usando os i-1 primeiros elementos
                dp[i][j] = dp[i-1][j];
                // se o elemento couber na bolsa, verifica a condição da dp
                if(w[i] <= j) dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> n;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }
    call_dp();
    ll ans = 0;
    for(int i=0;i<=s;i++){
        ans = max({ans,dp[n-1][i]});
    }
    cout << ans << "\n";
    return 0;
}