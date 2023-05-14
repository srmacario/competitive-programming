#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define mp make_pair
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

int num_block(int i, int j){
    if(i < 3 and j < 3) return 0;
    if(i < 3 and j < 6) return 1;
    if(i < 3 and j < 9) return 2;
    if(i < 6 and j < 3) return 5;
    if(i < 6 and j < 6) return 4;
    if(i < 6 and j < 9) return 3;
    if(i < 9 and j < 3) return 6;
    if(i < 9 and j < 6) return 7;
    if(i < 9 and j < 9) return 8;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        vector<string> grid;
        int chn[2][9] = {0}, block[9];
        for(int i=0;i<9;i++){
            string s;
            cin >> s;
            grid.pb(s);
        }
        cout << "\n";
        vector <pii> trade;
        chn[0][0] = chn[1][0] = 1;
        trade.pb({0,0});
        for(int k=1;k<9;k++){
            pii from = {-1,-1};
            for(int i=0;i<9;i++){
                if(from.st != -1) break;
                for(int j=0;j<9;j++){
                    if(from.st != -1) break;
                    if((num_block(i,j) == k) and !chn[0][i] and !chn[1][j]) from = {i,j}, chn[0][i] = chn[1][j] = 1;
                }
            }
            trade.pb(from);
        }
        for(int i=0;i<9;i++){
            grid[trade[i].st][trade[i].nd] = grid[trade[i].st][trade[i].nd] + 1;
            if(grid[trade[i].st][trade[i].nd] - '0' > 9) grid[trade[i].st][trade[i].nd] -= 2;
        }
        for(int i=0;i<9;i++){
            cout << grid[i];
            cout << "\n";
        }
    }
    return 0;
}