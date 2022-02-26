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
const int N = 2e5+5;

int a[N], has[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r+1]--;
    }
    for(int i = 1; i < N; i++){
        a[i] += a[i-1];
    }
    for(int i = 1; i < N; i++){
        has[i] = has[i-1];
        if(a[i] >= k) has[i]++;
    }
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << has[r] - has[l-1] << "\n";
    }
    return 0;
}