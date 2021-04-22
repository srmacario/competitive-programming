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
const int N = 1e5+5, M = 505;

int n, m, grid[M][M];

void solve(){
    for(int j = 2 - (m%3 == 1); j <= m; j+=3){
        for(int i = 1; i <= n; i++){
            grid[i][j] = 1;
        }
        if(!grid[2][j+1] and !grid[2][j+2]) grid[1][j+1] = grid[1][j+2] = 1;
        else grid[2][j+1] = grid[2][j+2] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j]) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }        
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            for(int j = 1; j <= m; j++){
                if(s[j-1] == 'X') grid[i][j] = 1;
                else grid[i][j] = 0;
            }
        }
        if(n == 1){
            for(int j = 1; j <= m; j++){
                cout << "X";
            }   
            cout << endl;
            continue;
        }
        solve();
        for(int i = 0; i <= n+1; i++)
            for(int j = 0; j <= m+1; j++) grid[i][j] = 0;
    }
    return 0;
}