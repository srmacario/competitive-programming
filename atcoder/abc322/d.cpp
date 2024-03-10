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

string s_grid[3][4];
int grid[3][4][4], ans[100][100];

bool fill(int k){
    // db(k);
    if(k == 3){
        for(int i = 0; i < 17; i++){
            for(int j = 0; j < 17; j++){
                bool ok2 = true;
                for(int ii = i; ii < i + 4; ii++){
                    for(int jj = j; jj < j + 4; jj++){
                        if(ans[i + ii][i + jj] != 1) ok2 = false;
                    }
                }
                if(ok2) return true;
            }
        }
        return false;
    }
    bool ok = false;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            //rotate 1
            int enter = 1;
            for(int ii = 0; ii < 4; ii++){
                for(int jj = 0; jj < 4; jj++){
                    ans[i + ii][j + jj] += grid[k][ii][jj];
                    if(ans[i + ii][j + jj] > 1) enter = 0;
                }
            }
            if(enter) ok = fill(k + 1);
            if(ok) return true;
            enter = 1;
            for(int ii = 0; ii < 4; ii++){
                for(int jj = 0; jj < 4; jj++){
                    ans[i + ii][j + jj] -= grid[k][ii][jj];
                }
            }
            //rotate 2
            for(int ii = 0; ii < 4; ii++){
                for(int jj = 3; jj >= 0; jj--){
                    ans[i + ii][j + jj] += grid[k][ii][jj];
                    if(ans[i + ii][j + jj] > 1) enter = 0;
                }
            }
            if(enter) ok = fill(k + 1);
            if(ok) return true;
            enter = 1;
            for(int ii = 0; ii < 4; ii++){
                for(int jj = 3; jj >= 0; jj--){
                    ans[i + ii][j + jj] -= grid[k][ii][jj];
                }
            }
            //rotate 3
            for(int ii = 3; ii >= 0; ii--){
                for(int jj = 0; jj < 4; jj++){
                    ans[i + ii][j + jj] += grid[k][ii][jj];
                    if(ans[i + ii][j + jj] > 1) enter = 0;
                }
            }
            if(enter) ok = fill(k + 1);
            if(ok) return true;
            enter = 1;
            for(int ii = 3; ii >= 0; ii--){
                for(int jj = 0; jj < 4; jj++){
                    ans[i + ii][j + jj] -= grid[k][ii][jj];
                }
            }
            //rotate 4
            for(int ii = 3; ii >= 0; ii--){
                for(int jj = 3; jj >= 0; jj--){
                    ans[i + ii][j + jj] += grid[k][ii][jj];
                    if(ans[i + ii][j + jj] > 1) enter = 0;
                }
            }
            if(enter) ok = fill(k + 1);
            if(ok) return true;
            enter = 1;
            for(int ii = 3; ii >= 0; ii--){
                for(int jj = 3; jj >= 0; jj--){
                    ans[i + ii][j + jj] -= grid[k][ii][jj];
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int k = 0; k < 3; k++){
        for(int i = 0; i < 4; i++){
            cin >> s_grid[k][i];
            for(int j = 0; j < 4; j++){
                grid[k][i][j] = (s_grid[k][i][j] == '#');
            }
        }
    }
    cout << (fill(0) ? "YES\n" : "NO\n") << "\n";
    return 0;
}