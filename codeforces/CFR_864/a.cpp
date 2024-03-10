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
    int t;
    cin >> t;
    while(t--){
        int n, m, x[2], y[2];
        cin >> n >> m;
        int mn[2] = {4, 4};
        for(int i = 0; i < 2; i++){
            cin >> x[i] >> y[i];
            if(x[i] == 1 or x[i] == n) mn[i]--;
            if(y[i] == 1 or y[i] == m) mn[i]--;
        }
        cout << min(mn[0], mn[1]) << "\n";
    }
    return 0;
}