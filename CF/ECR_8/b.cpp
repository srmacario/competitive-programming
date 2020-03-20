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
    string s;
    ll ans = 0;
    cin >> s;
    ll n = s.size();
    for(ll l = 0;l<n-1;l++){
        ll num = (s[l] - '0')*10 + (s[l+1] - '0');
        if(!(num%4)) ans += l+1;
    }
    for(ll l = 0;l<n;l++){
        ll num = (s[l] - '0');
        if(!(num%4)) ans += 1;
    }
    cout << ans << "\n";
    return 0;
}