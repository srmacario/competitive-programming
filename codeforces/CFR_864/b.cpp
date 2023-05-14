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
const int N = 1e3+5;

int grid[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int need = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> grid[i][j];
        for(int i = 0; i < n/ 2; i++){
            for(int j = 0; j < n; j++){
                need += (grid[i][j] != grid[n - 1 - i][n - 1 - j]);
            }
        }
        if(n % 2){
            for(int j = 0; j < n / 2; j++)
                need += (grid[(n + 1)/2 - 1][j] != grid[(n + 1)/2 - 1][n - 1 - j]);
        }
        if(need > k){
            cout << "NO\n";
            continue;
        }
        else{
            if(n % 2){
                cout << "YES\n";
                continue;
            }
            else{
                cout << (((k - need) % 2) ? "NO\n" : "YES\n");
                continue;
            }
        }
    }
    return 0;
}