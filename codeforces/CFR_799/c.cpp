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
        string grid[10];
        for(int i = 0; i < 8; i++) cin >> grid[i];
        //unmark
        for(int i = 1; i < 7; i++){
            for(int j = 1; j < 7; j++){
                if(grid[i][j] == '#' and grid[i - 1][j - 1] == '#' and grid[i - 1][j + 1] == '#' and grid[i + 1][j + 1] == '#' and grid[i + 1][j - 1] == '#'){
                    cout << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
    }
    return 0;
}