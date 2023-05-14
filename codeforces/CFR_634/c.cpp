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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector <ll> freq;
        ll dif = 0, ans = 0;
        for(int i=0;i<=n;i++) freq.pb(0);
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            if(!freq[x]) dif++;
            freq[x]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i] == dif) ans = max(ans, dif - 1);
            else ans = max(ans,min(dif,freq[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}