#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x,v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef unsigned long long ll;
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

ll comb[55][55];

void pre(){
    for(int i=0;i<55;i++) comb[i][0] = 1;
    for(ll i=1;i<55;i++)
        for(ll j=1;j<=i;j++)
            comb[i][j] = (comb[i][j-1]*(i-j+1))/j;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    ll n,k,a,b;
    cin >> n >> k;
    vector<ll> box(n);
    for(int i=0;i<n;i++){
        cin >> box[i];
    }
    cin >> a >> b;
    ll ans = 0, rem = k;
    sort(box.begin(),box.end());
    for(int i=n-1;i>=0;i--){
        if(rem == 0) break;
        if(box[i] <= b){
            ans += comb[i][rem];
            b -= box[i];
            rem--;
        }
    }
    if(!rem) ans++;
    rem = k;
    for(int i=n-1;i>=0;i--){
        if(rem == 0) break;
        if(box[i] < a){
            ans -= comb[i][rem];
            a -= box[i];
            rem--;
        }
    }
    if(!rem) ans--;
    cout << ans << "\n";
    return 0;
}