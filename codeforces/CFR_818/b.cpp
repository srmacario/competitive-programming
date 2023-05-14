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
const int N = 505;

char grid[N][N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k, r, c;
        cin >> n >> k >> r >> c;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                grid[i][j] = '.';

        int col = c;
        for(int i = r; i <= n; i++){
            for(int j = col; j <= n; j += k) grid[i][j] = 'X';
            for(int j = col; j >= 1; j -= k) grid[i][j] = 'X';
            col--;
            if(col < 1) col = n;
        }

        col = c;
        for(int i = r; i >= 1; i--){
            for(int j = col; j <= n; j += k) grid[i][j] = 'X';
            for(int j = col; j >= 1; j -= k) grid[i][j] = 'X';
            col++;
            if(col > n) col = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                cout << grid[i][j];
            cout << "\n";
        }
    }
    return 0;
}