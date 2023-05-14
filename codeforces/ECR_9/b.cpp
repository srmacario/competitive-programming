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
const int N = 5e5+5;

ll a[N],psum[N],ssum[N];
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> s;
    for(int i=1;i<=n;i++){
        if(s[i-1] == 'A') psum[i] = psum[i-1] + a[i];
        else psum[i] = psum[i-1] - a[i];
    }
    for(int i=n;i>=1;i--){
        if(s[i-1] == 'A') ssum[i] = ssum[i+1] + a[i];
        else ssum[i] = ssum[i+1] - a[i];
    }
    ll smax = 0;
    ll l = 1, r = 0;
    for(int i=1;i<=n;i++){
        if(psum[i] >= smax){
            smax = psum[i];
            l = 1, r = i;
        }
    }
    for(int i=n;i>=1;i--){
        if(ssum[i] >= smax){
            smax = ssum[i];
            r = n, l = i;
        }
    }
    for(int i=l-1;i<=r-1;i++){
        if(s[i] == 'A') s[i] = 'B';
        else s[i] = 'A';
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i-1] == 'B') ans+=a[i];
    }
    cout << ans << "\n";
    return 0;
}