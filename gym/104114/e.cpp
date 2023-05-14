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

int n;
ll dp[8][N];
pll c[N];
set<pii> cant;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 63, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= 2 * n; i++){
        cin >> c[i].st;
        c[i].nd = i;
        if(i%2) cant.insert({i, i + 1});
        else cant.insert({i, i - 1});
    }
    sort(c + 1, c + 2 * n + 1);
    //001
    if(!cant.count({c[3].nd, c[2].nd})) dp[1][3] = (c[3].st - c[2].st);
    //010
    if(!cant.count({c[3].nd, c[1].nd})) dp[2][3] = (c[3].st - c[1].st);
    //100
    if(!cant.count({c[2].nd, c[1].nd})) dp[4][3] = (c[2].st - c[1].st);
    dp[7][3] = 0;
    for(int i = 4; i <= 2 * n; i++)
        for(int b = 0; b < 8; b++){
            //needs to match the first
            if(b & 1){
                if(!cant.count({c[i].nd, c[i - 3].nd})) dp[b >> 1][i] = min(dp[b >> 1][i], dp[b][i - 1] + c[i].st - c[i - 3].st);
                continue;
            }
            //match second
            if(b & 2){
                if(!cant.count({c[i].nd, c[i - 2].nd})) dp[(b ^ 2) >> 1][i] = min(dp[(b ^ 2) >> 1][i], dp[b][i - 1] + c[i].st - c[i - 2].st);
            }
            //match third
            if(b & 4){
                if(!cant.count({c[i].nd, c[i - 1].nd})) dp[(b ^ 4) >> 1][i] = min(dp[(b ^ 4) >> 1][i], dp[b][i - 1] + c[i].st - c[i - 1].st);
            }
            //not match
            dp[(b >> 1) | (1 << 2)][i] = min(dp[(b >> 1) | (1 << 2)][i], dp[b][i - 1]);
        }
    cout << dp[0][2 * n] << "\n";
    return 0;
}