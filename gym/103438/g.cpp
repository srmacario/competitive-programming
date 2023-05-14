#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define cl(x, v) memset((x), (v), sizeof(x))
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;

bool cmp(pll a, pll b){
    return (a.st + a.nd) < (b.st + b.nd);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll ans = 0;
    cin >> n;
    vector<pll> a(2 * n);
    for(int i = 0; i < 2*n; i++){
        cin >> a[i].st >> a[i].nd;
        if(a[i].st > a[i].nd) swap(a[i].st, a[i].nd);
    }
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++){
        ans -= (a[i].st);
    }
    for(int i = n; i < 2 * n; i++){
        ans += (a[i].nd);
    }
    cout << ans << "\n";
    return 0;
}