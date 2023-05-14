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
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++) cin >> grid[i];
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j] == '*'){
                    cnt++;
                    grid[i][j] = '.';
                }
                else if(grid[i][j] == 'o'){
                    for(int k = i - 1; cnt; k--, cnt--){
                        grid[k][j] = '*';
                    }
                }
            }
            for(int k = n - 1; cnt; k--, cnt--){
                grid[k][j] = '*';
            }
        }
        for(int i = 0; i < n; i++) cout << grid[i] << "\n";
        cout << "\n";
    }
    return 0;
}