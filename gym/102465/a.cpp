#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x,v) memset((x),(v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " << 

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef pair <ll,ll> pll;
typedef pair <ll,pll> plll;
typedef vector<int> vi;
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

ll num[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, x;
    cin >> n >> k;
    ll ans = 0, resp = 0;
    for(ll i=0;i<k;i++){
        cin >> x;
        for(ll j=x;j<=n;j+=x){
            num[j] ^= 1;
            if(num[j]) ans++;
            else ans--;
        }
        resp = max(resp,ans);
    }
    cout << resp << "\n";
    return 0;
}