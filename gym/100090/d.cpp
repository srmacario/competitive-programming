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
const int N = 1e6+5;

int k, dp[N];
vi divs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;

    for(int i = 1; i*i <= k; i++){
        if(!(k%i)){
            divs.pb(i);
            if(i != k/i) divs.pb(k/i);
        }
    }

    sort(divs.begin(), divs.end());

    dp[1] = 1;
    for(int i = 0; i < divs.size(); i++){
        for(int j = 0; j < i; j++){
            if(!(divs[i]%divs[j])) dp[divs[i]] += dp[divs[j]];
        }
    }
    cout << dp[k] << "\n";
    
    return 0;
}