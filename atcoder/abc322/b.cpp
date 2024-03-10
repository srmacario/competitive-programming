#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
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

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int ans = 3, j = 0;
    for(int i = 0; i < m and j < n; i++){
        if(t[i] != s[j]) break;
        j++;
    }
    if(j == n) ans = 1;
    j = n - 1;
    for(int i = m - 1; i >= 0 and j >= 0; i--){
        if(t[i] != s[j]) break;
        j--;
    }
    if(j < 0){
        if(ans == 1) ans = 0;
        else ans = 2;
    }
    cout << ans << "\n";
    return 0;
}