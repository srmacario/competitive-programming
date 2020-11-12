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
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        k = ((n)*(n-1))/2 - k + 1;
        ll l = 0, r = 0, sum  = 0;
        for(ll i=1;i<=n;i++){
            sum = n*(i) - (i*(i+1))/2;
            if(sum < k) l = i;
            else{
                sum = n*(i-1) - ((i-1)*(i))/2;
                break;
            }
        }
        r = l + (k-sum);
        for(ll i=0;i<l;i++) cout << "a";
        cout << "b";
        for(ll i=l+1;i<r;i++) cout << "a";
        cout << "b";
        for(ll i=r+1;i<n;i++) cout << "a";
        cout << "\n";
    }
    return 0;
}