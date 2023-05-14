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

int n, k, a[N], b[N], p[N];

bool cmp(int i, int j){
    if(a[i] + b[i] == a[j] + b[j]) return a[i] < a[j];
    return a[i] + b[i] < a[j] + b[j];
}

bool calc(int i, int k){
    if(i < 1) return false;
    if(i == 1) return a[p[i]] >= k;
    if(a[p[i]] + b[p[i]] >= k){
        if(a[p[i - 1]] + b[p[i - 1]] >= k) return true;
        if(a[p[i]] >= k) return true;
        return calc(i - 1, k - b[p[i]]);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int max_a = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            p[i] = i;
            max_a = max(a[i], max_a);
        }
        if(k > a[0] + b[0]){
            cout << "NO\n";
            continue;
        }
        if(k <= max_a){
            cout << "YES\n";
            continue;
        }
        sort(p + 1, p + n, cmp);
        bool ok = calc(n - 1, k - b[0]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}