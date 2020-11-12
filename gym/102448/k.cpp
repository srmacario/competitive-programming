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
const int N = 1e5+5;

vector<vector<ll>> ban, memo;
int n,h;

ll dp(int pos, int al){
    //db(pos), db(al);
    if(pos < 0 or pos >= n or al < 0 or al >= h) return 0;
    if(memo[pos][al] != -1) return memo[pos][al];
    ll l = dp(pos-1,al-1) + ban[pos][al], r = dp(pos + 1, al-1) + ban[pos][al], m = dp(pos,al-1) + ban[pos][al];
    //db(l), db(r), db(m);
    return memo[pos][al] = max({l,m,r});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> h;
    ban.resize(n);
    memo.resize(n);
    for(int i=0;i<n;i++){
        ban[i].resize(h);
        memo[i].resize(h);
        for(int j=0;j<h;j++){
            cin >> ban[i][j];
            memo[i][j] = -1;
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<h;j++) cout << memo[i][j] << " ";
        cout << "\n";
    }*/
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp(i,h-1));
    }
    cout << ans << "\n";
    return 0;
}