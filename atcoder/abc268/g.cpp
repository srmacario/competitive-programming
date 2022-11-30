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
const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 5e5+5;

ll fexp(ll b, ll e){
    ll ans = 1;
    while(e){
        if(e&1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}

// Trie <O(|S|), O(|S|)>
int trie[N][26], cnt[N], trien = 1, end_node[N], n;
ll ans[N], inv;
bool is_end[N];

int add(int u, char c){
  c -= 'a';
  if (!trie[u][c]) trie[u][c] = ++trien;
  cnt[trie[u][c]]++;
  return trie[u][c];
}

void dfs(int u, int pre){
    if(is_end[u]){
        ans[end_node[u]] = (inv * (pre + n - cnt[u] + 1)) % MOD;
    }
    for(int c = 0; c < 26; c++){
        if(!trie[u][c]) continue;
        dfs(trie[u][c], pre + is_end[trie[u][c]]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inv = fexp(2, MOD - 2);
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int u = 1;
        for(char c : s) u = add(u, c);
        is_end[u] = true;
        end_node[u] = i;
    }
    dfs(1, 0);
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
    return 0;
}