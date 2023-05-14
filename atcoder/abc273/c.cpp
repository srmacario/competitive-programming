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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ord(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ord[i] = a[i];
    }
    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());
    for(int i = 0; i < n; i++){
        int cnt = (ord.end() - upper_bound(ord.begin(), ord.end(), a[i]));
        ans[cnt]++;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
    return 0;
}