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

const int N = 1e2+5; // Maximum number of items
const int L = 1e4+5; // Maximum value for 'limit'

int ans, n, k, limit, w[N], v[N], c[N], p[N];
int dp[N][L], used[N][L], memo[L];

int main () {
    scanf("%d%d%d", &n, &k, &limit);

    //members
    for (int i = 0; i < n; i++)
        scanf("%d%d", &c[i], &p[i]);

    //itens
    for (int i = 0; i < k; i++)
        scanf("%d%d", &w[i], &v[i]);

    for(int l = 0; l < n; l++){
        for (int i = 0; i < k; i++){ // Adding item by item to our dp
    //      If there's an item limitation, create a DECREASING j loop! Like this:
            for (int j = c[l]; j >= w[i]; j--){
                if(v[i] + dp[l][j - w[i]] > dp[l][j]){
                    used[l][j] = used[l][j - w[i]] + w[i];
                    dp[l][j] = v[i] + dp[l][j - w[i]];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
            for (int j = L - 1; j >= p[i]; j--)
                memo[j] = max(memo[j], dp[i][c[i]] + memo[j - p[i]]);

    cout << memo[limit] << "\n";
}