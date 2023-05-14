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
    int n;
    cin >> n;
    vi a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    a[0] = a.back();
    int ans = 0;
    for(int i = 1; i <= n; i+=2){
        int dif = abs(a[i] - a[i-1]);
        ans += min(dif, 24 - dif);
    }
    int tmp = ans;
    ans = 0;
    for(int i = 2; i <= n; i+=2){
        int dif = abs(a[i] - a[i-1]);
        ans += min(dif, 24 - dif);
    }
    cout << min(tmp,ans) << "\n"; 
    return 0;
}