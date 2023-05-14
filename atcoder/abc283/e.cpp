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
const int N = 1005;

int h, w;
int grid[N][N], nxt[N], prev[N], conf[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> h >> w;
    nxt[0] = 2;
    conf[1] = 0;
    for(int i = 1; i <= h; i++){
        nxt[i] = 2;
        for(int j = 1; j <= w; j++){
            cin >> grid[i][j];
        }
        grid[i][0] = grid[i][1] ^ 1;
        grid[i][w + 1] = grid[i][w] ^ 1;
        if(i == 1){
            for(int j = 1; j <= w; j++){
                grid[i - 1][j] = grid[i][j] ^ 1;
            }
        }
        if(i == h){
            for(int j = 1; j <= w; j++){
                grid[i + 1][j] = grid[i][j] ^ 1;
            }
        }
    }
    //line 1
    for(int j = 1; j <= w; j++){
        if(grid[1][j] == grid[1][j - 1] or grid[1][j] == grid[1][j + 1]) continue;
        if(grid[1][j] == grid[2][j]){
            if(nxt[2] == 1){
                cout << "-1\n";
                return 0;
            }
            nxt[2] = 0;
        }
        else{
            if(nxt[2] == 0){
                cout << "-1\n";
                return 0;
            }
            nxt[2] = 1;
        }
    }

    for(int i = 2; i < h; i++){
        if(nxt[i] == 2) conf[i] = 0;
        else conf[i] = nxt[i];
        for(int j = 1; j <= w; j++){
            if((grid[i][j] ^ conf[i]) == (grid[i][j - 1] ^ conf[i])  or (grid[i][j] ^ conf[i])  == grid[i][j + 1] ^ conf[i]  or (grid[i][j] ^ conf[i])  == (grid[i - 1][j] ^ conf[i - 1])) continue;
            if((grid[i][j] ^ conf[i])  == grid[i + 1][j]){
                if(conf[i + 1] == 1){
                    cout << "-1\n";
                    return 0;
                }
                conf[i + 1] = 0;
            }
            else{
                if(conf[i + 1] == 0){
                    cout << "-1\n";
                    return 0;
                }
                conf[i + 1] = 1;
            }
        }
    }

    if(nxt[h] == 2) conf[h] = 0;
    else conf[h] = nxt[h];
    int i = h;
    for(int j = 1; j <= w; j++){
            if((grid[i][j] ^ conf[i]) == (grid[i][j - 1] ^ conf[i])  or (grid[i][j] ^ conf[i])  == (grid[i][j + 1] ^ conf[i])) continue;
            if((grid[i][j] ^ conf[i])  == grid[i - 1][j]){
                if(conf[i - 1] == 1){
                    cout << "-1\n";
                    return 0;
                }
                conf[i - 1] = 0;
            }
            else{
                if(conf[i - 1] == 0){
                    cout << "-1\n";
                    return 0;
                }
                conf[i - 1] = 1;
            }
        }
    int ans = 0;
    for(int i = 1; i <= h; i++) ans += conf[i];
    cout << ans << "\n";
    return 0;
}