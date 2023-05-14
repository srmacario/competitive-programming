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
    int t;
    cin >> t;
    while(t--){
        int n,k;
        bool ok = true;
        cin >> n >> k;
        vi h(n), low(n), up(n), pos(n);
        for(int i=0;i<n;i++) cin >> h[i];
        low[0] = up[0] = h[0];
        for(int i=1;i<n;i++){
            low[i] = max(h[i], low[i-1]-(k-1)), up[i] = min(h[i] + k-1,up[i-1] + k-1);
            if(low[i] > up[i]){
                ok = false;
                break;
            }
        }
        if(!((h[n-1] >= low[n-1]) and (h[n-1] <= up[n-1]))) ok = false; 
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}