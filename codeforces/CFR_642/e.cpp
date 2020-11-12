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
const int N = 1e5+5;

ll s_sum;

ll dp(string t){
    ll n = t.size();
    //pressum of ones in t
    ll t_sum = count(t.begin(), t.end(), '1');
    //worst case everyone becomes 0
    ll ans = t_sum;
    vector<ll> memo(n);
    //pressum of ones in t until position i of t
    ll cur1 = 0;
    for(int i=0;i<n;i++){
        int now = (t[i] == '1');
        cur1 += now;
        //minimizing between: solving for i-1 and zeroing until i-1
        if(i > 0) memo[i] = min(memo[i-1], cur1 - now);
        //cost for transforming position i to 1
        memo[i] += 1 - now;
        //minimizing between: ans now and solving for position i and zeroing after i
        ans = min(ans,memo[i] + t_sum - cur1);
    }
    //best answer + cost to change everyone who is not in t to 0
    return ans + s_sum - t_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        //declaring and reading
        ll n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector <string> tmp(k);
        //pressum of ones in s
        s_sum = count(s.begin(),s.end(),'1');
        //generating string with the positions mod k for each i
        for(int i=0;i<n;i++){
            tmp[i%k] += s[i];
        }
        ll ans = LINF;
        //for each string solve
        for(int i=0;i<tmp.size();i++){
            ans = min(ans, dp(tmp[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}