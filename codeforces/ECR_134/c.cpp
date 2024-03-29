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
const int N = 2e5+5;

int a[N], b[N], n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        //min
        for(int i = 0; i < n; i++){
            cout << b[(lower_bound(b, b + n, a[i]) - b)] - a[i] << " ";
        }
        cout << "\n";
        //max
        int j = 0;
        for(int i = 0; i < n; i++){
            if(j < i) j = i;
            while(j + 1 < n and b[j] >= a[j + 1]) j++;
            cout << b[j] - a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}