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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, n;
    string s;
    cin >> a >> b >> s;
    n = (int) s.size();
    int l = n, r = -1;
    vector<ll> qw(n + 1), qb(n + 1);
    for(int i = 0; i < n; i++){
        if(s[i] == 'W' and l == n) l = i;
        qw[i + 1] = qw[i];
        qb[i + 1] = qb[i];
        if(s[i] == 'W') qw[i + 1]++;
        else qb[i + 1]++;
    }
    for(int i = n - 1; i >= 0; i--) if(s[i] == 'B' and r == -1) r = i;
    ll ans = 0;
    while(l < r){
        if(a <= (a-b)*(qb[r + 1] - qb[l] + qw[r + 1] - qw[l] - 1)) ans += a;
        else ans += (a-b)*(qb[r + 1] - qb[l] + qw[r + 1] - qw[l] - 1);
        r--, l++;
        while(l < r and s[r] != 'B') r--;
        while(l < r and s[l] != 'W') l++;
    }
    cout << ans << "\n";
    return 0;
}