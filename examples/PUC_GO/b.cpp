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

ll a[N], ps[N], ans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ps[i] = a[i] + ps[i-1];
    }
    for(int i=n+1;i<=2*n;i++){
        a[i] = a[i-n];
        ps[i] = a[i] + ps[i-1];
    }
    for(int i=1;i<=n;i++){
        ans[i] = (k/n)*(ps[n]) + ps[n+i] - ps[n+i - k%n];
        cout << ans[i];
        cout << (i == n ? "\n" : " ");
    }
    return 0;
}