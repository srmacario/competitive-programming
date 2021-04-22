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
const int N = 1e3+5;

int a[N], ans[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n, c;
        cin >> n >> c;
        if(c < n-1 or c > ((n+2)*(n-1))/2){
            cout << "Case #" << k+1 << ": IMPOSSIBLE\n";
            continue;
        }
        for(int i = 1; i <= n-1; i++) c--, a[i] = 1, ans[i] = i;
        ans[n] = n, a[n] = 0;
        for(int i = 1; i <= n-1; i++){
            if(c > (n - i + 1) - a[i]) c -= (n - i + 1) - a[i], a[i] = (n - i + 1); 
            else{
                a[i] += c;
                c = 0;
                break;
            }
        }
        for(int i = n; i >= 1; i--){
            reverse(ans + i, ans + i + a[i]);
        }
        cout << "Case #" << k+1 << ": ";
        for(int i = 1; i <= n; i++) cout << ans[i] << ((i == n) ? "\n" : " ");
    }
    return 0;
}