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

int n, a[N], dp[N], nxt[N], lst[N];

int calc(int pos){
    if(pos >= n) return 0;

    if(dp[pos] != -1) return dp[pos];
    
    dp[pos] = calc(pos + 1);
    if(~nxt[pos]) dp[pos] = min(dp[pos], calc(nxt[pos]));
    return ++dp[pos];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(lst, -1, sizeof(lst));
    memset(dp, -1, sizeof(dp));
    memset(nxt, -1, sizeof(nxt));
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(lst[a[i]] != -1) nxt[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
    cout << calc(0) - 1 << "\n";
    return 0;
}