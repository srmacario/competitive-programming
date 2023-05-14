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

int n, m, k;
vector<pii> adj[N];
vector<piii> edges;
vector<int> seq;
ll dp[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    edges.push_back({0, {0, 0}});
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
        adj[a].push_back({b, c});
    }
    seq.resize(k);
    for(int i = 0; i < k; i++) cin >> seq[i];
    memset(dp, 63, sizeof(dp));
    dp[1] = 0;
    for(int i = 0; i < k; i++){
        if(dp[edges[seq[i]].nd.st] == LINF) continue;
        dp[edges[seq[i]].nd.nd] = min(dp[edges[seq[i]].nd.nd], dp[edges[seq[i]].nd.st] + edges[seq[i]].st);
    }
    cout << (dp[n] == LINF ? -1 : dp[n]) << "\n";
    return 0;
}